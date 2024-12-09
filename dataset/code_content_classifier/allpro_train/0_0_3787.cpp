#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> parent;
vector<int> subtreeSize;
vector<int> result;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unify(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    
    if (pu != pv) {
        parent[pu] = pv;
        subtreeSize[pv] += subtreeSize[pu];
    }
}

int main() {
    cin >> N;
    parent.resize(N + 1);
    subtreeSize.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        subtreeSize[i] = 1;
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    sort(edges.begin(), edges.end());

    long long totalSum = 0;
    long long runningSum = 0;

    for (int i = 0; i < N - 1; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        int sizeU = subtreeSize[find(u)];
        int sizeV = subtreeSize[find(v)];

        totalSum += 1LL * sizeU * sizeV;

        runningSum += 1LL * sizeU * sizeV;
        result.push_back(runningSum);
        unify(u, v);
    }

    reverse(result.begin(), result.end());
    for (int i = 0; i < N - 1; i++) {
        totalSum += 2LL * result[i] * (N - 1 - i);
    }

    cout << totalSum + N << "\n";

    return 0;
}