#include <iostream>

int main() {
    long long n, k;
    std::cin >> n >> k;

    long long position = 1;
    long long interval = n;

    while (k > 1) {
        interval = (interval + 1) / 2;
        position += interval;
        k--;
    }

    std::cout << position << std::endl;

    return 0;
}