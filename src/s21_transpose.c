#include "s21_matrix.h"

int s21_transpose(matrix_t *matrix, matrix_t *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  s21_create_matrix(matrix->columns, matrix->rows, result);

  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      result->matrix[j][i] = matrix->matrix[i][j];
    }
  }

  return 0;
}