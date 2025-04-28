#include <iostream>
#include <complex>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

    
    // --help
    if (argc == 2 && string(argv[1]) == "--help") {
        cerr << "Usage: " << argv[0] << " <real> <imag> [N]" << endl;
        cerr << "Options (and corresponding environment variables):  " << endl;
        cerr << "<real>      : Real number (double)" << endl;
        cerr << "<imag>      : Imaginary number (double)" << endl;
        cerr << "[N]         : Optional third variable, limit the maximum number of iterations (int)" << endl;
        return 0;
    }

    // Validate num of arguments
    if (argc < 3 || argc > 4) {
        cerr << "Error: please enter correct number of variables to run this program. \n" << endl;
        cerr << "       for more information and help run the following command: ./mandelbrot --help. \n" << endl;
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

    int M = 3.0; // We are using 3.0 for stricter threshold
    complex<double> z(0, 0);
    int i;
    for (i = 0; i < N; ++i) {
        z = z * z + c;
        if (abs(z) > M) {
            
            cout << real << " + " << imag << "i is not in the Mandelbrot set" << endl;
            return 0;
        }
    }

    cout << real << " + " << imag << "i is in the Mandelbrot set" << endl;
    return 0;
}
