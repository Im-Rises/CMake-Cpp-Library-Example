#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("failed to init: %s", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow(
            "Hello", 0, 0, 640, 480,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    if (window == NULL) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return -1;
    }

    SDL_bool quit = SDL_FALSE;

    while (!quit) {
        SDL_Event e;

        // we need to call SDL_PollEvent to let window rendered, otherwise
        // no window will be shown
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }
    }

    // free
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    SDL_Quit();

    return 0;
}
