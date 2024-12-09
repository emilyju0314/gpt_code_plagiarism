#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    long long sumX = 0, sumY = 0;
    for (int i = 0; i < N; i++) {
        long long x, y;
        std::cin >> x >> y;
        sumX += x;
        sumY += y;
    }

    long long X = (sumX + sumY) / 2;
    std::cout << X << std::endl;

    return 0;
}