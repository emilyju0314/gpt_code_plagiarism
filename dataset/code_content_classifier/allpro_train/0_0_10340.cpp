#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    int maxCoins = 1;
    while (n % 3 == 0) {
        n /= 3;
        maxCoins++;
    }

    std::cout << maxCoins << std::endl;

    return 0;
}