#include <iostream>

#define MOD 1000000007

int main() {
    long long N, k;
    std::cin >> N >> k;

    long long result = 1;

    for(int i = 1; i <= N; i++) {
        result = (result + (i * k) % MOD) % MOD;
    }

    std::cout << result;

    return 0;
}