#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> x(n);
        for(int i = 0; i < n; ++i) {
            std::cin >> x[i];
        }

        std::sort(x.begin(), x.end());

        long long min_distance = 0;
        for(int i = n-1; i >= k; i -= k) {
            min_distance += 2LL * std::abs(x[i]);
        }

        long long remaining_distance = 0;
        for(int i = i % k; i >= 0; --i) {
            remaining_distance += std::abs(x[i]);
        }

        min_distance += remaining_distance;

        std::cout << min_distance << std::endl;
    }

    return 0;
}