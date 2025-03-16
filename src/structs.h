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

typedef struct {
    char *prompt;
    char *choices[4];
	char *results[4];
	i32 oxygenEffect[4];
	i32 hullEffect[4];
	i32 fuelEffect[4];
} StoryEvent;


typedef struct
{
	v2 position;
	i32 oxygen;
	i32 hull;
	i32 fuel;
	SDL_Texture *texture;
} Submarine;

typedef struct 
{
	f32 x, y;
	f32 speed;
	f32 driftX, driftY;
} TideParticle;