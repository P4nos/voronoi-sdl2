#include <SDL2/SDL_rect.h>
#include <stdint.h>
void prepareScene(void);
void presentScene(void);
void drawCicle(SDL_Point center, int r, int g, int b, int32_t radius);
void drawPoints(Seeds *seeds);
void drawSquareGrid(int numCells);
void drawGrid(Grid *grid);
void drawPlane(Grid *grid);
