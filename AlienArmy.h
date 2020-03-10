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
	void render();
protected:

	bool is_alive;
};

