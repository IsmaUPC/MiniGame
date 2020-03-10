
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include "SDL2_mixer-2.0.4/include/SDL_mixer.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#pragma comment( lib, "SDL2_mixer-2.0.4/lib/x86/SDL2_mixer.lib")
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "Entity.h"


#define WINDOW_WIDTH	720
#define WINDOW_HEIGHT	1024

#define PLAYER_HEIGHT	82
#define PLAYER_WIDTH	104


#define MAX_KEYS		256
#define MAX_SHOTS		32

#define FILES		4
#define COLUMS		6


//const int SPRITE_SIZE = 256;

class Menu
{
public:
	Menu();
	~Menu();

	bool Init();
	void Release();

	bool Input();
	bool Update();
	bool startGame();
	void changePlay(bool _play);
	void Draw();
	SDL_Rect rc;

private:
	SDL_Window* Window;
	SDL_Renderer* Renderer;


	SDL_Texture* TexBTN_Play[2], * TexBTN_Exit[2];

	Mix_Chunk* effect1 = NULL;
	Mix_Music* music = NULL;

	Entity BackGround, BTN_menu[2];

	//VARs
	
	bool play = true;
	int opc = 1;

	enum KEY_STATE {
		KEY_IDLE,
		KEY_DOWN,
		KEY_REPEAT,
		KEY_UP
	};
	KEY_STATE keys[MAX_KEYS];
};