#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    int count = 0;
    while (n > 0) {
        count += n % 3;
        n = n / 3;
    }

    std::cout << count << std::endl;

    return 0;
}