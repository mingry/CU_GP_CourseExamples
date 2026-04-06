#include "StopwatchGame_GameFunc.h"

MIX_Audio *wave1_;
MIX_Audio *music1_;
MIX_Track *wave1_track_;
MIX_Track *music1_track_;


TTF_Font *game_font_;
SDL_Texture *text_good_;
SDL_Texture *text_bad_;
SDL_Texture *text_time_;
SDL_FRect text_good_rect_;
SDL_FRect text_bad_rect_;
SDL_FRect text_time_rect_;
SDL_FRect text_time_out_rect_;

int time_ms_;
bool started_;
int result_;

void InitGame()
{
	g_flag_running = true;

	game_font_ = TTF_OpenFont("../../Resources/Chlorinp.ttf", 50);
	// 'good'
	{
	
		SDL_Color green = { 0, 255, 0, 255 };
		SDL_Surface *tmp_surface = TTF_RenderText_Blended(game_font_, "Good", 0, green);
	
		text_good_rect_.x = 0;
		text_good_rect_.y = 0;
		text_good_rect_.w = (float)tmp_surface->w;
		text_good_rect_.h = (float)tmp_surface->h;

		text_good_ = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		
		SDL_DestroySurface(tmp_surface);
	}

	// 'bad'
	{
	
		SDL_Color red = { 255, 0, 0, 255 };
		SDL_Surface *tmp_surface = TTF_RenderText_Blended(game_font_, "Bad", 0, red);
	
		text_bad_rect_.x = 0;
		text_bad_rect_.y = 0;
		text_bad_rect_.w = (float)tmp_surface->w;
		text_bad_rect_.h = (float)tmp_surface->h;

		text_bad_ = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
		
		SDL_DestroySurface(tmp_surface);
	}
	


	// Load the wave and mp3 files 
	wave1_ = MIX_LoadAudio(g_mixer, "../../Resources/ray_gun-Mike_Koenig-1169060422.wav", false);
	if ( wave1_ == NULL ) 
	{
		std::cout << "Couldn't load the wav: " << SDL_GetError() << std::endl;
	}

	music1_ = MIX_LoadAudio(g_mixer, "../../Resources/Kalimba.mp3", false);
	if(!music1_)
	{
		std::cout << "Couldn't load the mp3: " << SDL_GetError() << std::endl;
	}

	wave1_track_ = MIX_CreateTrack(g_mixer);
	music1_track_ = MIX_CreateTrack(g_mixer);

	MIX_SetTrackAudio(wave1_track_, wave1_);
	MIX_SetTrackAudio(music1_track_, music1_);

	MIX_PlayTrack(music1_track_, 0);
	MIX_SetTrackLoops(music1_track_, -1);	// 음악이 계속 반복해서 나오도록 한다.

	started_ = false;
	time_ms_ = 0;
	result_ = 0;

	text_time_ = 0;

}




//////////////////////////////////////////////////////////////////////////
// 시간을 문자 Texture로 만드는 함수.
void UpdateTimeTexture(int ms)
{
	if ( text_time_ != 0 )
	{
		SDL_DestroyTexture(text_time_);		// !!!중요!!!  이미 생성되어있는 texture 가 있으면 반드시 메모리에서 지워야한다. !!!
		text_time_ = 0;
	}

	SDL_Color black = { 0, 0, 0, 255 };
	std::string str = std::to_string(ms);
	SDL_Surface *tmp_surface = TTF_RenderText_Blended(game_font_, str.c_str(), 0, black);
	
	text_time_rect_.x = 0;
	text_time_rect_.y = 0;
	text_time_rect_.w = (float)tmp_surface->w;
	text_time_rect_.h = (float)tmp_surface->h;

	text_time_ = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
	
	SDL_DestroySurface(tmp_surface);
}

void Update()
{
	static Uint64 last_ticks = SDL_GetTicks(); // !중요! static 으로 선언한 이유 확일 할 것.
	Uint64 current_ticks = SDL_GetTicks();
	
	
	if ( started_ )
	{
		time_ms_ += (int)(current_ticks - last_ticks);
		UpdateTimeTexture(time_ms_);	// 업데이트 된 시간(time_ms_)을 문자로 변환한 후 texture로 만든다.
	}

	last_ticks = current_ticks;

}

void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	
	int win_w, win_h;
	SDL_GetWindowSize(g_window, &win_w, &win_h);	// 아래의 출력 내용을 화면 가운데 위치 시키기 위해 현재 window의 크기를 받아서 사용하고 있음을 확인하자.

	if ( result_ == 1 )
	{
		SDL_FRect r;
		r.x = (float)win_w/2 - text_good_rect_.w/2;
		r.y = 100;
		r.w = text_good_rect_.w;
		r.h = text_good_rect_.h;
		SDL_RenderTexture(g_renderer, text_good_, 0, &r);
	}
	else if ( result_ == -1 )
	{
		SDL_FRect r;
		r.x = (float)win_w/2 - text_bad_rect_.w/2;
		r.y = 100;
		r.w = text_bad_rect_.w;
		r.h = text_bad_rect_.h;
		SDL_RenderTexture(g_renderer, text_bad_, 0, &r);
	}

	{
		
		SDL_FRect r;
		r.x = (float)win_w/2 - text_time_rect_.w/2;
		r.y = 200;
		r.w = text_time_rect_.w;
		r.h = text_time_rect_.h;
		SDL_RenderTexture(g_renderer, text_time_, 0, &r);
	}
	
	
	SDL_RenderPresent(g_renderer); // draw to the screen

}



void HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			g_flag_running = false;
			break;

		case SDL_EVENT_KEY_DOWN:
			if ( event.key.key == SDLK_ESCAPE )	// ESC 키가 눌러졌을 때 프로그램이 끝나게 한다.
				g_flag_running = false;

			break;


		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			

			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				if ( started_ )
				{
					started_ = false;
					if ( 950 <= time_ms_ && time_ms_ <= 1050 )
					{
						MIX_PlayTrack(wave1_track_, 0);
						result_ = 1;
					}
					else
					{
						result_ = -1;
					}

				}
				else
				{
					result_ = 0;
					started_ = true;
					time_ms_ = 0;
				}
					
				
			}
			break;

		default:
			break;
		}
	}
}



void ClearGame()
{
	if (wave1_track_) MIX_DestroyTrack(wave1_track_);
	if (music1_track_) MIX_DestroyTrack(music1_track_);
	if ( wave1_ ) MIX_DestroyAudio(wave1_);
	if ( music1_ ) MIX_DestroyAudio(music1_);
	TTF_CloseFont(game_font_);
}

