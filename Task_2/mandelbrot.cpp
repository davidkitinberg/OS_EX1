#include <iostream>
#include <complex>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

    
    // Handle --help
    if (argc == 2 && string(argv[1]) == "--help") {
        cerr << "Usage: " << argv[0] << " <real> <imag> [N]" << endl;
        return 0;
    }

    // Validate arguments
    if (argc < 3 || argc > 4) {
        cerr << "Usage: " << argv[0] << " <real> <imag> [N]" << endl;
        return 1;
    }

    // Parse real and imag parts
    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    complex<double> c(real, imag);

    // Parse N if provided
    int N = 1000;
    if (argc == 4) {
        N = atoi(argv[3]);
    }

    complex<double> z(0, 0);
    int i;
    for (i = 0; i < N; ++i) {
        z = z * z + c;
        if (abs(z) > 3.0) {
            cout << c << " is not in the Mandelbrot set" << endl;
            return 0;
        }
    }

    cout << c << " is in the Mandelbrot set" << endl;
    return 0;
}
