#include <iostream>
#include <cmath>

int main() {
    int X;
    std::cin >> X;

    int result = 1;
    for (int b = 2; b <= X; b++) {
        for (int p = 2; pow(b, p) <= X; p++) {
            result = pow(b, p);
        }
    }

    std::cout << result << std::endl;

    return 0;
}