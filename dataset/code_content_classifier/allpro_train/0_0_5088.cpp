#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int L = A + B;
    int R = C + D;

    if (L > R) {
        std::cout << "Left";
    } else if (L == R) {
        std::cout << "Balanced";
    } else {
        std::cout << "Right";
    }

    return 0;
}