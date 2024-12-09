#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> count(m+1, 0);

    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        count[l]++;
        count[r+1]--;
    }

    int prefix_sum = 0;
    int max_prefix_sum = 0;

    for (int i = 1; i <= m; ++i) {
        prefix_sum += count[i];
        max_prefix_sum = std::max(max_prefix_sum, prefix_sum);
    }

    std::cout << max_prefix_sum << std::endl;

    return 0;
}