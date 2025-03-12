Arena levelArena;
Arena persistentArena;

SDL_Renderer* renderer;
SDL_Window* window;

Entity *player;

int main(int argc, char* argv[]) 
{
	Init_SDL();

	Arena_Init(&persistentArena, PERSISTENT_ARENA_SIZE); 
	Arena_Init(&levelArena, PERSISTENT_ARENA_SIZE);

	player = (Entity *)Arena_Alloc(&persistentArena, sizeof(Entity));

    if (player) {
        player->x = 50;
        player->y = 50;
		player->texture = Texture_Load("gfx/SubTest.png");
        printf("Player position: (%d, %d)\n", player->x, player->y);
    } else {
        printf("Failed to allocate persistent memory.\n");
    }

    while (1) 
	{
		u32 frameStart = SDL_GetTicks();

		Scene_Prepare();
		Input_Poll();
		Blit(player->texture, player->x, player->y);
		Scene_Present();
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