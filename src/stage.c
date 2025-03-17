Submarine *submarine;
Entity *bullet;
SalvageItem *salvage;

extern Arena levelArena;
extern Arena persistentArena;

void generateSalvageObjects() 
{
    if (!salvage) return;  // Ensure salvage was allocated

    for (i32 i = 0; i < MAX_OBJECTS; i++) 
	{
        salvage[i].x = rand() % WINDOW_WIDTH;
        salvage[i].y = rand() % WINDOW_HEIGHT;
		salvage[i].description;
    }
}

void Stage_Init(void)
{
	submarine = (Submarine *)Arena_Alloc(&persistentArena, sizeof(Submarine));
	bullet = (Entity *)Arena_Alloc(&persistentArena, sizeof(Entity));
	salvage = (SalvageItem *)Arena_Alloc(&persistentArena, MAX_OBJECTS * sizeof(SalvageItem));

	if (!salvage)
	{
        printf("Failed to allocate salvage objects.\n");
        return;
    }


	generateSalvageObjects();

	if (submarine) 
	{
		submarine->position.x = 150;
		submarine->position.y = 150;
		submarine->texture = Texture_Load("gfx/SubTest.png");
        printf("Player position: (%d, %d)\n", submarine->position.x, submarine->position.y);
    } 
	else 
	{
        printf("Failed to allocate persistent memory.\n");
    }

	if(bullet)
	{
		bullet->texture = Texture_Load("gfx/playerBullet.png");
	}

}