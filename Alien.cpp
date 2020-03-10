#include "Entity.h"
#include "Game.h"
#include "Assets.h"


class Alien:public Entity{
//
//	enum State {
//		LIVE, DYING, DEAD
//	};
//
//	//Vector2 positionAlien;
//	float stateTime;
//	
//	State state;
//public:
//	Alien::Alien(int _x,int _y, int _w, int _h,){
//		
//		//positionAlien = new Vector2(x, y);
//		int x = _x;
//		int y = _y;
//		state = LIVE;
//		Entity(_x, _y, int w, int h, int s){
//		x = posx;
//		y = posy;
//		width = w;
//		height = h;
//		speed = s;
//		is_alive = true;
//	}
//	}
//	
//
//	 void Alien::render(SDL_Renderer* _render, SDL_Texture* frame,int* _tiempo, SDL_Rect _rc) {
//		 _tiempo--;
//		
//			
//				 if (*_tiempo > 25 && *_tiempo < 50) {
//					 GetRect(&_rc.x, &_rc.y, &_rc.w, &_rc.h);
//					 SDL_RenderCopy(_render, frame, NULL, &_rc);
//				 }
//				 else {
//					 GetRect(&_rc.x, &_rc.y, &_rc.w, &_rc.h);
//					 SDL_RenderCopy(_render, frame, NULL, &_rc);
//				 }
//
//		 if (_tiempo == 0) *_tiempo = 50;
//	}
//
//	void update(float delta, Assets assets) {
//		stateTime += delta;
//		if (state == LIVE) {
//			//frame = assets.alien.getKeyFrame(stateTime, true);
//		}
//		else if (state == DYING) {
//			///frame = assets.aliendie.getKeyFrame(stateTime, false);
//		}
//
//		if (state == DYING) {
//			//if (assets.aliendie.isAnimationFinished(stateTime)) {       Saber hacer animaciones :D
//			state = DEAD;
//			//}
//		}
//	}
//
//	void shoot() {
//
//	}
	/*
	 void kill(Ship ship) {
		state = State.DYING;
		stateTime = 0;
		switch (ship.getLives()) {

		case 3:
			ship.setScore(ship.getScore() + 100);
			break;
		case 2:
			ship.setScore(ship.getScore() + 50);
			break;
		case 1:
			ship.setScore(ship.getScore() + 25);
			break;
		case 0:
			ship.setScore(ship.getScore() + 10);
			break;
		default:
			ship.setScore(ship.getScore() + 150);
			break;
		}
	}

	 bool isAlive(){
		return state == LIVE;
	}
	*/
};