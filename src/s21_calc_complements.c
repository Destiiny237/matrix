#include "s21_matrix.h"

int s21_calc_complements(matrix_t *matrix, matrix_t *result) {
  if (s21_check_valid_matrix(matrix) != 0) {
    return 1;
  }

  if (matrix->rows != matrix->columns) {
    return 2;
  }

  s21_create_matrix(matrix->rows, matrix->columns, result);

  matrix_t minor = {};
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, &minor);

  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      int result_minor = s21_minor(matrix, i, j, &minor);

      if (result_minor != 0) {
        s21_remove_matrix(&minor);
        return 2;
      }

      // алгебраическое дополнение (-1)^(i+j) * det(minor)
      int sign = (i + j) % 2 == 0 ? 1 : -1;

      double det_minor;
      s21_determinant(&minor, &det_minor);

      result->matrix[i][j] = sign * det_minor;
    }
  }

  s21_remove_matrix(&minor);
  return 0;
}
