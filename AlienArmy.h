#pragma once
#include "Entity.h"
#include "Game.h"
#include "Alien.h"


class AlienArmy {

	int x = 0, y = 0, maxX = 720;
	float speed = 5;
	Alien aliens[24];

public:
	Alien aliens[24];
	AlienArmy() {

		positionAliens();
	}; 
	~AlienArmy();

	void positionAliens();
	void move();
	void render(SDL_Renderer* _render, SDL_Texture* frame, int* _tiempo, SDL_Rect _rc);
protected:

	bool is_alive;
};

