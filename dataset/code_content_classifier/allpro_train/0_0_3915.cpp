#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> strengths(n);
        for (int j = 0; j < n; j++) {
            std::cin >> strengths[j];
        }

        std::sort(strengths.begin(), strengths.end());

        int min_diff = INT_MAX;
        for (int j = 1; j < n; j++) {
            min_diff = std::min(min_diff, strengths[j] - strengths[j-1]);
        }

        std::cout << min_diff << std::endl;
    }

    return 0;
}