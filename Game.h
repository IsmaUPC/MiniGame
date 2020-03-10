#pragma once

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
#include "AlienArmy.h"




#define WINDOW_WIDTH	720
#define WINDOW_HEIGHT	1024

#define PLAYER_HEIGHT	82
#define PLAYER_WIDTH	104


#define MAX_KEYS		256
#define MAX_SHOTS		32

#define FILES		4
#define COLUMS		6


const int SPRITE_SIZE = 256;

class Game
{
public:
	Game();
	~Game();

	bool Init();
	void Release();
	
	bool Input();
	bool Update();
	void Draw();
	SDL_Rect rc;
	int tiempo = 50;
	static const int SIZE = 50;
	static const int distanceAliens = (WINDOW_WIDTH - SIZE) / COLUMS;
	static const int W_WIDTH = WINDOW_WIDTH;
private:
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	//SDL_Surface* spaceShip = IMG_Load("spaceship2.png");
	SDL_Texture* textureShip,*textureBullet, * textureBackGround[7], * textureEnemy, * textureEnemy2;
	
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;
	Mix_Chunk* effect3 = NULL;
	Mix_Chunk* effect4 = NULL;
	Mix_Music* music = NULL;
	Mix_Chunk* Disparos = { NULL };
	
	Entity Player, Shots[MAX_SHOTS], BackGround[2], Enemy[FILES][COLUMS];
	
	AlienArmy army;
	int idx_shot; 
	
	int contador = 0;
	int vel = 1;
	bool move = true;

	int buclefilter = 0;
	int score = 0;
	int r = 0, g = 0, b = 0;


	enum KEY_STATE { 
		KEY_IDLE,
		KEY_DOWN,
		KEY_REPEAT,
		KEY_UP	
	};
	KEY_STATE keys[MAX_KEYS]; 
};