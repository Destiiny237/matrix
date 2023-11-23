#include "s21_matrix.h"

int s21_mult_number(matrix_t *matrix, double number, matrix_t *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  s21_create_matrix(matrix->rows, matrix->columns, result);

  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      result->matrix[i][j] = matrix->matrix[i][j] * number;
    }
  }

  return 0;
}