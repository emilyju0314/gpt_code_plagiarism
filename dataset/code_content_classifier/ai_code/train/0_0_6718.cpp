#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long totalDistance = 0;

void dfs(int node, int parent, vector<vector<int>>& adjList, vector<int>& cities, vector<int>& xorSum, vector<int>& count) {
    xorSum[node] = cities[node];
    count[node] = 1;

    for(int neighbor : adjList[node]) {
        if(neighbor == parent) continue;
        dfs(neighbor, node, adjList, cities, xorSum, count);
        xorSum[node] ^= xorSum[neighbor];
        count[node] += count[neighbor];
    }

    totalDistance += (long long)count[node] * (count[node] - (xorSum[node] ^ cities[node]));
}

int main() {
    int n;
    cin >> n;

    vector<int> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    vector<vector<int>> adjList(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> xorSum(n, 0);
    vector<int> count(n, 0);

    dfs(0, -1, adjList, cities, xorSum, count);

    cout << totalDistance << endl;

    return 0;
}