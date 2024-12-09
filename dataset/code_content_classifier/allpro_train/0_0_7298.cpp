#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> containers(m);
    for (int i = 0; i < m; i++) {
        int ai, bi;
        std::cin >> ai >> bi;
        containers[i] = {ai, bi};
    }

    std::sort(containers.begin(), containers.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    int totalMatches = 0;
    for (int i = 0; i < m; i++) {
        if (n > 0) {
            int matchboxesToTake = std::min(n, containers[i].first);
            totalMatches += matchboxesToTake * containers[i].second;
            n -= matchboxesToTake;
        } else {
            break;
        }
    }

    std::cout << totalMatches << std::endl;

    return 0;
}