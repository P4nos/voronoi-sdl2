#include <SDL2/SDL.h>

void handleInput(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      exit(0);
      break;
    }
  }
}
