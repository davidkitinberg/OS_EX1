
all: main

# Create shared library
libmandelbrot.so: mandelbrot.o
	g++ -shared -o $@ $^

mandelbrot.o: mandelbrot.cpp mandelbrot.h
	g++ -Wall -fPIC -g -c mandelbrot.cpp

# Build main and link it to the shared lib. Make sure the linker looks for the shared library in our current directory
main: main.cpp mandelbrot.h libmandelbrot.so
	g++ main.cpp -L. -lmandelbrot -Wl,-rpath=. -o main


clean:
	rm -f *.o *.so main
