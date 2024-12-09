#include <iostream>
#include <vector>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::pair<int, int> find_primes(int m, int a, int b) {
    std::vector<int> primes;
    for (int i = 2; i <= m; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }

    int max_area = 0;
    std::pair<int, int> result;

    for (int p : primes) {
        for (int q : primes) {
            if (p * q <= m && double(a) / b <= double(p) / q && double(p) / q <= 1) {
                if (p * q > max_area) {
                    max_area = p * q;
                    result = {p, q};
                }
            }
        }
    }

    return result;
}

int main() {
    int m, a, b;
    while (true) {
        std::cin >> m >> a >> b;
        if (m == 0 && a == 0 && b == 0) {
            break;
        }

        std::pair<int, int> primes = find_primes(m, a, b);
        std::cout << primes.first << " " << primes.second << "\n";
    }

    return 0;
}