#include <iostream>
#include <vector>
#include <algorithm>

bool canColorVertex(std::vector<std::vector<int>>& graph, std::vector<int>& colors, int v, int c) {
    for (int u : graph[v]) {
        if (colors[u] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraph(std::vector<std::vector<int>>& graph, std::vector<int>& colors, int v) {
    if (v == colors.size()) {
        return true;
    }

    for (int c = 1; c <= 4; c++) {
        if (canColorVertex(graph, colors, v, c)) {
            colors[v] = c;
            if (colorGraph(graph, colors, v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }

    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> colors(n, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    colorGraph(graph, colors, 0);

    for (int i = 0; i < n; i++) {
        std::cout << colors[i] << "\n";
    }

    return 0;
}