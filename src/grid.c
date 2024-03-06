#include "common.h"
#include <stdlib.h>
#include <string.h>

extern App app;
extern Grid grid;

Grid *createGrid() {

  int numRows = SCREEN_WIDTH / CELL_SIZE;
  int numCols = SCREEN_HEIGHT / CELL_SIZE;

  int size = numCols * numRows;
  Grid *grid = malloc(sizeof(Grid));
  memset(grid, 0, sizeof(Grid));
  grid->cells = malloc(sizeof(Cell) * size);
  memset(grid->cells, 0, sizeof(Cell) * size);

  grid->size = size;
  grid->rows = numRows;
  grid->cols = numCols;
  return grid;
}

void initializeGrid(Grid *grid) {
  int size = grid->size;

  int cellWidth = CELL_SIZE;
  int cellHeight = CELL_SIZE;

  int row = 0;
  int col = 0;
  Cell cell;
  for (int i = 1; i <= size; i++) {
    int x = col * cellWidth;
    int y = row * cellHeight;
    //    printf("x: %d, y: %d, i: %d\n", x, y, i);

    cell.x = x;
    cell.y = y;
    cell.w = cellWidth;
    cell.h = cellHeight;
    cell.r = 0;
    cell.g = 0;
    cell.b = 0;

    //  store cell reference
    grid->cells[i - 1] = cell;

    col += 1;
    if (i % grid->rows == 0) {
      row += 1;
      col = 0;
    }
  }
}

void deleteGrid(Grid *grid) {
  if (grid != NULL) {
    free(grid->cells);
  }
}

void printGrid() {
  if (DEBUG) {
    for (size_t i = 0; i < grid.size; i++) {
      Cell cell = grid.cells[i];
      printf("x: %d, y: %d, w: %d, h: %d\n", cell.x, cell.y, cell.w, cell.h);
    }
  }
}
