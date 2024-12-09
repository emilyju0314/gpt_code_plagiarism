#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;

        double diagonal = 1 / sin(M_PI / (2 * n));
        std::cout << std::fixed << std::setprecision(9) << diagonal << std::endl;
    }

    return 0;
}