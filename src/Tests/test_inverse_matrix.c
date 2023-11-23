#include "test.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t matrix = create_test_square_matrix_0();
  matrix_t s21_result = {NULL, 0, 0};
  s21_inverse_matrix(&matrix, &s21_result);

  matrix_t real_matrix_result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 0.0f;
  real_matrix_result.matrix[0][1] = -0.1;
  real_matrix_result.matrix[0][2] = 0.2;

  real_matrix_result.matrix[1][0] = -0.25;
  real_matrix_result.matrix[1][1] = 0.35;
  real_matrix_result.matrix[1][2] = 0.05;

  real_matrix_result.matrix[2][0] = 0.5;
  real_matrix_result.matrix[2][1] = -0.2;
  real_matrix_result.matrix[2][2] = -0.1;

  for (int i = 0; i < s21_result.rows; i++) {
    for (int j = 0; j < s21_result.columns; j++) {
      ck_assert_double_eq_tol(s21_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  matrix_t matrix = create_test_square_matrix_1();
  matrix_t s21_result;
  s21_inverse_matrix(&matrix, &s21_result);

  matrix_t real_matrix_result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 0.0815298;
  real_matrix_result.matrix[0][1] = -1.2980499;
  real_matrix_result.matrix[0][2] = 0.8420882;

  real_matrix_result.matrix[1][0] = -0.9043357;
  real_matrix_result.matrix[1][1] = 1.5598000;
  real_matrix_result.matrix[1][2] = -0.7150942;

  real_matrix_result.matrix[2][0] = 0.8145415;
  real_matrix_result.matrix[2][1] = -0.3985704;
  real_matrix_result.matrix[2][2] = 0.0775802;

  for (int i = 0; i < s21_result.rows; i++) {
    for (int j = 0; j < s21_result.columns; j++) {
      ck_assert_double_eq_tol(s21_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  matrix_t matrix = {};
  matrix_t s21_result = {};
  s21_inverse_matrix(&matrix, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &s21_result), 1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  matrix_t matrix = create_test_rectangle_matrix_2();
  matrix_t s21_result = {};
  s21_inverse_matrix(&matrix, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &s21_result), 2);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&real_matrix_result);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_inverse_matrix=-\033[0m");
  TCase *tc = tcase_create("inverse_matrix_tc");

  tcase_add_test(tc, test_inverse_matrix_1);
  tcase_add_test(tc, test_inverse_matrix_2);
  tcase_add_test(tc, test_inverse_matrix_3);
  tcase_add_test(tc, test_inverse_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
