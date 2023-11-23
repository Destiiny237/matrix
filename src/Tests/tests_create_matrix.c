#include "test.h"

matrix_t create_test_square_matrix_0() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1.0f;
  matrix.matrix[0][1] = 2.0f;
  matrix.matrix[0][2] = 3.0f;

  matrix.matrix[1][0] = 0.0f;
  matrix.matrix[1][1] = 4.0f;
  matrix.matrix[1][2] = 2.0f;

  matrix.matrix[2][0] = 5.0f;
  matrix.matrix[2][1] = 2.0f;
  matrix.matrix[2][2] = 1.0f;

  return matrix;
}

matrix_t create_test_square_matrix_1() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1.429513;
  matrix.matrix[0][1] = 2.047692;
  matrix.matrix[0][2] = 3.358028;

  matrix.matrix[1][0] = 4.465463;
  matrix.matrix[1][1] = 5.923475;
  matrix.matrix[1][2] = 6.129512;

  matrix.matrix[2][0] = 7.932478;
  matrix.matrix[2][1] = 8.932578;
  matrix.matrix[2][2] = 9.123312;

  return matrix;
}

matrix_t create_test_square_matrix_2() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1.4295134;
  matrix.matrix[0][1] = 2.0476923;
  matrix.matrix[0][2] = 3.3580285;

  matrix.matrix[1][0] = 4.4654631;
  matrix.matrix[1][1] = 5.9234752;
  matrix.matrix[1][2] = 6.1295124;

  matrix.matrix[2][0] = 7.9324785;
  matrix.matrix[2][1] = 8.9325782;
  matrix.matrix[2][2] = 9.1233122;

  return matrix;
}

matrix_t create_test_square_matrix_3() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1.4423214;
  matrix.matrix[0][1] = 2.0476923;
  matrix.matrix[0][2] = 3.3580285;

  matrix.matrix[1][0] = 4.4654631;
  matrix.matrix[1][1] = 5.9623462;
  matrix.matrix[1][2] = 6.1295124;

  matrix.matrix[2][0] = 7.9324785;
  matrix.matrix[2][1] = 8.9325782;
  matrix.matrix[2][2] = 9.1263462;

  return matrix;
}

matrix_t create_test_edge_square_matrix_4() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 7.4423214;
  return matrix;
}

matrix_t create_test_edge_square_matrix_5() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 0;
  matrix.matrix[0][1] = 0;
  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 0;
  return matrix;
}

matrix_t create_test_edge_square_matrix_6() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(0, 0, &matrix);

  return matrix;
}

matrix_t create_test_rectangle_matrix_1() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 4, &matrix);
  matrix.matrix[0][0] = 1.4423214;
  matrix.matrix[0][1] = 2.0476923;
  matrix.matrix[0][2] = 3.3580285;
  matrix.matrix[0][3] = 23.3534535;

  matrix.matrix[1][0] = 4.4654631;
  matrix.matrix[1][1] = 5.9623462;
  matrix.matrix[1][2] = 6.1295124;
  matrix.matrix[1][3] = 16.1242523;

  matrix.matrix[2][0] = 7.9324785;
  matrix.matrix[2][1] = 8.9325782;
  matrix.matrix[2][2] = 9.1263462;
  matrix.matrix[2][3] = 3.16345632;

  return matrix;
}

matrix_t create_test_rectangle_matrix_2() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 4, &matrix);
  matrix.matrix[0][0] = -1.4423214;
  matrix.matrix[0][1] = 2.0336923;
  matrix.matrix[0][2] = 3.3580285;
  matrix.matrix[0][3] = 23.3534535;

  matrix.matrix[1][0] = 4.4654631;
  matrix.matrix[1][1] = -5.9623462;
  matrix.matrix[1][2] = 6.1233124;
  matrix.matrix[1][3] = -16.1242523;

  matrix.matrix[2][0] = 7.3334785;
  matrix.matrix[2][1] = -1.9325782;
  matrix.matrix[2][2] = 1.1263462;
  matrix.matrix[2][3] = -2.16335632;

  return matrix;
}

matrix_t create_test_rectangle_matrix_3() {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(3, 4, &matrix);
  matrix.matrix[0][0] = 65.4423214;
  matrix.matrix[0][1] = 14.0442342;
  matrix.matrix[0][2] = 3.3580285;
  matrix.matrix[0][3] = 23.3534535;

  matrix.matrix[1][0] = 4.4654631;
  matrix.matrix[1][1] = 63.9623462;
  matrix.matrix[1][2] = 24.1295124;
  matrix.matrix[1][3] = 16.1242523;

  matrix.matrix[2][0] = 7.9324785;
  matrix.matrix[2][1] = 12.9325782;
  matrix.matrix[2][2] = 9.1263462;
  matrix.matrix[2][3] = 72.1634562;

  return matrix;
}