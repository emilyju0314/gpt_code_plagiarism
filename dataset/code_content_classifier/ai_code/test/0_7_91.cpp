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

        long long result = 0;
        for (int i = 0; i < n; i++) {
            int left = i, right = i + 1;
            long long sum = 0;
            int minimum = a[i];
            while (left >= 0 && right <= n) {
                minimum = std::min(minimum, a[right - 1]);
                sum = (sum + minimum) % MOD;
                result = (result + sum) % MOD;
                left--;
                right++;
            }
        }
        std::cout << result << std::endl;
    }

    return 0;
}