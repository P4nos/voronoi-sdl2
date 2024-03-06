#include <stdlib.h>
int randInRange(int lower, int upper) {
  return lower + rand() / (RAND_MAX / (upper - lower + 1) + 1);
}
