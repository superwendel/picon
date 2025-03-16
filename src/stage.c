Submarine *submarine;
Entity *bullet;

extern Arena levelArena;
extern Arena persistentArena;

void Stage_Init(void)
{
	submarine = (Submarine *)Arena_Alloc(&persistentArena, sizeof(Submarine));
	bullet = (Entity *)Arena_Alloc(&persistentArena, sizeof(Entity));

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