all: main

main: main.o
	gcc -pg -o main main.o

main.o: main.c main.h
	gcc -pg -Wall -c main.c -o main.o

profiling: main
	gprof main gmon.out > profiling.txt

clean:
	rm -f main main.o gmon.out profiling.txt
