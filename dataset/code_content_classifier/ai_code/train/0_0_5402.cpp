#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int ans = a[n-1] - a[0];
    for (int i = 1; i <= k; i++) {
        int diff = a[n-i] - a[i-1];
        ans = std::min(ans, diff);
    }

    std::cout << ans << std::endl;

    return 0;
}