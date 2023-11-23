#include "test.h"

START_TEST(test_mult_matrix_1) {
  matrix_t first = create_test_square_matrix_0();
  matrix_t second = create_test_square_matrix_0();

  matrix_t s21_result = {};
  s21_mult_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 3, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 16;
  real_matrix_result.matrix[0][1] = 16;
  real_matrix_result.matrix[0][2] = 10;

  real_matrix_result.matrix[1][0] = 10;
  real_matrix_result.matrix[1][1] = 20;
  real_matrix_result.matrix[1][2] = 10;

  real_matrix_result.matrix[2][0] = 10;
  real_matrix_result.matrix[2][1] = 20;
  real_matrix_result.matrix[2][2] = 20;

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

START_TEST(test_mult_matrix_2) {
  matrix_t first = create_test_square_matrix_0();
  matrix_t second = create_test_rectangle_matrix_1();

  matrix_t s21_result = {};
  s21_mult_matrix(&first, &second, &s21_result);

  matrix_t real_matrix_result = {};
  s21_create_matrix(3, 4, &real_matrix_result);

  real_matrix_result.matrix[0][0] = 34.1706831;
  real_matrix_result.matrix[0][1] = 40.7701193;
  real_matrix_result.matrix[0][2] = 42.9960919;
  real_matrix_result.matrix[0][3] = 65.09232706;

  real_matrix_result.matrix[1][0] = 33.7268094;
  real_matrix_result.matrix[1][1] = 41.7145412;
  real_matrix_result.matrix[1][2] = 42.770742;
  real_matrix_result.matrix[1][3] = 70.82392184;

  real_matrix_result.matrix[2][0] = 24.0750117;
  real_matrix_result.matrix[2][1] = 31.0957321;
  real_matrix_result.matrix[2][2] = 38.1755135;
  real_matrix_result.matrix[2][3] = 152.17922842;

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

START_TEST(test_mult_matrix_3) {
  matrix_t first = {};
  matrix_t second = {};
  s21_create_matrix(1, 1, &second);

  matrix_t s21_result = {};

  ck_assert_int_eq(s21_mult_matrix(&first, &second, &s21_result), 1);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&s21_result);
}

START_TEST(test_mult_matrix_4) {
  matrix_t first = create_test_rectangle_matrix_1();
  matrix_t second = {};
  s21_create_matrix(1, 1, &second);

  matrix_t s21_result = {};

  ck_assert_int_eq(s21_mult_matrix(&first, &second, &s21_result), 2);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&s21_result);
}

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_mult_matrixr=-\033[0m");
  TCase *tc = tcase_create("mult_matrix_tc");

  tcase_add_test(tc, test_mult_matrix_1);
  tcase_add_test(tc, test_mult_matrix_2);
  tcase_add_test(tc, test_mult_matrix_3);
  tcase_add_test(tc, test_mult_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
