#include "test.h"

START_TEST(test_calc_complements_1) {
  matrix_t matrix = create_test_square_matrix_0();

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 0;
  real_matrix_result.matrix[0][1] = 10;
  real_matrix_result.matrix[0][2] = -20;

  real_matrix_result.matrix[1][0] = 4;
  real_matrix_result.matrix[1][1] = -14;
  real_matrix_result.matrix[1][2] = 8;

  real_matrix_result.matrix[2][0] = -8;
  real_matrix_result.matrix[2][1] = -2;
  real_matrix_result.matrix[2][2] = 4;

  matrix_t s21_matrix_result = {};
  s21_calc_complements(&matrix, &s21_matrix_result);

  for (int i = 0; i < s21_matrix_result.rows; i++) {
    for (int j = 0; j < s21_matrix_result.columns; j++) {
      ck_assert_double_eq_tol(s21_matrix_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&real_matrix_result);
  s21_remove_matrix(&s21_matrix_result);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t matrix = create_test_square_matrix_1();
  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);
  real_matrix_result.matrix[0][0] = -0.7106334;
  real_matrix_result.matrix[0][1] = 7.8824069;
  real_matrix_result.matrix[0][2] = -7.0997385;

  real_matrix_result.matrix[1][0] = 11.3141140;
  real_matrix_result.matrix[1][1] = -13.5955901;
  real_matrix_result.matrix[1][2] = 3.4740353;

  real_matrix_result.matrix[2][0] = -7.3398422;
  real_matrix_result.matrix[2][1] = 6.2329326;
  real_matrix_result.matrix[2][2] = -0.6762083;

  matrix_t s21_matrix_result = {};
  s21_calc_complements(&matrix, &s21_matrix_result);

  for (int i = 0; i < s21_matrix_result.rows; i++) {
    for (int j = 0; j < s21_matrix_result.columns; j++) {
      ck_assert_double_eq_tol(s21_matrix_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], 1.0E-7);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&real_matrix_result);
  s21_remove_matrix(&s21_matrix_result);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t matrix = {};
  matrix_t s21_matrix_result = {};
  ck_assert_int_eq(s21_calc_complements(&matrix, &s21_matrix_result), 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_matrix_result);
  s21_remove_matrix(&s21_matrix_result);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t matrix = create_test_rectangle_matrix_1();
  matrix_t s21_matrix_result = {};
  ck_assert_int_eq(s21_calc_complements(&matrix, &s21_matrix_result), 2);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_matrix_result);
  s21_remove_matrix(&s21_matrix_result);
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t matrix = create_test_rectangle_matrix_2();
  matrix_t s21_matrix_result = {};
  ck_assert_int_eq(s21_calc_complements(&matrix, &s21_matrix_result), 2);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_matrix_result);
  s21_remove_matrix(&s21_matrix_result);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_calc_complements=-\033[0m");
  TCase *tc = tcase_create("calc_complements_tc");

  tcase_add_test(tc, test_calc_complements_1);
  tcase_add_test(tc, test_calc_complements_2);
  tcase_add_test(tc, test_calc_complements_3);
  tcase_add_test(tc, test_calc_complements_4);
  tcase_add_test(tc, test_calc_complements_5);

  suite_add_tcase(s, tc);
  return s;
}