#pragma once
#include "Entity.h"
class Alien :public Entity {

	enum State {
		LIVE, DYING, DEAD
	};


	float stateTime;

	State state;
	void update(float delta, SDL_Texture* frame);
	void render(SDL_Renderer* _render, SDL_Texture* frame, int* _tiempo, SDL_Rect _rc);

public:
	Alien() {}
	Alien(int _x, int _y, int _w, int _h, int _s) {
		x = _x;
		y = _y;
		width = _w;
		height = _h;
		speed = _s;
		is_alive = true;
		state = LIVE;

	}
	~Alien() {}


};