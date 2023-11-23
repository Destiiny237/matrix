#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>


#include "../s21_matrix.h"

matrix_t create_test_square_matrix_0();
matrix_t create_test_square_matrix_1();
matrix_t create_test_square_matrix_2();
matrix_t create_test_square_matrix_3();
matrix_t create_test_edge_square_matrix_4();
matrix_t create_test_edge_square_matrix_5();
matrix_t create_test_edge_square_matrix_6();

matrix_t create_test_rectangle_matrix_1();
matrix_t create_test_rectangle_matrix_2();
matrix_t create_test_rectangle_matrix_3();

Suite *test_determinant(void);
Suite *test_calc_complements(void);
Suite *test_eq_matrix(void);
Suite *test_inverse_matrix(void);
Suite *test_mult_matrix(void);
Suite *test_mult_number(void);
Suite *test_create_remove_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_sum_matrix(void);
Suite *test_transpose(void);

#endif