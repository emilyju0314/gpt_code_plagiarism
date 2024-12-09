#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        long long ans = 0;
        std::vector<int> count(n, 1);

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                count[i] = count[i-1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int left = count[i];
            int right = count[n-1-i];
            ans = (ans + 1LL * left * right % MOD) % MOD;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}