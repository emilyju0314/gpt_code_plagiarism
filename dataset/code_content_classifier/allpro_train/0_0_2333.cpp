#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;

    while (std::cin >> n && n != 0) {
        std::vector<int> scores(n);
        for (int i = 0; i < n; i++) {
            std::cin >> scores[i];
        }

        std::sort(scores.begin(), scores.end());

        int minDifference = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDifference = std::min(minDifference, scores[i] - scores[i - 1]);
        }

        std::cout << minDifference << std::endl;
    }

    return 0;
}