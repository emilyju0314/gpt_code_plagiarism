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
    int k;
    std::cin >> k;

    std::vector<int> colors(k);
    int total_balloons = 0;
    for (int i = 0; i < k; i++) {
        std::cin >> colors[i];
        total_balloons += colors[i];
    }

    int result = 1;
    for (int i = 0; i < k; i++) {
        int cnt = total_balloons - colors[i];
        result = (result * power(cnt + 1, MOD - 2)) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}