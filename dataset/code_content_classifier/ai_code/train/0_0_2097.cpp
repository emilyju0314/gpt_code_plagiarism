#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int sum = 0;
        bool flag = false;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum % x != 0) {
                flag = true;
                ans = i+1;
            }
        }

        for (int i = n-1; i >= 0; i--) {
            sum -= a[i];
            if (sum % x != 0) {
                flag = true;
                ans = std::max(ans, n - i);
            }
        }

        if (!flag) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }

    return 0;
}