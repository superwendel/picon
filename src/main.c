int main(int argc, char* argv[]) 
{
	Init_SDL();

    while (1) 
	{
		u32 frameStart = SDL_GetTicks();

		Input_Poll();
		//Update
		//Render

        u32 frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < FRAME_TIME_MS) 
		{
            SDL_Delay(FRAME_TIME_MS - frameTime);
        }
    }

	Exit();
	return 0;
}