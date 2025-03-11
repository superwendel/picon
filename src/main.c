extern SDL_Renderer* renderer;
extern SDL_Window* window;

Arena persistentArena;
Arena levelArena;

int main(int argc, char* argv[]) 
{
	Init_SDL();
//	Init_Game();

	Arena_Init(&persistentArena, PERSISTENT_ARENA_SIZE); 
	Arena_Init(&levelArena, PERSISTENT_ARENA_SIZE);

	vec2 *playerPos = (vec2 *)Arena_Alloc(&persistentArena, sizeof(vec2));

    if (playerPos) {
        playerPos->x = 100;
        playerPos->y = 150;
        printf("Player position: (%d, %d)\n", playerPos->x, playerPos->y);
    } else {
        printf("Failed to allocate persistent memory.\n");
    }

	vec2 *player2Pos = (vec2 *)Arena_Alloc(&persistentArena, sizeof(vec2));

    if (player2Pos) {
        player2Pos->x = 200;
        player2Pos->y = 350;
        printf("Player position: (%d, %d)\n", player2Pos->x, player2Pos->y);
    } else {
        printf("Failed to allocate persistent memory.\n");
    }

    i32 *levelData = (i32 *)Arena_Alloc(&levelArena, 100 * sizeof(i32));
    if (levelData) {
        for (i32 i = 0; i < 100; i++) {
            levelData[i] = i; // Just an example initialization.
        }
        printf("Level data allocated and initialized.\n");
    } else {
        printf("Failed to allocate level memory.\n");
    }

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