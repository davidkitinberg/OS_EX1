

all:
	gcc -Wall -Wextra -g dijkstra_infinite_loop.c -o dijkstra_infinite_loop

gcov:
	rm -f dijkstra_infinite_loop *.gcda *.gcno *.gcov
	gcc -Wall -Wextra -g -fprofile-arcs -ftest-coverage dijkstra_infinite_loop.c -o dijkstra_infinite_loop

run:
	./dijkstra_infinite_loop

report:
	gcov dijkstra_infinite_loop.c

clean:
	rm -f dijkstra_infinite_loop *.o *.gcda *.gcno *.gcov
