#include "Game.h"
#include "Menu.h"

int main(int argc, char* args[])
{
	srand(time(NULL));
	Game game;
	Menu menu;
	

	bool end = false;
	bool play = true;

	bool initGame = false;

	if (!menu.Init()) return -1;

	while (!end){
		
		end = menu.Update();
		menu.Draw();

		play = menu.startGame();

		while (!play){

			if (!initGame){
				menu.Release();
				if (!game.Init()) return -1;
				initGame = true;
			}


		play = game.Update();
		game.Draw();
		}
		if (initGame == true){
			game.Release();
			if (!menu.Init()) return -1;
			initGame = false;
		}
		menu.changePlay(true);

	}

	menu.Release();
	return 0;
}