#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 998244353;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int mod_inverse(int x) {
    int result = 1;
    int power = MOD - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        power /= 2;
    }
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> likes(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> likes[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    std::vector<int> numerator(n, 0);
    std::vector<int> denominator(n, 0);

    for (int i = 0; i < n; ++i) {
        denominator[likes[i]] += weights[i];
    }

    int total_denominator = 0;
    for (int i = 0; i < n; ++i) {
        total_denominator += denominator[i];
    }

    for (int i = 0; i < n; ++i) {
        numerator[likes[i]] += weights[i] * total_denominator - weights[i] * denominator[likes[i]];
        denominator[likes[i]] = total_denominator;
    }

    for (int i = 0; i < n; ++i) {
        int g = gcd(numerator[i], denominator[i]);

        int q_i = numerator[i] / g;
        int p_i = denominator[i] / g;

        int r_i = (q_i % MOD) * mod_inverse(p_i) % MOD;
        if (r_i < 0) {
            r_i += MOD;
        }

        std::cout << r_i << " ";
    }

    std::cout << std::endl;

    return 0;
}