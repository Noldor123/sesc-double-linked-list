run:prog
	./prog
prog:prog.c
	gcc -std=c99 prog.c -o prog
build:prog
