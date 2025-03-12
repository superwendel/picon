extern SDL_Renderer* renderer;
extern SDL_Window* window;

void Exit(void);

PINLINE void Init_SDL()
{
	//TODO(wendel): config or pass in command line?
	i32 rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED, SDL_RENDERER_PRESENTVSYNC;
	windowFlags = 0;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0); //0=nearest pixel sampling

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) 
	{
        printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
		Exit();
    }

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		printf("Couldn't init SDL Mixer\n");
		Exit();
	}

	Mix_AllocateChannels(MAX_SND_CHANNELS);

    window = SDL_CreateWindow("picon",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH * 4, WINDOW_HEIGHT * 4,
                              windowFlags);

    if (!window) 
	{
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		Exit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
	{
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        Exit();
    }

	SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
	// KeyDown scale of the renderer to 3x/4x/5x
	//TODO(wendel) probably configure this
	SDL_RenderSetScale(renderer, 4.0f, 4.0f);

	IMG_Init(IMG_INIT_PNG);

	if (TTF_Init() < 0)
	{
		printf("Couldn't init SDL TTF: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_ShowCursor(0);
}

void Exit()
{
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
	exit(0);
}