#include <iostream>
#include <vector>
using namespace std;

vector<int> numChildren;
vector<vector<int>> adjList;

void dfs(int u, int parent) {
    for (int v : adjList[u]) {
        if (v != parent) {
            dfs(v, u);
            numChildren[u] += numChildren[v];
        }
    }
}

int main() {
    int n;
    cin >> n;

    numChildren.resize(n + 1);
    adjList.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(1, 0);

    int q;
    cin >> q;

    while (q--) {
        int v, k;
        cin >> v >> k;

        int maxScore = numChildren[v] - k;
        if (v != 1) {
            maxScore = max(maxScore, numChildren[1] - k - 1);
        }

        cout << maxScore << "\n";
    }

    return 0;
}