extern SDL_Renderer* renderer;
extern SDL_Window* window;

PINLINE void Scene_Prepare(void)
{
	SDL_SetRenderDrawColor(renderer, 15, 89, 102, 255);
    SDL_RenderClear(renderer);
}

PINLINE void Scene_Present(void)
{
	SDL_RenderPresent(renderer);
}

SDL_Texture *Texture_Load(char *filename)
{
    SDL_Texture *texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    texture = IMG_LoadTexture(renderer, filename);

    return texture;
}

void Blit(SDL_Texture *texture, i32 x, i32 y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}