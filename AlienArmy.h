#pragma once
#include "Entity.h"
#include "Game.h"
#include "Alien.h"


class AlienArmy {
	int x = 0, y = 0, maxX = 1024;
	float speed = 0;
	Alien aliens[24];

public:
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

