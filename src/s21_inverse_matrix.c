#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *matrix, matrix_t *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  if (matrix->rows != matrix->columns) {
    return 2;
  }

  s21_create_matrix(matrix->rows, matrix->columns, result);

  double det_A = 0.0f;
  int result_det_A = s21_determinant(matrix, &det_A);

  if (result_det_A != 0) {
    s21_remove_matrix(result);
    return 2;
  }

  matrix_t comatrix = {NULL, 0, 0};
  int result_complements = s21_calc_complements(matrix, &comatrix);

  if (result_complements != 0) {
    s21_remove_matrix(&comatrix);
    return 2;
  }

  s21_remove_matrix(result);
  int result_transpose = s21_transpose(&comatrix, result);

  s21_remove_matrix(&comatrix);

  if (result_transpose != 0) {
    return 2;
  }

  double inv_det_A = 1.0 / det_A;
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] *= inv_det_A;
    }
  }

  return 0;
}
