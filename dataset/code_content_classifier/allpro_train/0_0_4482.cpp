#include <iostream>
#include <cmath>

int countNumbersWithEightDivisors(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int divisors = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if (i / j == j) {
                    divisors++;
                } else {
                    divisors += 2;
                }
            }
        }
        if (divisors == 8 && i % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;

    int result = countNumbersWithEightDivisors(N);
    std::cout << result << std::endl;

    return 0;
}