#include "mandelbrot.h"
#include <iostream>
#include <complex>
#include <cstdio>

int main() {
    double real, imag;
    int N = 1000;
    bool stop = true;

    while (stop)
    {

        // Scan user's input
        if (scanf("%lf %lf", &real, &imag) != 2) {
            std::cerr << "Invalid input.\n";
            return 1;
        }

        // End program if user enters 0 0
        if (real == 0 && imag == 0) {
            std::cout << "Termination input received (0 + 0i). Exiting.\n";
            stop = false;
        }

        std::complex<double> c(real, imag);
        if (is_in_mandelbrot(c, N)) // Call for is_in_mandelbrot function from shared library
        {
            std::cout << real << " + " << imag << "i is in the Mandelbrot set" << std::endl;
        } 
        else 
        {
            std::cout << real << " + " << imag << "i is not in the Mandelbrot set" << std::endl;
        }
    }
    
}
