typedef struct
{
	i32 x;
	i32 y;
} v2;

typedef struct
{
	i32 up;
	i32 down;
	i32 left;
	i32 right;
	i32 fire;
} App;

typedef struct
{ 
	v2 position;
	v2 delta;
	i32 health;
	SDL_Texture *texture;
} Entity;

typedef struct 
{
	f32 x, y;
	f32 speed;
	f32 driftX, driftY;
} TideParticle;