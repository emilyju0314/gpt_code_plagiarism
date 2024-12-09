#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int numBlack = 0;
    for (char c : S) {
        if (c == 'B') {
            numBlack++;
        }
    }

    if (numBlack % 2 != 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    std::vector<long long> fact(2*N+1);
    fact[0] = 1;
    for (int i = 1; i <= 2*N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    long long ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * (2*N-i)) % MOD;
        ans = (ans * modInverse(i+1, MOD)) % MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}