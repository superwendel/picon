Arena levelArena;
Arena persistentArena;

SDL_Renderer* renderer;
SDL_Window* window;

Entity *player;

App app;

int main(int argc, char* argv[]) 
{
	Init_SDL();

	Arena_Init(&persistentArena, PERSISTENT_ARENA_SIZE); 
	Arena_Init(&levelArena, PERSISTENT_ARENA_SIZE);

	player = (Entity *)Arena_Alloc(&persistentArena, sizeof(Entity));

    if (player) 
	{
		player->position.x = 50;
 			player->position.y = 50;
		player->texture = Texture_Load("gfx/SubTest.png");
        printf("Player position: (%d, %d)\n", player->position.x, player->position.y);
    } 
	else 
	{
        printf("Failed to allocate persistent memory.\n");
    }

    while (1) 
	{
		u32 frameStart = SDL_GetTicks();

		Scene_Prepare();
		Input_Poll();

		if (app.up)
        {
            player->position.y -= 4;
        }

        if (app.down)
        {
            player->position.y  += 4;
        }

        if (app.left)
        {
            player->position.x  -= 4;
        }

        if (app.right)
        {
            player->position.x += 4;
        }

		Blit(player->texture, player->position.x, player->position.y);
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