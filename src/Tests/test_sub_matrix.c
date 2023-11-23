#include "test.h"

START_TEST(test_sub_matrix_1) {
  matrix_t first = create_test_square_matrix_0();
  matrix_t second = create_test_square_matrix_0();

  matrix_t s21_result = {};
  s21_sub_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 0;
  real_matrix_result.matrix[0][1] = 0;
  real_matrix_result.matrix[0][2] = 0;

  real_matrix_result.matrix[1][0] = 0;
  real_matrix_result.matrix[1][1] = 0;
  real_matrix_result.matrix[1][2] = 0;

  real_matrix_result.matrix[2][0] = 0;
  real_matrix_result.matrix[2][1] = 0;
  real_matrix_result.matrix[2][2] = 0;

  for (int i = 0; i < s21_result.rows; i++) {
    for (int j = 0; j < s21_result.columns; j++) {
      ck_assert_double_eq_tol(s21_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}

START_TEST(test_sub_matrix_2) {
  matrix_t first = create_test_rectangle_matrix_2();
  matrix_t second = create_test_rectangle_matrix_3();

  matrix_t s21_result = {};
  s21_sub_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 4, &real_matrix_result);

  real_matrix_result.matrix[0][0] = -66.8846428;
  real_matrix_result.matrix[0][1] = -12.0105419;
  real_matrix_result.matrix[0][2] = 0;
  real_matrix_result.matrix[0][3] = 0;

  real_matrix_result.matrix[1][0] = 0;
  real_matrix_result.matrix[1][1] = -69.9246924;
  real_matrix_result.matrix[1][2] = -18.0062;
  real_matrix_result.matrix[1][3] = -32.2485046;

  real_matrix_result.matrix[2][0] = -0.599;
  real_matrix_result.matrix[2][1] = -14.8651564;
  real_matrix_result.matrix[2][2] = -8;
  real_matrix_result.matrix[2][3] = -74.32681252;

  for (int i = 0; i < s21_result.rows; i++) {
    for (int j = 0; j < s21_result.columns; j++) {
      ck_assert_double_eq_tol(s21_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_sub_matrix=-\033[0m");
  TCase *tc = tcase_create("sub_matrix_tc");

  tcase_add_test(tc, test_sub_matrix_1);
  tcase_add_test(tc, test_sub_matrix_2);

  suite_add_tcase(s, tc);
  return s;
}
