CC=gcc
OUT= tests
FLAGS=-Wall -Werror -Wextra -lstdc++ -std=c++17 -lgtest
SRC=SC_tests/tests.cc SmartCalc/controller.cc SmartCalc/model.cc

all: install

tests:
	$(CC) $(FLAGS) $(SRC) -o tests
	./tests

clean:
	@rm -rf $(OUT) *.a *.gch *.gcno *.gcna *.gcda *.info *.dSYM test_html .qmake.stash unit_tests report documentation latex *.gz

leaks:
	leaks -atExit -- ./tests

install:
	cd SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && mv SmartCalc/SmartCalc.app SmartCalc/SmartCalc_v2.app && mv SmartCalc/SmartCalc_v2.app ../build/

uninstall: clean
	rm -rf build/SmartCalc_v2.app

style_test:
	clang-format -n SC_tests/*
	clang-format -n SmartCalc/helpers/*
	clang-format -n SmartCalc/*.cc
	clang-format -n SmartCalc/*.h
