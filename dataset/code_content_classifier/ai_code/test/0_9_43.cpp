#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> enjoyment(MAXN);
vector<pair<int, int>> adj[MAXN];

pair<int, int> dfs(int node, int parent, int maxEnjoyment, int maxToll) {
    pair<int, int> result = {enjoyment[node], 0};
    if (parent != -1) {
        result.second = max(maxToll, maxEnjoyment);
    }
    for (auto& edge : adj[node]) {
        int child = edge.first;
        int edgeCapacity = edge.second;
        if (child == parent) continue;
        if (edgeCapacity >= maxEnjoyment) {
            auto childResult = dfs(child, node, edgeCapacity, edge.second);
            result.first = max(result.first, childResult.first);
            result.second = max(result.second, childResult.second);
        }
    }
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> enjoyment[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        
        auto result = dfs(x, -1, 0, 0);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}