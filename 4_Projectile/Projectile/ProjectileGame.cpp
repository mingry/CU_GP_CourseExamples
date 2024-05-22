#include <iostream>

#include "ProjectileGame.h" 
#include "SDL_image.h"
#include "G2W.h"
#include "math.h"

extern int g_current_game_phase;
extern bool g_flag_running;
extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern double g_timestep_s;



ProjectileGame::ProjectileGame()
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
		SDL_FreeSurface(ball_surface);
	}

	mouse_win_x_ = 0;
	mouse_win_y_ = 0;

	AddNewBall();
}



ProjectileGame::~ProjectileGame()
{
	SDL_DestroyTexture(ball_texture_);
}


void
ProjectileGame::AddNewBall()
{
	balls_.push_back( Ball(0.11f, &room_) );
}


void
ProjectileGame::Update()
{

	// Update balls
	for (Ball& b : balls_)
	{
		b.Update(g_timestep_s);
	}
}

void 
ProjectileGame::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	
	
	// Draw room_
	{
		SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);

		// Left Wall
		SDL_RenderDrawLine(g_renderer, G2W_X(room_.left_wall_x()),
										G2W_Y(0), 
										G2W_X(room_.left_wall_x()),
										G2W_Y(room_.height()) );

		
		// Right Wall
		SDL_RenderDrawLine(g_renderer, G2W_X(room_.right_wall_x()),
										G2W_Y(0), 
										G2W_X(room_.right_wall_x()),
										G2W_Y(room_.height()) );

		// Top Wall
		SDL_RenderDrawLine(g_renderer, G2W_X(room_.left_wall_x()),
										G2W_Y(room_.height()), 
										G2W_X(room_.right_wall_x()),
										G2W_Y(room_.height()) );

		// Bottom Wall
		SDL_RenderDrawLine(g_renderer, G2W_X(room_.left_wall_x()),
										G2W_Y(0), 
										G2W_X(room_.right_wall_x()),
										G2W_Y(0) );

		// Fence
		SDL_RenderDrawLine(g_renderer, G2W_X( room_.vertiacal_fence_pos_x() ), 
										G2W_Y(0), 
										G2W_X( room_.vertiacal_fence_pos_x()  ),
										G2W_Y( room_.ground_height()+room_.vertiacal_fence_height() ) );
	}


	// Draw Balls
	for ( Ball &b : balls_ )
	{

		int ball_win_x = G2W_X(b.pos_x());
		int ball_win_y = G2W_Y(b.pos_y());

		double win_radius = G2W_Scale * b.radius();

		SDL_Rect dest_rect;
		dest_rect.w = (int)(2*win_radius);
		dest_rect.h = (int)(2*win_radius);
		dest_rect.x = (int)(ball_win_x - win_radius);
		dest_rect.y = (int)(ball_win_y - win_radius);

		SDL_RenderCopy(g_renderer, ball_texture_, &ball_src_rectangle_, &dest_rect);
	}

	
	// Draw the Guide Line 
	if (balls_.size() > 0)
	{
		SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 100);
		SDL_RenderDrawLine(g_renderer, G2W_X(balls_.back().pos_x()), 
										G2W_Y(balls_.back().pos_y()),
										mouse_win_x_, 
										mouse_win_y_ );
	}


	SDL_RenderPresent(g_renderer); // draw to the screen
}



void 
ProjectileGame::HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				// Get the cursor's x position.
				mouse_win_x_ = event.button.x;
				mouse_win_y_ = event.button.y;

				
				double mouse_game_x = W2G_X(mouse_win_x_);
				double mouse_game_y = W2G_Y(mouse_win_y_);
				

				
				// Luanch
				if ( balls_.size() > 0)
				{
					// Guide Line Vector
					double guide_line_x = mouse_game_x - balls_.back().pos_x();
					double guide_line_y = mouse_game_y - balls_.back().pos_y();

					// Lauching Force
					double launcing_force_x = 8.0 * guide_line_x;
					double launcing_force_y = 8.0 * guide_line_y;

					// Launch
					balls_.back().Launch(launcing_force_x, launcing_force_y);


					// Add a new ball for the next
					AddNewBall();
				}
			}

		

		case SDL_MOUSEMOTION:
			{
				// Get the cursor's x position.
				mouse_win_x_ = event.button.x;
				mouse_win_y_ = event.button.y;

				
				
			}
			break;

		default:
			break;
		}
	}
}
