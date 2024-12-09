#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        std::cin >> colors[i];
    }

    std::unordered_map<int, std::unordered_map<int, bool>> edgeExists;
    std::unordered_map<int, int> neighborColorsCount;

    for(int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if(a != b) {
            edgeExists[colors[a-1]][colors[b-1]] = true;
            edgeExists[colors[b-1]][colors[a-1]] = true;
        }
    }

    int maxNeighborColors = -1;
    int bestColor = -1;

    for(const auto& entry : edgeExists) {
        int color = entry.first;
        int count = entry.second.size();
        if(count > maxNeighborColors || (count == maxNeighborColors && color < bestColor)) {
            maxNeighborColors = count;
            bestColor = color;
        }
    }

    std::cout << bestColor << std::endl;

    return 0;
}