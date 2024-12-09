#include <iostream>
#include <vector>

bool is_coprime(long long a, long long b) {
    if (a == 1 || b == 1) {
        return true;
    }
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

int main() {
    long long l, r;
    std::cin >> l >> r;

    for (long long a = l; a <= r - 2; a++) {
        for (long long b = a + 1; b <= r - 1; b++) {
            if (is_coprime(a, b)) {
                for (long long c = b + 1; c <= r; c++) {
                    if (!is_coprime(a, c) && is_coprime(b, c)) {
                        std::cout << a << " " << b << " " << c << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}