#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

bool Menu::Init(){

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
	//music = Mix_LoadMUS("Soundtruck.mp3");
	//effect1 = Mix_LoadWAV("laser.wav");

	// Cargar nuestras imagenes despues de crear el renderer
	IMG_Init(IMG_INIT_PNG);

	//textureShip = SDL_CreateTextureFromSurface(Renderer, IMG_Load("spaceship2.png"));
	
	//Initialize keys array
	for (int i = 0; i < MAX_KEYS; ++i)
		keys[i] = KEY_IDLE;


	//Music Start
	//Mix_PlayMusic(music, -1);//-1 for loop

	return true;
}

void Menu::Release(){

	//SDL_DestroyTexture(textureEnemy2);
	IMG_Quit();

	//Sounds
	//Mix_FreeMusic(music);
	//Mix_FreeChunk(effect1);
	Mix_CloseAudio();

	//Clean up all SDL initialized subsystems
	SDL_Quit();
}

bool Menu::Input()
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

bool Menu::Update(){

	//Read Input
	if (!Input())	return true;
	//int x, y, w, h;
	//Process Input
	//int fx = 0, fy = 0;
	if ((keys[SDL_SCANCODE_UP] == KEY_DOWN || keys[SDL_SCANCODE_W] == KEY_DOWN) )	opc++;
	if ((keys[SDL_SCANCODE_DOWN] == KEY_DOWN || keys[SDL_SCANCODE_S] == KEY_DOWN) ) opc--;

	if (opc > 1){
		opc = 0;
	}
	if (opc < 0){
		opc = 1;
	}
	if (keys[SDL_SCANCODE_SPACE] == KEY_DOWN) {
		switch (opc) {
		case 1:
			play = false;
			break;

		case 0:
			return true;
			break;
		}
	}

	return false;
}

bool Menu::startGame(){

	return play;
}

void Menu::changePlay(bool _play){

	if (play == false){
		opc = 1;
	}
	play = _play;


}




void Menu::Draw(){

	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	//Clear rendering target                 
	SDL_RenderClear(Renderer);

	//Update screen
	SDL_RenderPresent(Renderer);

	SDL_Delay(10);	// 1000/10 = 100 fps max
}
