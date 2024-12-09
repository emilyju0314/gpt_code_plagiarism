#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    std::vector<long long> b(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<long long> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    std::sort(diff.begin(), diff.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::abs(diff[i] - diff[n/2]);
    }

    std::cout << ans << std::endl;

    return 0;
}