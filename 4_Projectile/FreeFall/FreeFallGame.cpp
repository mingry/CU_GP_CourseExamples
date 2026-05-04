#include <iostream>
#include <iomanip>

#include "FreeFallGame.h" 
#include "SDL3_image/SDL_image.h"
#include "G2W.h"
#include "math.h"


extern int g_current_game_phase;
extern bool g_flag_running;
extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern float g_timestep_s;

FreeFallGame::FreeFallGame()
{
	g_flag_running = true;


	// Texture
	{
		SDL_Surface* ball_surface = IMG_Load("../../Resources/ball.png");
		ball_src_rectangle_.x = 0;
		ball_src_rectangle_.y = 0;
		ball_src_rectangle_.w = ball_surface->w;
		ball_src_rectangle_.h = ball_surface->h;

		ball_texture_ = SDL_CreateTextureFromSurface(g_renderer, ball_surface);
		SDL_DestroySurface(ball_surface);
	}

	// 공의 반지름
	ball_radius_ = 0.11;

	// 최초 공의 위치
	ball_pos_[0] = 0.0;
	ball_pos_[1] = 2.0;
	
	// 최초 공의 속도
	ball_vel_[0] = 0.0;
	ball_vel_[1] = 0.0;


	mouse_win_x_ = 0;
	mouse_win_y_ = 0;

	simul_time_ = 0.0;

	start_ = false;
}



FreeFallGame::~FreeFallGame()
{
	SDL_DestroyTexture(ball_texture_);
}



void
FreeFallGame::Update()
{
	if (start_) {

		// 중력 가속도
		float g[2];
		g[0] = 0.0f;
		g[1] = -9.8f;

		simul_time_ += g_timestep_s;

		// g_timestep_s 시간이 지난 후 공의 위치 계산
		ball_pos_[0] = ball_pos_[0] + g_timestep_s * ball_vel_[0];
		ball_pos_[1] = ball_pos_[1] + g_timestep_s * ball_vel_[1];

		// 공이 떨어지는 중이라면, 바닥과 충돌하였는지 검사
		if (ball_vel_[1] < 0.f && ball_pos_[1] - ball_radius_ <= 0.0f )
		{

			// 위치 변경.
			// 현재 공이 바닥을 뚫고 내려가 있을 가능성이 크므로, 
			// 바닥에 접하는 위치로 옮긴다.
			ball_pos_[1] = 0.0f + ball_radius_;

			// 충돌 반응 계산
			// 바닥은 수평하므로 수직 방향에 대해서만 속도의 방향을 변화 시킨다.
			ball_vel_[1] = -1.0f * ball_vel_[1] * 0.7f; // 탄성 계수 0.7
		}

		// g_timestep_s 시간이 지난 후 공의 속도 계산
		ball_vel_[0] = ball_vel_[0] + g_timestep_s * g[0];
		ball_vel_[1] = ball_vel_[1] + g_timestep_s * g[1];

		std::cout << " t: " << std::fixed << std::setw(5) << std::setprecision(2) << std::right << simul_time_;
		std::cout << " v: " << ball_vel_[1];
		std::cout << " p: " << ball_pos_[1];
		std::cout << std::endl;
	}

}

void 
FreeFallGame::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	
	// Ball
	SDL_FRect dest_rect;
	dest_rect.w = 2.0f* ball_radius_ * G2W_Scale;
	dest_rect.h = 2.0f* ball_radius_ * G2W_Scale;
	dest_rect.x = G2W_X(ball_pos_[0]) - (G2W_Scale*ball_radius_);
	dest_rect.y = G2W_Y(ball_pos_[1]) - (G2W_Scale*ball_radius_);
	
	SDL_RenderTexture(g_renderer, ball_texture_, &ball_src_rectangle_, &dest_rect);

	// Ground Line
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_RenderLine(g_renderer, G2W_X(-1.5f),
		G2W_Y(0.0f),
		G2W_X(1.5f),
		G2W_Y(0.0f));

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void 
FreeFallGame::HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			g_flag_running = false;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				simul_time_ = 0.0; // reset the simulation time
				start_ = true;
				// Get the cursor's x position.
				/*mouse_win_x_ = event.button.x;
				mouse_win_y_ = event.button.y;

				
				float mouse_game_x = W2G_X(mouse_win_x_);
				float mouse_game_y = W2G_Y(mouse_win_y_);*/
				
			}
			else if (event.button.button == SDL_BUTTON_RIGHT)
			{
				start_ = false;
				ball_pos_[0] = 0.f;
				ball_pos_[1] = 2.f;
				ball_vel_[0] = 0.f;
				ball_vel_[1] = 0.f;
			}
		

		case SDL_EVENT_MOUSE_MOTION:
			{
				// Get the cursor's x position.
				//mouse_win_x_ = event.button.x;
				//mouse_win_y_ = event.button.y;
				
			}
			break;

		default:
			break;
		}
	}
}
