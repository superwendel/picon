typedef struct
{
	i32 x;
	i32 y;
} vec2;

typedef struct
{
	SDL_Renderer *renderer;
	SDL_Window *window;
} app;

typedef struct
{
	i32 x;
	i32 y;
	SDL_Texture *texture;
} Entity;

typedef struct 
{
	f32 x, y;
	f32 speed;
	f32 driftX, driftY;
} TideParticle;