#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    double debt = 100000;

    for (int i = 0; i < n; i++) {
        debt = ceil(debt * 1.05 / 1000) * 1000;
    }

    std::cout << debt << std::endl;

    return 0;
}