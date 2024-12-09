#include <iostream>
#include <vector>

using namespace std;

struct Friend {
    int index;
    int cost;
};

vector<vector<Friend>> adjList;
vector<int> visitCount;
int maxCost = 0;
int k;

void dfs(int node, int parent, int totalCost) {
    visitCount[node]++;
    if (visitCount[node] > k) {
        return;
    }

    for (Friend friend : adjList[node]) {
        if (friend.index != parent) {
            dfs(friend.index, node, totalCost + friend.cost);
        }
    }

    maxCost = max(maxCost, totalCost);
}

int main() {
    int n;
    cin >> n >> k;

    adjList.resize(n);
    visitCount.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }

    dfs(0, -1, 0);

    cout << maxCost << endl;

    return 0;
}