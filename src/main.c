int main(int argc, char* argv[]) 
{
	Init_SDL();

	SDL_Event e;
    i32 running = 1;
    while (running) 
	{
        while (SDL_PollEvent(&e)) 
		{
            if (e.type == SDL_QUIT) 
			{
                running = 0;
            }
        }
    }

	Exit();
}