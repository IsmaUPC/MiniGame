#include "Game.h"
#include <math.h>

Game::Game() {}
Game::~Game(){}

bool Game::Init()
{


	//Initialize SDL with all subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	//Create our window: title, x, y, w, h, flags
	Window = SDL_CreateWindow("Spaceship: arrow keys + space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window == NULL)
	{
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return false;
	}
	//Create a 2D rendering context for a window: window, device index, flags
	Renderer = SDL_CreateRenderer(Window, -1, 0);
	if (Renderer == NULL)
	{
		SDL_Log("Unable to create rendering context: %s", SDL_GetError());
		return false;
	}

	//AUDIO
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	music = Mix_LoadMUS("musica.mp3");
	effect1 = Mix_LoadWAV("laser.wav");

	

	// Cargar nuestras imagenes despues de crear el renderer
	IMG_Init(IMG_INIT_PNG);
	textureShip = SDL_CreateTextureFromSurface(Renderer, IMG_Load("spaceship2.png"));
	textureBullet = SDL_CreateTextureFromSurface(Renderer, IMG_Load("shot.png"));
	textureBackGround = SDL_CreateTextureFromSurface(Renderer, IMG_Load("space.png"));

	//Initialize keys array
	for (int i = 0; i < MAX_KEYS; ++i)
		keys[i] = KEY_IDLE;

	//Init variables
	Player.Init(20, WINDOW_HEIGHT - 200, 104, 82, 7);	
	idx_shot = 0;
	
	BackGround[0].Init(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);
	BackGround[1].Init(0, -1*WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, 1);


	int Tama�o = 70;
	int spacio = (WINDOW_WIDTH -Tama�o) / COLUMS;
	

	/*for (int j = 0; j < FILES; j++){
		for (int i = 0; i < COLUMS; i++){

			Enemy[j][i].Init(20 +((spacio+5) * i), 20 + ((spacio + 5) * j), Tama�o, Tama�o, 3);
		}
	}*/


	//Music Start
	Mix_PlayMusic(music, -1);//-1 for loop

	return true;
}
void Game::Release()
{
	SDL_DestroyTexture(textureShip);
	SDL_DestroyTexture(textureBullet);
	SDL_DestroyTexture(textureBackGround);
	IMG_Quit();

	//Sounds
	Mix_FreeMusic(music);
	Mix_FreeChunk(effect1);

	Mix_CloseAudio();

	//Clean up all SDL initialized subsystems
	SDL_Quit();
}
bool Game::Input()
{

	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)	return false;
	}

	SDL_PumpEvents();
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keyboard[i])
			keys[i] = (keys[i] == KEY_IDLE) ? KEY_DOWN : KEY_REPEAT;
		else
			keys[i] = (keys[i] == KEY_REPEAT || keys[i] == KEY_DOWN) ? KEY_UP : KEY_IDLE;
	}

	return true;
}
bool Game::Update()
{



	//Read Input
	if (!Input())	return true; 
		int x, y, w, h;
		Player.GetRect(&x, &y, &w, &h);
	//Process Input
	int fx = 0, fy = 0;
	if (keys[SDL_SCANCODE_ESCAPE] == KEY_DOWN)	return true;
	//if ((keys[SDL_SCANCODE_UP] == KEY_REPEAT || keys[SDL_SCANCODE_W] == KEY_REPEAT) && y > 0)	fy = -1;
	///if ((keys[SDL_SCANCODE_DOWN] == KEY_REPEAT || keys[SDL_SCANCODE_S] == KEY_REPEAT) && y < (WINDOW_HEIGHT-PLAYER_HEIGHT))	fy = 1;
	if ((keys[SDL_SCANCODE_LEFT] == KEY_REPEAT || keys[SDL_SCANCODE_A] == KEY_REPEAT) && x >0 )	fx = -1 ;
	if ((keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT || keys[SDL_SCANCODE_D] == KEY_REPEAT) && x < (WINDOW_WIDTH- PLAYER_WIDTH))	fx = 1;
	if (keys[SDL_SCANCODE_SPACE] == KEY_DOWN )
	{
		
		
		Shots[idx_shot].Init(x + ((w / 2) - (w/3)), y - 5, 20, 56, 12);
		idx_shot++;
		idx_shot %= MAX_SHOTS;
		Shots[idx_shot].Init(x +(((w / 2) + (w/3))-20), y -5 , 20, 56, 12);
		idx_shot++;
		idx_shot %= MAX_SHOTS;

		//sound effect
		Mix_PlayChannel(-1, effect1, 0);
	}

	//Logic
	//Player update
	Player.Move(fx, fy);



	for (int i = 0; i <= 1; ++i){
		if (BackGround[i].GetY() >WINDOW_HEIGHT ) {

			BackGround[i].SetY(-WINDOW_HEIGHT);

		}
		BackGround[i].Move(0, 1);

	}



	//Shots update
	for (int i = 0; i < MAX_SHOTS; ++i)
	{
		if (Shots[i].IsAlive())
		{
			Shots[i].Move(0, -1);
			if (Shots[i].GetX() > WINDOW_WIDTH)	Shots[i].ShutDown();
		}
	}
		
	return false;
}
void Game::Draw()
{

	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	//Clear rendering target                 
	SDL_RenderClear(Renderer);
	SDL_Rect rc;
	for (int i = 0; i <= 1; ++i)	{
		//SDL_SetRenderDrawColor(Renderer, 0, 192, 0, 255);
		BackGround[i].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
		//El primer null es la parte de textura que coges, el segundo parametro es para el rectangulo de la pantalla
		SDL_RenderCopy(Renderer, textureBackGround, NULL, &rc);

	}



	//Draw player

	//SDL_SetRenderDrawColor(Renderer, 0, 192, 0, 255);
	Player.GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
	//El primer null es la parte de textura que coges, el segundo parametro es para el rectangulo de la pantalla
	SDL_RenderCopy(Renderer, textureShip , NULL,&rc);

	//SDL_RenderFillRect(Renderer, &rc);
	

	//Draw Enemy
	/*
	SDL_SetRenderDrawColor(Renderer, 0, 192, 0, 255);
	for (int j = 0; j < FILES; j++) {
		for (int i = 0; i < COLUMS; i++) {

			Enemy[j][i].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
			SDL_RenderFillRect(Renderer, &rc);
		}
	}*/



	//Draw shots
	SDL_SetRenderDrawColor(Renderer, 192, 0, 0, 255);
	for (int i = 0; i < MAX_SHOTS; ++i)
	{
		if (Shots[i].IsAlive())
		{
			Shots[i].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
			SDL_RenderCopy(Renderer, textureBullet, NULL, &rc);
			//SDL_RenderFillRect(Renderer, &rc);
		}
	}
	//Update screen
	SDL_RenderPresent(Renderer);

	SDL_Delay(10);	// 1000/10 = 100 fps max
}