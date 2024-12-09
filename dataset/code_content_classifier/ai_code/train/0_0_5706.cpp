#include <iostream>

int main() {
    int n, r, ai, bi, ci;
    double result = 0.0;

    std::cin >> n >> r;
    for (int i = 0; i < n; i++) {
        std::cin >> ai >> bi >> ci;
        result += static_cast<double>(r) / (ai + bi + ci);
    }

    result /= n;
    std::cout << result << std::endl;

    return 0;
}