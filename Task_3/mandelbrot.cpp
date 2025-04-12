#include "mandelbrot.h"
#include <complex>

bool is_in_mandelbrot(std::complex<double> c, int N) {
    std::complex<double> z = 0;
    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (abs(z) > 3.0)
            return false;
    }
    return true;
}
