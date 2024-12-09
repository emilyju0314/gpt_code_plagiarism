#include <iostream>
#include <vector>
#include <unordered_set>

bool canDrawMagicCircle(int n, int m, std::vector<std::pair<int, int>>& strings) {
    std::unordered_set<int> connectedStones;

    for (const auto& str : strings) {
        connectedStones.insert(str.first);
        connectedStones.insert(str.second);
    }

    return connectedStones.size() == n;
}

int main() {
    int n, m;

    while (true) {
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<std::pair<int, int>> strings;
        
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            strings.push_back({u, v});
        }

        if (canDrawMagicCircle(n, m, strings)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}