#if defined(_WIN32)
#include <SDL.h>
#elif defined(__linux__)
#include <SDL2/SDL.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#endif

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("failed to init: %s", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return -1;
    }

    SDL_bool quit = SDL_FALSE;

    while (!quit)
    {
        SDL_Event e;

        // we need to call SDL_PollEvent to let window rendered, otherwise
        // no window will be shown
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = SDL_TRUE;
            }
        }
    }

    // free
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();

    return 0;
}
