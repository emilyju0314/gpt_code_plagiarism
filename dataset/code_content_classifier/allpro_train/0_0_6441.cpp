#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList1, adjList2, adjList3;
vector<int> subtreeSize1, subtreeSize2, subtreeSize3;
long long ans;

void calculateSubtreeSizes(int u, int parent, vector<vector<int>>& adjList, vector<int>& subtreeSize) {
    subtreeSize[u] = 1;
    for (int v : adjList[u]) {
        if (v != parent) {
            calculateSubtreeSizes(v, u, adjList, subtreeSize);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

void calculateDistances(int u, int parent, const vector<vector<int>>& adjList, const vector<int>& subtreeSize, long long& ans) {
    for (int v : adjList[u]) {
        if (v != parent) {
            ans += 2LL * min(subtreeSize[v], subtreeSize1[1] - subtreeSize[v]) * min(subtreeSize[u], subtreeSize2[1]);
            calculateDistances(v, u, adjList, subtreeSize, ans);
        }
    }
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    adjList1.resize(n1 + 1);
    for (int i = 1; i < n1; i++) {
        int u, v;
        cin >> u >> v;
        adjList1[u].push_back(v);
        adjList1[v].push_back(u);
    }

    adjList2.resize(n2 + 1);
    for (int i = 1; i < n2; i++) {
        int u, v;
        cin >> u >> v;
        adjList2[u].push_back(v);
        adjList2[v].push_back(u);
    }

    adjList3.resize(n3 + 1);
    for (int i = 1; i < n3; i++) {
        int u, v;
        cin >> u >> v;
        adjList3[u].push_back(v);
        adjList3[v].push_back(u);
    }

    subtreeSize1.resize(n1 + 1);
    subtreeSize2.resize(n2 + 1);
    subtreeSize3.resize(n3 + 1);

    calculateSubtreeSizes(1, -1, adjList1, subtreeSize1);
    calculateSubtreeSizes(1, -1, adjList2, subtreeSize2);
    calculateSubtreeSizes(1, -1, adjList3, subtreeSize3);

    ans = 0LL;
    calculateDistances(1, -1, adjList1, subtreeSize1, ans);
    calculateDistances(1, -1, adjList2, subtreeSize2, ans);
    calculateDistances(1, -1, adjList3, subtreeSize3, ans);

    cout << ans << endl;

    return 0;
}