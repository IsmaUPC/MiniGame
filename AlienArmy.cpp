
#include "Entity.h"
#include "Game.h"
#include "Assets.h"

#include "Alien.h"
#include "AlienArmy.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

static const int SIZE = 50;
static const int distanceAliens = (WINDOW_WIDTH - SIZE) / COLUMS;
 

void AlienArmy::positionAliens() {
	int a = 0;
		for (int i = 0; i < 6; i++) {  // fila
			for (int j = 0; j < 4; j++) {  // columna

				aliens[a] = Alien(20 + ((distanceAliens + 5) * i), 20 + ((distanceAliens + 5) * j), 55, 40, 3);
				a++;
			}
		}
	
}

AlienArmy::~AlienArmy()
{
}




void AlienArmy::move() {

	x += x * speed;

	if (x > maxX) {

		for (Alien alien : aliens) {
			alien.y -= 10;
		}
		x = maxX;
		speed *= -1;

	}
	else if (x < 0) {
		for (Alien alien : aliens) {
			alien.y -= 10;
		}
		x = 0;
		speed *= -1;

	}
    for (Alien alien : aliens) {
        alien.x += speed;
        alien.Move(speed,0);

    }
}
		void AlienArmy::render(SDL_Renderer* _render, SDL_Texture* frame, int* _tiempo, SDL_Rect _rc) {
			for (Alien alien : aliens) {
				if (alien.state == alien.LIVE) {
					alien.render( _render, frame, _tiempo, _rc);

				}
			}
		}

    //void shoot(Assets assets) {
    //    if (shootTimer.check()) {
    //        if (aliens.size > 0) { //FIXME ya no hay null pointer exception
    //            int alienNum = random.nextInt(aliens.size);

    //            Alien alien = aliens.get(alienNum);

    //            shoots.add(new AlienShoot(new Vector2(alien.positionAlien)));

    //            assets.alienSound.play(soundsConfiguration.getVolumeAlienShoot());


    //            shootTimer.set(random.nextFloat() % 5 + 1);

    //        }
    //    }
    //}

     /*void removeDeadAliens() {
        Array<Alien> aliensToRemove = new Array<Alien>();
		 Alien aliensRemove[24];
        for (Alien alien : aliens) {
            if (alien.state == Alien.State.DEAD) {
                aliensToRemove.add(alien);
            }
        }

        for (Alien alien : aliensToRemove) {
            aliens.removeValue(alien, true);
        }

    }*/
/*
    public void removeShoots() {
        Array<AlienShoot> shootsToRemove = new Array<AlienShoot>();
        for (AlienShoot shoot : shoots) {
            if (shoot.state == AlienShoot.State.TO_REMOVE) {
                shootsToRemove.add(shoot);
            }
        }

        for (AlienShoot shoot : shootsToRemove) {
            shoots.removeValue(shoot, true);
        }
    }*/

