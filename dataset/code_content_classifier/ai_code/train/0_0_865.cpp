#include <iostream>
#include <vector>

const int MOD = 998244353;

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % MOD;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    std::vector<long long> powers(N);
    for (int i = 0; i < N; i++) {
        powers[i] = power(X[i], i + 1);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum = (sum + powers[i]) % MOD;
    }

    std::cout << sum << std::endl;

    return 0;
}