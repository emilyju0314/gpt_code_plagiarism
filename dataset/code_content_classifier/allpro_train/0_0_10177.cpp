#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    int x, y;
    std::cin >> x >> y;

    std::vector<std::pair<int, int>> maxPairs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> maxPairs[i].first >> maxPairs[i].second;
    }

    std::vector<std::pair<int, int>> minPairs(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> minPairs[i].first >> minPairs[i].second;
    }

    bool maxWins = true;
    bool minWins = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maxPairs[i].first > minPairs[j].first || maxPairs[i].second > minPairs[j].second) {
                minWins = true;
                break;
            }
        }
        if (minWins) {
            break;
        }
    }

    if (minWins) {
        std::cout << "Min" << std::endl;
    } else {
        std::cout << "Max" << std::endl;
    }

    return 0;
}