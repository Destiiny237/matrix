#include "test.h"

START_TEST(test_sum_matrix_1) {
  matrix_t first = create_test_square_matrix_0();
  matrix_t second = create_test_square_matrix_0();

  matrix_t s21_result = {};
  s21_sum_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 2;
  real_matrix_result.matrix[0][1] = 4;
  real_matrix_result.matrix[0][2] = 6;

  real_matrix_result.matrix[1][0] = 0;
  real_matrix_result.matrix[1][1] = 8;
  real_matrix_result.matrix[1][2] = 4;

  real_matrix_result.matrix[2][0] = 10;
  real_matrix_result.matrix[2][1] = 4;
  real_matrix_result.matrix[2][2] = 2;

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

START_TEST(test_sum_matrix_2) {
  matrix_t first = create_test_rectangle_matrix_2();
  matrix_t second = create_test_rectangle_matrix_3();

  matrix_t s21_result = {};
  s21_sum_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 4, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 64;
  real_matrix_result.matrix[0][1] = 16.0779265;
  real_matrix_result.matrix[0][2] = 6.716057;
  real_matrix_result.matrix[0][3] = 46.706907;

  real_matrix_result.matrix[1][0] = 8.9309262;
  real_matrix_result.matrix[1][1] = 58;
  real_matrix_result.matrix[1][2] = 30.2528248;
  real_matrix_result.matrix[1][3] = 0;

  real_matrix_result.matrix[2][0] = 15.265957;
  real_matrix_result.matrix[2][1] = 11;
  real_matrix_result.matrix[2][2] = 10.2526924;
  real_matrix_result.matrix[2][3] = 70.00009988;

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

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_sum_matrix=-\033[0m");
  TCase *tc = tcase_create("sum_matrix_tc");

  tcase_add_test(tc, test_sum_matrix_1);
  tcase_add_test(tc, test_sum_matrix_2);

  suite_add_tcase(s, tc);
  return s;
}
