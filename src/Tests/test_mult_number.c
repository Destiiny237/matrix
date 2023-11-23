#include "test.h"

START_TEST(test_mult_number_1) {
  matrix_t matrix = create_test_square_matrix_0();
  matrix_t s21_result = {};
  s21_mult_number(&matrix, 5, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 5;
  real_matrix_result.matrix[0][1] = 10;
  real_matrix_result.matrix[0][2] = 15;

  real_matrix_result.matrix[1][0] = 0;
  real_matrix_result.matrix[1][1] = 20;
  real_matrix_result.matrix[1][2] = 10;

  real_matrix_result.matrix[2][0] = 25;
  real_matrix_result.matrix[2][1] = 10;
  real_matrix_result.matrix[2][2] = 5;

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

START_TEST(test_mult_number_2) {
  matrix_t matrix = create_test_square_matrix_1();
  matrix_t s21_result = {};
  s21_mult_number(&matrix, 5, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 7.147565;
  real_matrix_result.matrix[0][1] = 10.238460;
  real_matrix_result.matrix[0][2] = 16.790140;

  real_matrix_result.matrix[1][0] = 22.327315;
  real_matrix_result.matrix[1][1] = 29.617375;
  real_matrix_result.matrix[1][2] = 30.647560;

  real_matrix_result.matrix[2][0] = 39.662390;
  real_matrix_result.matrix[2][1] = 44.662890;
  real_matrix_result.matrix[2][2] = 45.616560;

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

START_TEST(test_mult_number_3) {
  matrix_t matrix = {};
  matrix_t s21_result = {};

  ck_assert_int_eq(s21_mult_number(&matrix, 5, &s21_result), 1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&s21_result);
}
END_TEST

START_TEST(test_mult_number_4) {
  matrix_t matrix = create_test_edge_square_matrix_4();
  matrix_t s21_result = {};
  s21_mult_number(&matrix, 5, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(1, 1, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 37.2116070;

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

START_TEST(test_mult_number_5) {
  matrix_t matrix = create_test_rectangle_matrix_3();
  matrix_t s21_result = {};
  s21_mult_number(&matrix, -0.123, &s21_result);
  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 4, &real_matrix_result);

  real_matrix_result.matrix[0][0] = -8.0494055322;
  real_matrix_result.matrix[0][1] = -1.7274408066;
  real_matrix_result.matrix[0][2] = -0.4130375055;
  real_matrix_result.matrix[0][3] = -2.8724747805;

  real_matrix_result.matrix[1][0] = -0.5492519613;
  real_matrix_result.matrix[1][1] = -7.8673685826;
  real_matrix_result.matrix[1][2] = -2.9679300252;
  real_matrix_result.matrix[1][3] = -1.9832830329;

  real_matrix_result.matrix[2][0] = -0.9756948555;
  real_matrix_result.matrix[2][1] = -1.5907071186;
  real_matrix_result.matrix[2][2] = -1.1225405826;
  real_matrix_result.matrix[2][3] = -8.8761051126;

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

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_mult_number=-\033[0m");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_test(tc, test_mult_number_1);
  tcase_add_test(tc, test_mult_number_2);
  tcase_add_test(tc, test_mult_number_3);
  tcase_add_test(tc, test_mult_number_4);
  tcase_add_test(tc, test_mult_number_5);

  suite_add_tcase(s, tc);
  return s;
}
