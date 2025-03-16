extern App app;
extern i32 selectedChoice;
extern i32 currentEvent;
extern bool displayChoices;
extern bool showResult;
extern StoryEvent events[];
extern Submarine *player;

void doKeyUp(SDL_KeyboardEvent *e)
{
    if (e->repeat == 0)
    {
        if (e->keysym.scancode == SDL_SCANCODE_UP)
        {
            app.up = 0;
        }

        if (e->keysym.scancode == SDL_SCANCODE_DOWN)
        {
            app.down = 0;
        }

        if (e->keysym.scancode == SDL_SCANCODE_LEFT)
        {
            app.left = 0;
        }

        if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            app.right = 0;
        }

		if (e->keysym.scancode == SDL_SCANCODE_LCTRL)
        {
            app.fire = 0;
        }
    }
}

void doKeyDown(SDL_KeyboardEvent *e)
{
	if (displayChoices) 
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

			// Show result message
			showResult = true;
			displayChoices = false;
		}
	} 
	else if (showResult)
	{
		// After displaying result, move to the next event
		currentEvent = getRandomEvent();
		showResult = false; 
	}
	else if (e->keysym.sym == SDLK_SPACE) 
	{
		displayChoices = true;
	}
}

void Input_Poll(void)
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

            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;

        }
    }
}