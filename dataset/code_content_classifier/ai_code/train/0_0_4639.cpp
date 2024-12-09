#include <iostream>
#include <vector>
#include <unordered_set>

int minNumberOfTrees(int n, int k, std::vector<std::pair<int, int>> pairs, int l, int r) {
    std::unordered_set<int> friends;
    for (auto pair : pairs) {
        if ((pair.first < l || pair.first > r) && (pair.second < l || pair.second > r)) {
            continue;
        }
        friends.insert(pair.first);
        friends.insert(pair.second);
    }
    return friends.size();
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int m;
    std::cin >> m;

    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        pairs.push_back({u, v});
    }

    int q;
    std::cin >> q;

    std::vector<std::pair<int, int>> situations;
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        situations.push_back({l, r});
    }

    for (auto situation : situations) {
        int answer = minNumberOfTrees(n, k, pairs, situation.first, situation.second);
        std::cout << answer << std::endl;
    }

    return 0;
}