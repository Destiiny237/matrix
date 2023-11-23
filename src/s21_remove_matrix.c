#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->matrix[i]);
  }
  free(matrix->matrix);

  matrix->rows = 0;
  matrix->columns = 0;
  matrix->matrix = NULL;
  matrix = NULL;
}