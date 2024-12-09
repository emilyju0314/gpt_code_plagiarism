#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

const ll MOD = 1000000007;

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        if (x < 0) {
            w[-x - 1] = y;
        } else {
            x--, y--;

            ll total_energy = 0;
            int left = a[x], right = a[y];

            std::vector<int> weights_sorted(w.begin() + x, w.begin() + y + 1);
            std::sort(weights_sorted.begin(), weights_sorted.end());

            for (int i = x; i <= y; i++) {
                int idx = std::lower_bound(weights_sorted.begin(), weights_sorted.end(), w[i]) - weights_sorted.begin();
                total_energy = (total_energy + 1ll * (std::abs(a[i] - left) + std::abs(a[i] + y - right)) % MOD * weights_sorted[idx] % MOD) % MOD;
            }

            std::cout << total_energy << "\n";
        }
    }

    return 0;
}