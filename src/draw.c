#include "common.h"

#include "draw.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdint.h>
#include <stdlib.h>
extern App app;

void prepareScene() {
  SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
  SDL_RenderClear(app.renderer);
}

void presentScene() { SDL_RenderPresent(app.renderer); }

void drawSquareGrid(int numCells) {

  SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);

  int cellWidth = SCREEN_WIDTH / numCells;
  int cellHeight = SCREEN_HEIGHT / numCells;

  int numLines = 2 * numCells - 2;
  int x1, y1, x2, y2;
  for (size_t i = 1; i <= numLines; i++) {

    if (i < numCells) {
      // create column lines
      x1 = i * cellWidth;
      y1 = 0;
      x2 = x1;
      y2 = SCREEN_HEIGHT;
      //     printf("x1: %d, y1: %d, x2: %d, y2: %d, i: %zu\n", x1, y1, x2, y2,
      //     i);
    } else {
      // create row lines
      x1 = 0;
      y1 = cellHeight * i - cellHeight * numCells + cellHeight;
      x2 = SCREEN_WIDTH;
      y2 = y1;
      //      printf("x1: %d, y1: %d, x2: %d, y2: %d, i: %zu\n", x1, y1, x2, y2,
      //      i);
    }
    SDL_RenderDrawLine(app.renderer, x1, y1, x2, y2);
  }
}

void drawGrid(Grid *grid) {
  Cell cell;
  SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);

  if (DEBUG) {
    printf("grid\n");
  }
  for (int i = 0; i < grid->size; i++) {
    cell = grid->cells[i];
    if (DEBUG) {
      printf("x: %d, y: %d, w: %d, h: %d\n", cell.x, cell.y, cell.w + cell.x,
             cell.h + cell.y);
    }
    // draw the top border of the grid
    SDL_RenderDrawLine(app.renderer, cell.x, cell.y, cell.w + cell.x, cell.y);
    // draw the right border of the grid
    SDL_RenderDrawLine(app.renderer, cell.x, cell.y, cell.x, cell.y + cell.h);
  }
}

void drawPlane(Grid *grid) {
  Cell cell;
  SDL_Rect *rect = malloc(sizeof(SDL_Rect));
  for (int i = 0; i < grid->size; i++) {
    cell = grid->cells[i];
    // set the color of the rectange
    SDL_SetRenderDrawColor(app.renderer, cell.r, cell.g, cell.b, 255);

    rect->x = cell.x;
    rect->y = cell.y;
    rect->h = cell.h;
    rect->w = cell.w;
    SDL_RenderFillRect(app.renderer, rect);
  }
}

void drawPoints(Seeds *seeds) {
  SDL_Point center;
  for (int i = 0; i < seeds->size; i++) {

    center.x = seeds->centers[i].x;
    center.y = seeds->centers[i].y;
    // printf("x: %d, y: %d\n", center.x, center.y);
    drawCicle(center, seeds->centers[i].r, seeds->centers[i].g,
              seeds->centers[i].b, RADIUS);
  }
}

void drawCicle(SDL_Point center, int r, int g, int b, int32_t radius) {
  const int32_t diameter = (radius * 2);

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
  while (x >= y) {
    //  Each of the following renders an octant of the circle
    SDL_RenderDrawPoint(app.renderer, center.x + x, center.y - y);
    SDL_RenderDrawPoint(app.renderer, center.x + x, center.y + y);
    SDL_RenderDrawPoint(app.renderer, center.x - x, center.y - y);
    SDL_RenderDrawPoint(app.renderer, center.x - x, center.y + y);
    SDL_RenderDrawPoint(app.renderer, center.x + y, center.y - x);
    SDL_RenderDrawPoint(app.renderer, center.x + y, center.y + x);
    SDL_RenderDrawPoint(app.renderer, center.x - y, center.y - x);
    SDL_RenderDrawPoint(app.renderer, center.x - y, center.y + x);

    if (error <= 0) {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0) {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
}
