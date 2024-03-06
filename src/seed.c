#include "common.h"
#include <stdlib.h>

Seeds *generateSeeds() {
  Seeds *seeds = malloc(sizeof(Seeds));
  seeds->centers = malloc(sizeof(Seed) * NUMBER_OF_SEEDS);
  seeds->size = NUMBER_OF_SEEDS;

  Seed seed;
  for (size_t i = 0; i < NUMBER_OF_SEEDS; i++) {
    seed.x = randInRange(2 * RADIUS, SCREEN_WIDTH);
    seed.y = randInRange(2 * RADIUS, SCREEN_HEIGHT);
    seed.r = randInRange(0, 255);
    seed.g = randInRange(0, 255);
    seed.b = randInRange(0, 255);
    seeds->centers[i] = seed;
  }

  return seeds;
}

void deleteSeeds(Seeds *seeds) { free(seeds); }
