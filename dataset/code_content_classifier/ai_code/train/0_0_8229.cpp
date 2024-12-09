#include <iostream>

int main() {
    long long n, k;
    std::cin >> n >> k;

    long long count = 0;

    if (n >= k) {
        long long max_first_toy = k - 1;
        if (max_first_toy % 2 == 0) {
            count = max_first_toy / 2;
        }
    }

    std::cout << count << std::endl;

    return 0;
}