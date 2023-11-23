#include "test.h"

START_TEST(create_remove_1) {
  matrix_t first = {};
  ck_assert_int_eq(s21_create_matrix(2, 2, &first), 0);
  s21_remove_matrix(&first);
}
END_TEST

START_TEST(create_remove_2) {
  matrix_t first = {};
  ck_assert_int_eq(s21_create_matrix(0, 0, &first), 1);
  s21_remove_matrix(&first);
}
END_TEST

START_TEST(create_remove_3) {
  matrix_t first = {};
  ck_assert_int_eq(s21_create_matrix(4, -5, &first), 1);
  s21_remove_matrix(&first);
}
END_TEST

START_TEST(create_remove_4) {
  matrix_t first = {};
  ck_assert_int_eq(s21_create_matrix(4, 91, &first), 0);
  s21_remove_matrix(&first);
}
END_TEST

Suite *test_create_remove_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_create_remove=-\033[0m");
  TCase *tc = tcase_create("create_remove_tc");

  tcase_add_test(tc, create_remove_1);
  tcase_add_test(tc, create_remove_2);
  tcase_add_test(tc, create_remove_3);
  tcase_add_test(tc, create_remove_4);

  suite_add_tcase(s, tc);
  return s;
}