#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *matrix1, matrix_t *matrix2, matrix_t *result) {
  if (s21_check_valid_matrix(matrix1) != 0 ||
      s21_check_valid_matrix(matrix2) != 0) {
    return 1;
  }

  if (matrix1->columns != matrix2->rows) {
    return 2;
  }

  s21_create_matrix(matrix1->rows, matrix2->columns, result);

  for (int i = 0; i < matrix1->rows; ++i) {
    for (int j = 0; j < matrix2->columns; ++j) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < matrix1->columns; ++k) {
        result->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
      }
    }
  }

  return 0;
}