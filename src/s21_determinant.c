#include "s21_matrix.h"

int s21_determinant(matrix_t *matrix, double *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  if (matrix->rows != matrix->columns) {
    return 2;
  }

  if (matrix->rows == 1) {
    *result = matrix->matrix[0][0];
    return 0;
  }

  if (matrix->rows == 2) {
    *result = matrix->matrix[0][0] * matrix->matrix[1][1] -
              matrix->matrix[0][1] * matrix->matrix[1][0];
    return 0;
  }

  *result = 0;

  matrix_t minor = {NULL, 0, 0};
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, &minor);

  for (int j = 0; j < matrix->columns; j++) {
    int result_minor = s21_minor(matrix, 0, j, &minor);

    if (result_minor != 0) {
      s21_remove_matrix(&minor);
      return 2;
    }

    double det_minor;
    int result_det_minor = s21_determinant(&minor, &det_minor);

    if (result_det_minor != 0) {
      s21_remove_matrix(&minor);
      return 2;
    }

    // Алгебраическое дополнение = (-1)^j * matrix[0][j] * det(minor)
    int sign = j % 2 == 0 ? 1 : -1;
    *result += sign * matrix->matrix[0][j] * det_minor;
  }

  s21_remove_matrix(&minor);
  return 0;
}