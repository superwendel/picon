Arena levelArena;
Arena persistentArena;

SDL_Renderer* renderer;
SDL_Window* window;
TTF_Font *font;


App app;

SDL_Color white = {255, 255, 255, 255};
SDL_Color yellow = {255, 255, 0, 255};

extern Submarine *submarine;

i32 totalEvents = 4;

StoryEvent events[] = {
    {"A strong current pulls you off course!",
	{"Fight the current", "Ride it out", "Deploy stabilizing fins", "Emergency surface"},
	{"You struggle against the current, but it drains fuel.",
	"You let the current take you, saving fuel but drifting.",
	"The stabilizers hold, but it slows your descent.",
	"You emergency surface, aborting the mission!"},
	{-5, 0, -2, -10}, {-3, 0, -1, 0}, {-10, 0, -5, 0}
    },

    {"You discover a wreck filled with supplies!",
	{"Send a drone", "Ignore it", "Dock and enter", "Fire a flare"},
	{"The drone recovers some useful supplies.",
	"You pass by, wondering what was inside.",
	"You find extra oxygen tanks, but take some hull damage.",
	"The flare lights up something moving inside..."},
	{0, 0, 5, 0}, {0, 0, 0, 0}, {5, -5, 10, -2}
    },

    {"A deep-sea predator lurks ahead!",
	{"Stay still", "Evade slowly", "Fire torpedoes", "Speed past"},
	{"The predator ignores you, vanishing into the dark.",
	"You slowly drift away, unnoticed.",
	"You fire! The creature flees, but you burn energy.",
	"You escape at high speed, but hull integrity is compromised."},
	{0, -5, 0, -10}, {0, -3, -5, -10}, {-5, 0, -10, -5}
    },

    {"Strange glowing creatures surround you.",
	{"Observe them", "Ignore them", "Turn off lights", "Try to collect a sample"},
	{"The creatures pulse in strange patterns, mesmerizing you.",
	"You ignore them, but feel like you missed something.",
	"The darkness swallows them, making them vanish.",
	"You collect a small sample—it glows faintly in the vial."},
	{5, 0, 0, -5}, {0, 0, 0, 0}, {0, 0, 0, 0}
    }
};

i32 currentEvent = 0;
i32 selectedChoice = 0;
bool displayChoices = false;
bool showResult = false;

int getRandomEvent() 
{
    return rand() % totalEvents;
}

void renderText(const char *text, int x, int y, SDL_Color color) 
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

int main(int argc, char* argv[]) 
{
	Init_SDL();

	font = TTF_OpenFont("font/Inkbit.ttf", TEXT_SIZE);

	if (!font) 
	{
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

	Arena_Init(&persistentArena, PERSISTENT_ARENA_SIZE); 
	Arena_Init(&levelArena, PERSISTENT_ARENA_SIZE);

	Stage_Init();

    while (1) 
	{
		u32 frameStart = SDL_GetTicks();

		Scene_Prepare();
		Input_Poll();

		Blit(submarine->texture, submarine->position.x, submarine->position.y);

		// Show story prompts and choices
        if (showResult) 
		{
            // Display the result text
            renderText(events[currentEvent].results[selectedChoice], 50, 50, white);
            renderText("Press any key to continue...", 50, 100, yellow);
        } else if (displayChoices) {
            renderText(events[currentEvent].prompt, 50, 50, white);
            for (int i = 0; i < 4; i++) {
                SDL_Color color = (i == selectedChoice) ? yellow : white;
                renderText(events[currentEvent].choices[i], 70, 100 + (i * 30), color);
            }
        } else {
            renderText("Press SPACE to interact", 50, 50, white);
        }

		Scene_Present();

        u32 frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < FRAME_TIME_MS) 
		{
            SDL_Delay(FRAME_TIME_MS - frameTime);
        }
    }

	Exit();
	return 0;
}