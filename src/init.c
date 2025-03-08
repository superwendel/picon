SDL_Renderer* renderer;
SDL_Window* window;

PINLINE void Init_SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
        printf("SDL could not ! SDL_Error: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow("picon",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1280, 960,
                              SDL_WINDOW_SHOWN);

    if (!window) 
	{
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
	{
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

PINLINE void Exit()
{
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

