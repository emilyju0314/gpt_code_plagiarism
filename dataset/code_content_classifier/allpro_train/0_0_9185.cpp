#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<pair<int,int>>> adjList;
vector<bool> lucky;
vector<long long> subtreeSize;
long long totalTriplets = 0;

void dfs(int v, int p) {
    subtreeSize[v] = 1;
    for (pair<int,int> u : adjList[v]) {
        if (u.first != p) {
            dfs(u.first, v);
            subtreeSize[v] += subtreeSize[u.first];
            if (lucky[u.second]) {
                totalTriplets += 2 * subtreeSize[u.first] * (adjList.size() - subtreeSize[u.first]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    adjList.resize(n + 1);
    lucky.assign(n + 1, false);
    subtreeSize.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        if (w == 4 || w == 7) {
            lucky[w] = true;
        }
    }

    dfs(1, 0);

    cout << totalTriplets << endl;

    return 0;
}