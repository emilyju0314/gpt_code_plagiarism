#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

int z(std::vector<int>& a, int k) {
    if (a.size() < k) {
        return 0;
    } else {
        std::vector<int> b;
        int ans = 0;
        for (int i = 0; i <= a.size() - k; ++i) {
            int temp = a[i];
            for (int j = i; j < i + k; ++j) {
                temp = std::max(temp, a[j]);
            }
            b.push_back(temp);
            ans = (ans + temp) % MOD;
        }
        return (ans + z(b, k)) % MOD;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int result = z(a, k);
    std::cout << result << std::endl;

    return 0;
}