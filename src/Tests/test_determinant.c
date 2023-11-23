#include "test.h"

START_TEST(test_determinant_1) {
  matrix_t matrix = create_test_square_matrix_1();
  double real_determinant = -8.7162391;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);
  ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
  // memset(&matrix, 0, sizeof(matrix));
}
END_TEST

START_TEST(test_determinant_2) {
  matrix_t matrix = create_test_square_matrix_2();
  double real_determinant = -8.7162433;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);
  ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t matrix = create_test_square_matrix_3();
  double real_determinant = -9.2509286;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);
  ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_4) {
  matrix_t matrix = create_test_edge_square_matrix_4();
  double real_determinant = 7.4423214;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);
  ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_5) {
  matrix_t matrix = create_test_edge_square_matrix_5();
  double real_determinant = 0.0;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);

  ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_6) {
  matrix_t matrix = create_test_edge_square_matrix_6();
  // double real_determinant = 24;
  double school21_determinant = 0.0;

  s21_determinant(&matrix, &school21_determinant);
  ck_assert_int_eq(s21_determinant(&matrix, &school21_determinant), 1);
  // ck_assert_double_eq_tol(real_determinant, school21_determinant, 1.0E-7);

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[45m-=S21_determinant=-\033[0m");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, test_determinant_1);
  tcase_add_test(tc, test_determinant_2);
  tcase_add_test(tc, test_determinant_3);
  tcase_add_test(tc, test_determinant_4);
  tcase_add_test(tc, test_determinant_5);
  tcase_add_test(tc, test_determinant_6);

  suite_add_tcase(s, tc);
  return s;
}