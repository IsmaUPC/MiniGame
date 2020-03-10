#include "AlienArmy.h"
#include "Entity.h"
#include "Game.h"
#include "Assets.h"

#include "Alien.cpp"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


class AlienArmy {
//
//	int x, y, maxX;
//
//	float speed = 8;
//
//
//
//	Alien aliens[24];
//
//	AlienArmy(int WORLD_WIDTH, int WORLD_HEIGHT) {
//
//
//
//
//		int random = rand() % 10 + 1;
//
//		this->x = 0;
//		this->y = WORLD_HEIGHT - 30;
//		this->maxX = 60;
//
//		/// this->soundsConfiguration = soundsConfiguration;
//
//		for (int j = 0; j < 24; j++) {
//
//
//			aliens[j] = Alien(20 + ((Game::spacio + 5) * j), 20 + ((Game::spacio + 5) * j), 1, 1, 1);
//
//		}
//		shoots[32];
//
//
//		/* moveTimer = new Timer(0.8);
//		 shootTimer = new Timer(random.nextFloat() % 5 + 1);
//		 */
//		positionAliens();
//	}
//
//
//	void render(SDL_Renderer* _render, SDL_Texture* frame, int* tiempo) {
//		for (Alien alien : aliens) {
//			alien.render(_render, frame, tiempo, );
//		}
//
//		/* for (AlienShoot shoot : shoots) {
//			 shoot.render(batch);
//		 */
//	}
//}
//
//    void update(float delta, SDL_Texture* frame) {
//       /* moveTimer.update(delta);
//        shootTimer.update(delta);
//        soundsConfiguration.update();*/
//
//        move();
//        shoot(frame);
//
//        for (Alien alien : aliens) {
//            alien.update(delta, frame);
//        }
//
//        for (AlienShoot shoot : shoots) {
//            shoot.update(delta, frame);
//        }
//
//
//        removeDeadAliens();
//        removeShoots();
//    }
//
//
//    void positionAliens() {
//        for (int i = 0; i < 5; i++) {  // fila
//            for (int j = 0; j < 11; j++) {  // columna
//                aliens.add(new Alien(j * 30 + 10, y - i * 12));
//            }
//        }
//    }
//
//
//    void move() {
//       // if (moveTimer.check()) {
//            x += speed;
//
//            if (x > maxX) {
//                for (Alien alien : aliens) {
//                    alien.positionAlien.y -= 10;
//                }
//                x = maxX;
//                speed *= -1;
//
//
//            }
//            else if (x < 0) {
//               for (Alien alien : aliens) {
//                    alien.positionAlien.y -= 10;
//                }
//               x = 0;
//                speed *= -1;
//
//            }
//
//            for (Alien alien : aliens) {
//                alien.positionAlien.x += speed;
//
//            }
//        //}
//    }
//
//    void shoot(Assets assets) {
//        if (shootTimer.check()) {
//            if (aliens.size > 0) { //FIXME ya no hay null pointer exception
//                int alienNum = random.nextInt(aliens.size);
//
//                Alien alien = aliens.get(alienNum);
//
//                shoots.add(new AlienShoot(new Vector2(alien.positionAlien)));
//
//                assets.alienSound.play(soundsConfiguration.getVolumeAlienShoot());
//
//
//                shootTimer.set(random.nextFloat() % 5 + 1);
//
//            }
//        }
//    }
//
//     void removeDeadAliens() {
//        //Array<Alien> aliensToRemove = new Array<Alien>();
//		 Alien aliensRemove[24];
//        for (Alien alien : aliens) {
//            if (alien.state == Alien.State.DEAD) {
//                aliensToRemove.add(alien);
//            }
//        }
//
//        for (Alien alien : aliensToRemove) {
//            aliens.removeValue(alien, true);
//        }
//
//    }
//
//    public void removeShoots() {
//        Array<AlienShoot> shootsToRemove = new Array<AlienShoot>();
//        for (AlienShoot shoot : shoots) {
//            if (shoot.state == AlienShoot.State.TO_REMOVE) {
//                shootsToRemove.add(shoot);
//            }
//        }
//
//        for (AlienShoot shoot : shootsToRemove) {
//            shoots.removeValue(shoot, true);
//        }
//    }
};