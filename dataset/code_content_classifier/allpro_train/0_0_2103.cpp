#include <iostream>
#include <vector>
#include <unordered_set>

const long long MOD = 998244353;

std::vector<std::pair<int, int>> edges;
std::vector<int> colors;
std::unordered_set<int> red_edges;

void update_colors() {
    colors.assign(edges.size(), 0);
    for (int i : red_edges) {
        colors[i] = 1;
    }
}

long long calculate_hash() {
    long long hash = 0;
    for (int i : red_edges) {
        hash = (hash + (1LL << i) % MOD) % MOD;
    }
    return hash;
}

int main() {
    int n1, n2, m;
    std::cin >> n1 >> n2 >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        edges.emplace_back(x, y);
    }

    int q;
    std::cin >> q;

    while (q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int v1, v2;
            std::cin >> v1 >> v2;
            edges.emplace_back(v1, v2);
            red_edges.insert(edges.size() - 1);
            update_colors();
            std::cout << calculate_hash() << std::endl;
            std::cout.flush();
        } else {
            update_colors();
            std::cout << red_edges.size();
            for (int i : red_edges) {
                std::cout << " " << i + 1;
            }
            std::cout << std::endl;
            std::cout.flush();
        }
    }

    return 0;
}