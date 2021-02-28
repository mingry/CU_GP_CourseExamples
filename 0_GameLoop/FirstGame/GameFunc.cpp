#include "GameFunc.h"
#include <iostream>
#include <windows.h>

extern bool g_flag_running;

int g_input;
std::string g_output; // 캐릭터

// 캐릭터의 위치
int g_pos_x;
int g_pos_y;

// 흘러간 시간 계산
double g_elapsed_time_ms;


/////////////////////////////////////////////////////////////
// InitGame() 
// 프로그램이 시작될 때 최초에 한 번 호출되는 함수.
// 이 함수에서 게임에 필요한 자원(이미지, 사운드 등)을 로딩하고, 상태 변수들을 초기화 해야한다.
void InitGame()
{
	g_flag_running = true;
	g_input = 0;
	g_output = "-__-";

	g_pos_x = 0;
	g_pos_y = 10;
	g_elapsed_time_ms = 0;

	// Clear the console screen.
	// 표준출력 화면을 깨끗히 지운다.
	system("cls");
}






/////////////////////////////////////////////////////////////
// Update() 
// 게임의 내용을 갱신하는 함수.
// 게임에 일어나는 변화들은 모두 이 곳에서 구현한다.
// 실제 게임의 룰을 구현해야하는 곳.
// main 함수의 while loop에 의해서 무한히 반복 호출된다.
void Update()
{
	if (g_input == 1) {
		g_output = "^__^\n";
	}
	else if (g_input == 2) {
		g_output = "0__0\n";
	}
	else if (g_input == 3) {
		g_output = "T__T\n";
	}
	else {
		g_output = "-__-\n";
	}
	
	// 캐릭터의 위치가 자동으로 1칸씩 이동하게 한다.
	g_pos_x++;

	// 캐릭터의 위치가 오른쪽 경계에 닿으면 다시 왼쪽 시작 부분으로 보낸다.  
	if ( g_pos_x >= 27 ) g_pos_x=0;

	// Elapsed Time
	// 게임 시작부터 현재까지 흘러간 시간을 계산.
	// 0.03초를 더한다. main 함수에 SDL_Delay(30) 부분을 주목하자.
	g_elapsed_time_ms += 30;
}




/////////////////////////////////////////////////////////////
// Render() 
// 그림을 그리는 함수.
// main 함수의 while loop에 의해서 무한히 반복 호출된다.
void Render()
{
	//// 1. 배경 그리기.
	// 1.1. 커서를 콘솔 화면의 왼쪽 위 모서리 부분으로 옮긴다. 좌표(0, 0)
	// <windows.h>에서 제공하는 함수를 사용한다.
	COORD cur;
	cur.X = 0;
	cur.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

	// 1.2. 배경 부분을 '.'으로 채운다.
	for ( int i=0; i<20; i++ )
	{
		for ( int j=0; j<30; j++ )
		{
			std::cout << ".";
		}
		std::cout << std::endl;
	}

	// 1.3. 배경 아래에 시간을 표시한다,
	std::cout << "Elapsed Time: " << g_elapsed_time_ms / 1000.0f << std::endl;


	//// 2. 캐릭터 그리기.
	// 2.1. 커서를 캐릭터가 그려질 위치로 옮긴다. 
	cur.X = g_pos_x;
	cur.Y = g_pos_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

	// 2.2. 캐릭터 표정을 그린다.
	std::cout << g_output;
}



/////////////////////////////////////////////////////////////
// HandleEvents() 
// 이벤트를 처리하는 함수.
// main 함수의 while loop에 의해서 무한히 반복 호출된다.
void HandleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_KEYDOWN:
			if ( event.key.keysym.sym == SDLK_LEFT )
			{
				g_input = 1;
			}
			else if ( event.key.keysym.sym == SDLK_RIGHT )
			{
				g_input = 2;
			}
			else if (event.key.keysym.sym == SDLK_SPACE) {
				g_input = 3;
			}
			break;

		case SDL_KEYUP:
			g_input = 0;
			break;

		case SDL_MOUSEBUTTONDOWN:
		
			// If the mouse left button is pressed. 
			if ( event.button.button == SDL_BUTTON_LEFT ) {
				g_input = 1;
			}
			break;

		default:
			break;
		}
	}
}




/////////////////////////////////////////////////////////////
// ClearGame() 
// 프로그램이 끝날 때 한 번 호출되는 함수.
// 이 함수에서 사용된 자원(이미지, 사운드 등)과 메모리 등을 해제해야한다.
void ClearGame()
{
}

