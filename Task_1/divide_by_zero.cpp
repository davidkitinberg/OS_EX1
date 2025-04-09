#include <iostream>

int main() {
    int x = 1;
    int y = 0;
    int z = x / y; // Crash here
    std::cout << "Result: " << z << std::endl;
    return 0;
}
