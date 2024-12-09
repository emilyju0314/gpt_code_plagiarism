#include <iostream>

int main() {
    int D, N;
    std::cin >> D >> N;

    int factor = 1;
    for (int i = 0; i < D; i++) {
        factor *= 100;
    }

    if (N == 100) {
        N = 101;
    }

    int result = N * factor;

    std::cout << result << std::endl;

    return 0;
}