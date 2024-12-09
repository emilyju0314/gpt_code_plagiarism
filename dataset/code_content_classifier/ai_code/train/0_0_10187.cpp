#include <iostream>
#include <string>
#include <cmath>

const int MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    std::string c, d;
    std::cin >> c >> d;
    int n;
    std::cin >> n;

    long long total_pairs = 1;
    long long total_flexibilities = 0;

    for (char qc : c) {
        for (char qd : d) {
            if (qc == '?' && qd == '?') {
                total_pairs = (total_pairs * 2) % MOD;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        long long curr_flex = power(2, i) - 1;
        curr_flex = (curr_flex * total_pairs) % MOD;
        total_flexibilities = (total_flexibilities + curr_flex) % MOD;
    }

    std::cout << total_flexibilities << std::endl;

    return 0;
}