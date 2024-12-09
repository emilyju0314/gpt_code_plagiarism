#include <iostream>
#include <vector>
#include <string>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> dominoes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dominoes[i];
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (dominoes[i] == "??" || (dominoes[i][0] == '?' && dominoes[i][1] == '?')) {
            ans = (ans * 2) % MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dominoes[i][0] == 'W' && dominoes[(i + 1) % n][1] == 'W') {
            std::cout << "0\n";
            return 0;
        }
        if (dominoes[i][1] == 'W' && dominoes[(i + 1) % n][0] == 'W') {
            std::cout << "0\n";
            return 0;
        }
        if (dominoes[i][0] == 'B' && dominoes[(i + 1) % n][1] == 'B') {
            std::cout << "0\n";
            return 0;
        }
        if (dominoes[i][1] == 'B' && dominoes[(i + 1) % n][0] == 'B') {
            std::cout << "0\n";
            return 0;
        }
    }

    std::cout << ans << "\n";

    return 0;
}