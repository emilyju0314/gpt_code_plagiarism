#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> maxDistances;

int dfs(int u, int parent) {
    int maxDistance = 0;
    for (int v : graph[u]) {
        if (v != parent) {
            maxDistance = max(maxDistance, 1 + dfs(v, u));
        }
    }
    maxDistances[u] = maxDistance;
    return maxDistance;
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    maxDistances.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int maxProfit = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : graph[i]) {
            if (maxDistances[i] + maxDistances[j] + 1 != n) {
                int profit = maxDistances[i] * maxDistances[j];
                maxProfit = max(maxProfit, profit);
            }
        }
    }

    cout << maxProfit << endl;

    return 0;
}