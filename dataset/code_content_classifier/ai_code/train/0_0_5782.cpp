#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    int min_digits = 20; // initialize with a large value
    for (long long i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            long long j = N / i;
            int digits = std::max((int)std::to_string(i).size(), (int)std::to_string(j).size());
            min_digits = std::min(min_digits, digits);
        }
    }

    std::cout << min_digits << std::endl;

    return 0;
}