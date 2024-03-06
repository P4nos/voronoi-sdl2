#include "main.h"
#include "common.h"
#include "draw.h"
#include "init.h"
#include "input.h"
#include "voronoi.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
App app;
Grid grid;
Seeds seeds;

int main(int argc, char *argv[]) {
  initSDL();
  atexit(cleanup);

  prepareScene();
  //  drawSquareGrid(50);
  grid = *createGrid();
  initializeGrid(&grid);

  seeds = *generateSeeds();

  drawGrid(&grid);

  partionPlane(&seeds, &grid);
  drawPlane(&grid);

  // drawPoints(&seeds);

  deleteGrid(&grid);
  presentScene();
  while (1) {

    handleInput();
    SDL_Delay(5);
  }
}
