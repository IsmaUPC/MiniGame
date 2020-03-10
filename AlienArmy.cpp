
#include "Entity.h"
#include "Game.h"
#include "Assets.h"

#include "Alien.h"
#include "AlienArmy.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>



void AlienArmy::positionAliens() {
	for (int i = 0; i < 5; i++) {  // fila
		for (int j = 0; j < 11; j++) {  // columna
			aliens[i] = Alien();

			//	= (j * 30 + 10, y - i * 12, 55, 40, 3);
		}
	}
}

AlienArmy::~AlienArmy()
{
}


void AlienArmy::positionAliens()
{
}

void AlienArmy::move() {
       
	x += speed;

    if (x > maxX) {

		for (Alien alien : aliens) {
		   alien.y -= 10;
		}
		x = maxX;
		speed *= -1;

		}else if (x < 0) {
		   for (Alien alien : aliens) {
		      alien.y -= 10;
		    }
		   x = 0;
		    speed *= -1;

		}
		for (Alien alien : aliens) {
		    alien.x += speed;
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

