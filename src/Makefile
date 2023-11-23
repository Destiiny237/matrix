gcc = gcc -std=c11 -g -Wall -Werror -Wextra

HEAD = s21_matrix.h
objectFiles = $(shell find . -name "test*.o")
functionFiles = $(shell find . -name "test*.c")
oF = $(shell find . -name "s21*.o")
fF = $(shell find . -name "s21*.c")


CHECK_FLAGS = -lcheck -pthread -lrt -lsubunit -lm

ifeq ($(shell uname -s), Mac)
CHECK_FLAGS = -lcheck
endif

all: s21_matrix.a test gcov_report

matrix.h:
	$(gcc) s21_matrix.h

s21_matrix.a: funcForA
	ar rcs $@ $(oF)
	ranlib s21_matrix.a

funcForA: library
	$(gcc) -c $(fF)

test: functions
	$(gcc) $(objectFiles) $(oF) -o s21_matrix $(CHECK_FLAGS)
	./s21_matrix

library:
	$(gcc) $(HEAD)

functions: library
	$(gcc) -c $(functionFiles) $(fF)

gcov_report: functions 
	gcc --coverage $(functionFiles) $(fF) -o s21_test $(CHECK_FLAGS) 
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clang-check:
	clang-format -n *.c *.h
	clang-format -n Tests/*.c *.h

clang-repair:
	clang-format -i *.c *.h
	clang-format -i Tests/*.c *.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes --verbose -s ./s21_matrix

clean:
	rm -rf *.o *.gch *.gcno *.gcda *.a main *.info s21_matrix s21_test ./report/

rebuild: clean all
