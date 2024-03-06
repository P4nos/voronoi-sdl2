#include <SDL2/SDL.h>
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 420
/*
 * The radius of the center of the cell
 */
#define RADIUS 2
/*
 * The size of the cell in pixels. a cell is an area that is used to divide
 * the screen area
 */
#define CELL_SIZE 4
/*
 * Number of voronoi seeds
 */
#define NUMBER_OF_SEEDS 10
#define DEBUG 0

typedef struct {
  int x;
  int y;
  int w;
  int h;
  int r;
  int g;
  int b;
} Cell;

typedef struct {
  int x;
  int y;
  int r;
  int g;
  int b;
} Seed;

typedef struct {
  int size;
  Seed *centers;
} Seeds;

typedef struct {
  int size;
  int cols;
  int rows;
  Cell *cells;
} Grid;

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} App;
