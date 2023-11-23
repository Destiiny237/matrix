#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1) {
    return 1;
  }

  result->matrix = calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }

  result->rows = rows;
  result->columns = columns;

  return 0;
}