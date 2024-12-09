#include <iostream>

int main() {
    long long S;
    std::cin >> S;

    // Find six integers that satisfy the conditions for the given value of S
    long long X1 = 0, Y1 = 0, X2 = S, Y2 = 1, X3 = 0, Y3 = 0;

    std::cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " " << X3 << " " << Y3 << std::endl;

    return 0;
}