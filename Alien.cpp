#include "Entity.h"
#include "Game.h"
#include "Assets.h"



class Alien {

	enum State {
		LIVE, DYING, DEAD
	};

	//Vector2 positionAlien;
	float stateTime;
	SDL_Texture* frame;
	State state;

	Alien(int x, int y) {
		//positionAlien = new Vector2(x, y);
		state = LIVE;
	}

	// void render(SpriteBatch batch) {
	//	batch.draw(frame, positionAlien.x, positionAlien.y);
	//}

	void update(float delta, Assets assets) {
		stateTime += delta;
		if (state == LIVE) {
			//frame = assets.alien.getKeyFrame(stateTime, true);
		}
		else if (state == DYING) {
			///frame = assets.aliendie.getKeyFrame(stateTime, false);
		}

		if (state == DYING) {
			//if (assets.aliendie.isAnimationFinished(stateTime)) {       Saber hacer animaciones :D
			state = DEAD;
			//}
		}
	}

	void shoot() {

	}
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