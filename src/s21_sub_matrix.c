#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *matrix1, matrix_t *matrix2, matrix_t *result) {
  if (s21_check_valid_matrix(matrix1) != 0 ||
      s21_check_valid_matrix(matrix2) != 0) {
    return 1;
  }

  if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
    return 2;
  }

  s21_create_matrix(matrix1->rows, matrix1->columns, result);

  for (int i = 0; i < matrix1->rows; ++i) {
    for (int j = 0; j < matrix1->columns; ++j) {
      result->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
    }
  }

  return 0;
}