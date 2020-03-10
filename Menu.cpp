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

	//TEXT

	//Open the font
	TTF_Init();
	font = TTF_OpenFont("arial.ttf", fontsize);

	// Cargar nuestras imagenes despues de crear el renderer
	IMG_Init(IMG_INIT_PNG);
	TexBTN_Play[0] = SDL_CreateTextureFromSurface(Renderer, IMG_Load("BT_Play_off.png"));
	TexBTN_Play[1] = SDL_CreateTextureFromSurface(Renderer, IMG_Load("BT_Play_on.png"));
	TexBTN_Exit[0] = SDL_CreateTextureFromSurface(Renderer, IMG_Load("BT_Exit_off.png"));
	TexBTN_Exit[1] = SDL_CreateTextureFromSurface(Renderer, IMG_Load("BT_Exit_on.png"));
	
	//Initialize keys array
	for (int i = 0; i < MAX_KEYS; ++i)
		keys[i] = KEY_IDLE;


	//Init variables

	BackGround.Init(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1);


	for (int i = 0; i < 2; i++) {
		// 0 = play / 1 = exit
		BTN_menu[i].Init((WINDOW_WIDTH >> 1)- 180, (WINDOW_HEIGHT >> 2) + (i*240), 360, 120, 0);
	}


	//Music Start
	//Mix_PlayMusic(music, -1);//-1 for loop

	return true;
}

void Menu::Release(){

	for (int i = 0; i < 2; i++){
		SDL_DestroyTexture(TexBTN_Exit[i]);
		SDL_DestroyTexture(TexBTN_Play[i]);
	}
	IMG_Quit();

	//Sounds
	//Mix_FreeMusic(music);
	//Mix_FreeChunk(effect1);
	Mix_CloseAudio();

	//TEXT
	SDL_FreeSurface(message);
	SDL_DestroyTexture(texture);


	//Close the font that was used
	TTF_CloseFont(font);

	//Quit SDL_ttf
	TTF_Quit();


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
	if (keys[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		score++;
	}
	if (opc > 1){
		opc = 0;
	}
	if (opc < 0){
		opc = 1;
	}
	if (keys[SDL_SCANCODE_RETURN] == KEY_DOWN) {
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
	SDL_Rect rc;

	BackGround.GetRect(&rc.x, &rc.y, &rc.w, &rc.h);


	switch (opc) {
	case 1:
		BTN_menu[0].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
		SDL_RenderCopy(Renderer, TexBTN_Play[1], NULL, &rc);

		BTN_menu[1].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
		SDL_RenderCopy(Renderer, TexBTN_Exit[0], NULL, &rc);
		break;

	case 0:
		BTN_menu[0].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
		SDL_RenderCopy(Renderer, TexBTN_Play[0], NULL, &rc);

		BTN_menu[1].GetRect(&rc.x, &rc.y, &rc.w, &rc.h);
		SDL_RenderCopy(Renderer, TexBTN_Exit[1], NULL, &rc);
		break;
	}

	//TEXT

	
	
	message = TTF_RenderText_Solid(font,"Aqui escribimos el mensaje", textColor);
	texture = SDL_CreateTextureFromSurface(Renderer, message);

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { (WINDOW_WIDTH >> 1 )/2, (WINDOW_HEIGHT >> 1) - fontsize*2, texW, texH };
	SDL_RenderCopy(Renderer, texture, NULL, &dstrect);
	
	

	//Update screen
	SDL_RenderPresent(Renderer);

	SDL_Delay(10);	// 1000/10 = 100 fps max
}
