#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> puzzles(m);
    for (int i = 0; i < m; i++) {
        std::cin >> puzzles[i];
    }

    std::sort(puzzles.begin(), puzzles.end());

    int min_diff = puzzles[n-1] - puzzles[0];
    for (int i = 1; i <= m - n; i++) {
        min_diff = std::min(min_diff, puzzles[i + n - 1] - puzzles[i]);
    }

    std::cout << min_diff << std::endl;

    return 0;
}