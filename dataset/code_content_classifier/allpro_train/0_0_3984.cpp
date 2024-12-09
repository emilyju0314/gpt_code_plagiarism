#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> islanders;
vector<vector<int>> adjList;
vector<int> subtreeSizes, subtreeIslanders;
int totalCost = 0;

void dfs(int u, int parent) {
    subtreeSizes[u] = 1;
    subtreeIslanders[u] = islanders[u];

    for (int v : adjList[u]) {
        if (v != parent) {
            dfs(v, u);
            subtreeSizes[u] += subtreeSizes[v];
            subtreeIslanders[u] += subtreeIslanders[v];
            totalCost += abs(subtreeIslanders[v]);
        }
    }
}

int main() {
    cin >> N;
    islanders.resize(N);
    adjList.resize(N);

    subtreeSizes.resize(N);
    subtreeIslanders.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> islanders[i];
    }

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(0, -1);

    if (subtreeIslanders[0] != 0) {
        cout << -1 << endl;
    } else {
        cout << totalCost << endl;
    }

    return 0;
}