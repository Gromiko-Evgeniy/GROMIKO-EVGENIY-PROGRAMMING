main: Lab7_C.c 
 gcc -o main catalog.c Lab7_C.c -lm
test: Lab7_C.c test_7.c
 gcc -ftest-coverage -fprofile-arcs -O0 -o test -Dmain=_main catalog.c Lab7_C.c test_7.c -lm
 ./test
 gcov -abcfu catalog.c Lab7_C.c
 
