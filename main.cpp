#include "Game.h"
#include "Menu.h"

int main(int argc, char* args[])
{
	srand(time(NULL));
	Game game;
	Menu menu;
	if (!game.Init()) return -1;

	bool end = false;
	bool play = true;
	while (!end){
		
		end = menu.Update();
		menu.Draw();

		play = menu.startGame();

		while (!play){
		play = game.Update();
		game.Draw();
		}
		menu.changePlay(true);

	}

	menu.Release();
	game.Release();
	return 0;
}