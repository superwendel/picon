SDL_Renderer* renderer;
SDL_Window* window;

void Exit(void);

PINLINE void Init_SDL()
{
	i32 rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

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
                              1280, 960,
                              windowFlags);

    if (!window) 
	{
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		Exit();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
	{
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        Exit();
    }

	//TODO(wendel): think there was a pixel hint/pixel scale, decide after art stryle is defined

	IMG_Init(IMG_INIT_PNG);

	if (TTF_Init() < 0)
	{
		printf("Couldn't init SDL TTF: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_ShowCursor(0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Exit()
{
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
	exit(1);
}