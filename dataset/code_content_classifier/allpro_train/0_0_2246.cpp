#include <iostream>

int main() {
    long long n, m;
    int k;
    std::cin >> n >> m >> k;

    long long sum = 0;
    long long multiplier = 1;
    for (int i = 0; i < k; i++) {
        sum += (n % 10 + ((i * m) % 10)) * multiplier;
        n /= 10;
        multiplier *= 10;
    }

    std::cout << sum << std::endl;

    return 0;
}