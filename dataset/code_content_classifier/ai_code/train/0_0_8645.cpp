#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> lengths(n+1);
        for (int i = 0; i <= n; ++i) {
            std::cin >> lengths[i];
        }

        std::vector<int> diffs;
        for (int i = 0; i < n; ++i) {
            diffs.push_back(lengths[i+1] - lengths[i]);
        }

        int common_diff = *std::min_element(diffs.begin(), diffs.end());
        int weed_length_index = std::find(diffs.begin(), diffs.end(), common_diff) - diffs.begin();

        std::cout << lengths[weed_length_index] + common_diff << std::endl;
    }

    return 0;
}