#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    // Swap A and B
    int temp = A;
    A = B;
    B = temp;

    // Swap A and C
    temp = A;
    A = C;
    C = temp;

    std::cout << A << " " << B << " " << C << std::endl;

    return 0;
}