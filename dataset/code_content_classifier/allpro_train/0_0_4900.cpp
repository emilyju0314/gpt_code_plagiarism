#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int min_val = a[i], max_val = a[i];
        for (int j = i; j < n; j++) {
            min_val = std::min(min_val, a[j]);
            max_val = std::max(max_val, a[j]);
            ans += max_val - min_val;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}