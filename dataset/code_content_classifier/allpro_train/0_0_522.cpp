#include <iostream>
#include <vector>

const int MOD = 998244353;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> likes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> likes[i];
    }
    
    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += weights[i];
    }

    for (int k = 1; k <= m; k++) {
        int new_sum = 0;
        for (int i = 0; i < n; i++) {
            if (likes[i] == 1) {
                weights[i] = (total_sum - weights[i] + MOD) % MOD;
            }
            new_sum = (new_sum + weights[i]) % MOD;
        }
        total_sum = new_sum;
    }

    int total_inv = power(total_sum, MOD - 2);
    for (int i = 0; i < n; i++) {
        int result = (weights[i] * total_inv) % MOD;
        std::cout << result << std::endl;
    }

    return 0;
}