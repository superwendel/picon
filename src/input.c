extern i32 selectedChoice;
extern i32 currentEvent;
extern StoryEvent events[];
extern Submarine *player;
extern Drone drone;
extern enum GameState gameState;

PINLINE void handleDroneMovement(SDL_Event *e) {
    if (!drone.active) return; // If drone isn't active, don't process movement

    if (e->type == SDL_KEYDOWN) 
	{
        switch (e->key.keysym.sym) 
		{
            case SDLK_UP:    drone.y -= drone.speed; break;
            case SDLK_DOWN:  drone.y += drone.speed; break;
            case SDLK_LEFT:  drone.x -= drone.speed; break;
            case SDLK_RIGHT: drone.x += drone.speed; break;
        }
    }
}

PINLINE void doKeyDown(SDL_KeyboardEvent *e)
{
	if (gameState == GS_CHOICE) 
	{
		if (e->keysym.sym == SDLK_DOWN) 
		{
			selectedChoice = (selectedChoice + 1) % 4;
		}
		
		else if (e->keysym.sym == SDLK_UP) 
		{
			selectedChoice = (selectedChoice - 1 + 4) % 4;
		} 
		
		else if (e->keysym.sym == SDLK_RETURN) 
		{
			submarine->oxygen += events[currentEvent].oxygenEffect[selectedChoice];
			submarine->hull += events[currentEvent].hullEffect[selectedChoice];
			submarine->fuel += events[currentEvent].fuelEffect[selectedChoice];

			gameState = GS_RESULT;
		}
	} 
	else if (gameState == GS_RESULT)
	{
		currentEvent = getRandomEvent();
		gameState = GS_DRONE;
	}
	else if (e->keysym.sym == SDLK_SPACE) 
	{
		gameState = GS_CHOICE;
	}
}

PINLINE void Input_Poll(void)
{
	SDL_Event event;
    while (SDL_PollEvent(&event)) 
	{
        switch (event.type) 
		{
            case SDL_QUIT:
				Exit();
                break;
			case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;
        }
    }
}