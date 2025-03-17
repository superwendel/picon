enum GameState { 
	GS_DRONE,
	GS_EVENT,
	GS_CHOICE,
	GS_RESULT,
	GS_CITY
};

typedef struct {
	i32 x;
	i32 y;
} v2;

typedef struct { 
	v2 position;
	v2 delta;
	i32 health;
	SDL_Texture *texture;
} Entity;

typedef struct {
	i32 x, y;
    const char* description;
    b32 upgrade;
	b32 collected;
} SalvageItem;

typedef struct {
    char *prompt;
    char *choices[4];
	char *results[4];
	i32 oxygenEffect[4];
	i32 hullEffect[4];
	i32 fuelEffect[4];
} StoryEvent;

typedef struct {
    i32 reinforcedHull;
    i32 oxygenEfficiency;
    i32 fuelEfficiency;
    i32 moraleBoost;
    i32 sonarRange;
    i32 thermalShielding;
    i32 extraFood;
} Upgrades;

typedef struct {
    i32 x, y;         
    i32 speed;        
    i32 active;       
} Drone;

typedef struct {
	v2 position;
	i32 oxygen;
	i32 hull;
	i32 fuel;
	i32 power;
	i32 temp;
	i32 pressure;
	i32 sonar;
	i32 morale;
	i32 food;
	i32 sanity;
	i32 signal;
	i32 biohazard;
	i32 navigation;
	SDL_Texture *texture;
	Upgrades upgrades;
} Submarine;

typedef struct {
	f32 x, y;
	f32 speed;
	f32 driftX, driftY;
} TideParticle;