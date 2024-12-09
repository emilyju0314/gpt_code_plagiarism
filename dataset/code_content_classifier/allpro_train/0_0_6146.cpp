#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> shopLocations;

int dfs(int node, int parent, int limit) {
    int maxDist = 0;
    bool isShop = false;

    for (auto& neighbor : graph[node]) {
        if (neighbor.first != parent) {
            int dist = dfs(neighbor.first, node, limit) + neighbor.second;
            maxDist = max(maxDist, dist);

            if (dist >= limit) {
                isShop = true;
            }
        }
    }

    if (isShop) {
        shopLocations.push_back(node);
        return 0;
    }

    return maxDist;
}

bool isValid(int limit, int k) {
    shopLocations.clear();
    dfs(1, -1, limit);

    if (shopLocations.size() <= k) {
        return true;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    int l = 0, r = 1e9; // define range for binary search

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (isValid(mid, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}