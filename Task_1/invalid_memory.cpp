#include <iostream>

int main() {
    int* ptr = (int*)0xdeadbeef; // Bad pointer
    *ptr = 42; // Crash here
    return 0;
}
