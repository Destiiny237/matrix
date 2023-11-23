#include <math.h>

#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *matrix1, matrix_t *matrix2) {
  if (s21_check_valid_matrix(matrix1) != 0 ||
      s21_check_valid_matrix(matrix2) != 0) {
    return FAILURE;
  }

  if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
    return FAILURE;
  }

  for (int i = 0; i < matrix1->rows; ++i) {
    for (int j = 0; j < matrix1->columns; ++j) {
      if (round(matrix1->matrix[i][j] * 1e7) !=
          round(matrix2->matrix[i][j] * 1e7)) {
        return FAILURE;
      }
    }
  }

  return SUCCESS;
}