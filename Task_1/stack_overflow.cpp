#include <iostream>

void recurse(int y) {
    int x = y;
    recurse(y + 1);
}

int main() {
    recurse(0);
    return 0;
}
