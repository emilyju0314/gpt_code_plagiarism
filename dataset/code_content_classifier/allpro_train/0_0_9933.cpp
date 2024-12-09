#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (1LL * res * x) % MOD;
        }
        x = (1LL * x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> s1(n), s2(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s1[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> s2[i];
    }

    int cnt = 0, total = 1;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 0 && s2[i] == 0) {
            cnt = (cnt + 1) % MOD;
            total = (2LL * total) % MOD;
        } else if (s1[i] == 0) {
            cnt = (cnt + (m - s2[i])) % MOD;
        } else if (s2[i] == 0) {
            cnt = (cnt + s1[i] - 1) % MOD;
        } else if (s1[i] > s2[i]) {
            cnt = (cnt + 1) % MOD;
        } else if (s2[i] > s1[i]) {
            total = (2LL * total) % MOD;
        }
    }

    int inv_total = power(total, MOD - 2);
    int answer = (1LL * cnt * inv_total) % MOD;

    std::cout << answer << std::endl;

    return 0;
}