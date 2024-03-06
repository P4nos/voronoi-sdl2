#include "common.h"
#include <math.h>

int eucledeanDistance(Cell cell, Seed seed);

void partionPlane(Seeds *seeds, Grid *grid) {

  for (int i = 0; i < grid->size; i++) {
    int min = SCREEN_WIDTH + 2; // instantiate to point outside the screen
    Cell *cell = &grid->cells[i];
    Seed closestSeed;

    for (int j = 0; j < seeds->size; j++) {
      Seed seed = seeds->centers[j];
      int distance = eucledeanDistance(*cell, seed);

      if (DEBUG) {
        printf("cellx: %d, celly: %d, seedx: %d, seedy: %d, distance %d\n",
               cell->x, cell->y, seed.x, seed.y, distance);
      }

      if (distance <= min) {
        min = distance;
        closestSeed = seed;
        if (DEBUG) {
          printf("min: %d, closest.x: %d, closest.y: %d\n", min, closestSeed.x,
                 closestSeed.y);
        }
      }
    }
    // mark cell as part of the point region
    cell->r = closestSeed.r;
    cell->g = closestSeed.g;
    cell->b = closestSeed.b;
  }
}

int eucledeanDistance(Cell cell, Seed seed) {
  return sqrt(pow((cell.x - seed.x), 2) + pow((cell.y - seed.y), 2));
}
