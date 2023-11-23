#include "s21_matrix.h"

int s21_minor(matrix_t *matrix, int r, int c, matrix_t *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  if (r < 0 || r >= matrix->rows || c < 0 || c >= matrix->columns) {
    return 2;
  }

  int row_index_result = 0;
  for (int i = 0; i < matrix->rows; i++) {
    if (i == r) {
      continue;
    }
    int col_index_result = 0;
    for (int j = 0; j < matrix->columns; j++) {
      if (j == c) {
        continue;
      }
      result->matrix[row_index_result][col_index_result] = matrix->matrix[i][j];
      col_index_result++;
    }
    row_index_result++;
  }

  return 0;
}

int s21_check_valid_matrix(matrix_t *matrix) {
  if (matrix == NULL) {
    return 1;
  }

  if (matrix->rows < 1 || matrix->columns < 1) {
    return 1;
  }

  return 0;
}