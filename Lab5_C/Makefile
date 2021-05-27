main: Lab5_C.c 
	gcc -o main Lab5_C.c
test: Lab5_C.c test_5.c
	gcc -o test -Dmain=_main Lab5_C.c test_5.c
	echo "y\nlim\ntre\nyte\nqfw\nn\n" > test.txt
	./test < test.txt
