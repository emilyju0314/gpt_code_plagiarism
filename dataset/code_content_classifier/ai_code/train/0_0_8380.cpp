#include <iostream>

int main() {
    int M, D;
    std::cin >> M >> D;

    int productDays = 0;
    for (int m = 1; m <= M; m++) {
        for (int d = 1; d <= D; d++) {
            if (d >= 22 && m == (d % 10) * (d / 10)) {
                productDays++;
            }
        }
    }

    std::cout << productDays << std::endl;

    return 0;
}