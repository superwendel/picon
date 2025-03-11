typedef struct 
{
    char *buffer;
    size_t size;
    size_t offset;
} Arena;

void Arena_Init(Arena *arena, size_t size) 
{
    arena->buffer = (char *)SDL_malloc(size);
    arena->size = size;
    arena->offset = 0;
}

void *Arena_Alloc(Arena *arena, size_t size) 
{
    if (arena->offset + size > arena->size) 
	{
        SDL_Log("Arena out of space\n");
        return NULL;
    }

    void *ptr = (char *)arena->buffer + arena->offset;
    arena->offset += size;
    return ptr;
}

void Arena_Reset(Arena *arena) {
    arena->offset = 0;
}

void Arena_Free(Arena *arena) {
    free(arena->buffer);
    arena->buffer = NULL;
    arena->size = 0;
    arena->offset = 0;
}