#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<long long> count(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        count[l - 1]++;
        count[r]--;
    }

    for (int i = 1; i <= n; i++) {
        count[i] += count[i - 1];
    }

    std::sort(a.begin(), a.end());
    std::sort(count.begin(), count.end() - 1);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * a[i] * count[i];
    }

    std::cout << ans << std::endl;

    return 0;
}