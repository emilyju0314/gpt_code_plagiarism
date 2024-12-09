#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, M;
    std::cin >> n >> k >> M;

    std::vector<int> t(k);
    for (int i = 0; i < k; i++) {
        std::cin >> t[i];
    }

    std::sort(t.begin(), t.end());

    int maxPoints = 0;

    for (int solvedSubtasks = 0; solvedSubtasks <= n * k; solvedSubtasks++) {
        int timeRemaining = M;
        int points = 0;

        for (int i = 0; i < k; i++) {
            if (solvedSubtasks * t[i] <= timeRemaining) {
                points = solvedSubtasks + solvedSubtasks / k;
            }
        }

        maxPoints = std::max(maxPoints, points);
    }

    std::cout << maxPoints << std::endl;

    return 0;
}