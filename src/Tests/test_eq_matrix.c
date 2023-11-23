#include "test.h"

START_TEST(test_equal_1) {
  matrix_t first = create_test_square_matrix_1();
  matrix_t second = create_test_square_matrix_2();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_2) {
  matrix_t first = create_test_square_matrix_1();
  matrix_t second = create_test_square_matrix_3();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_3) {
  matrix_t first = create_test_square_matrix_2();
  matrix_t second = create_test_square_matrix_3();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_4) {
  matrix_t first = create_test_rectangle_matrix_1();
  matrix_t second = create_test_rectangle_matrix_1();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 1);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_5) {
  matrix_t first = create_test_rectangle_matrix_2();
  matrix_t second = create_test_rectangle_matrix_3();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_6) {
  matrix_t first = create_test_rectangle_matrix_1();
  matrix_t second = create_test_rectangle_matrix_3();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_7) {
  matrix_t first = create_test_rectangle_matrix_2();
  matrix_t second = create_test_rectangle_matrix_1();

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(test_equal_8) {
  matrix_t first = {};
  matrix_t second = {};

  ck_assert_int_eq(s21_eq_matrix(&first, &second), 0);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_eq_matrix=-\033[0m");
  TCase *tc = tcase_create("eq_matrix_tc");

  tcase_add_test(tc, test_equal_1);
  tcase_add_test(tc, test_equal_2);
  tcase_add_test(tc, test_equal_3);
  tcase_add_test(tc, test_equal_4);
  tcase_add_test(tc, test_equal_5);
  tcase_add_test(tc, test_equal_6);
  tcase_add_test(tc, test_equal_7);
  tcase_add_test(tc, test_equal_8);

  suite_add_tcase(s, tc);
  return s;
}
