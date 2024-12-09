#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long max_val = *std::max_element(a.begin(), a.end());
        std::unordered_map<long long, int> count_map;

        for (int i = 0; i < n; ++i) {
            if (a[i] == max_val && (i == 0 || a[i - 1] < max_val)) {
                count_map[max_val]++;
            }
        }

        std::cout << count_map[max_val] << std::endl;
    }

    return 0;
}