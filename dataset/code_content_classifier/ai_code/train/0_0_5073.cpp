#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;
int totalCost = 0;
int totalProbability = 0;

void dfs(int u, int parent, int cost, int probability) {
    bool isLeaf = true;
    for (auto child : adj[u]) {
        if (child.first != parent) {
            isLeaf = false;
            dfs(child.first, u, child.second, probability);
        }
    }

    if (isLeaf) {
        totalCost += cost * probability;
        totalProbability += probability;
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(0, -1, 0, 1);

    cout << totalCost / totalProbability << endl;

    return 0;
}