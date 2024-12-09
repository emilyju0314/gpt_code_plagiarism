#include <iostream>

std::string determineWinner(long long n, long long x, long long y) {
    long long whiteSteps = x + y - 2;
    long long blackSteps = 2*n - x - y;

    if (whiteSteps <= blackSteps) {
        return "White";
    } else {
        return "Black";
    }
}

int main() {
    long long n, x, y;
    std::cin >> n >> x >> y;

    std::cout << determineWinner(n, x, y) << std::endl;

    return 0;
}