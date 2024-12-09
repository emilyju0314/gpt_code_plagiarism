#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 250005;

int N, M;
int parent[MAXN], size[MAXN];
int numCycles;
bool isCycle[MAXN];

int findSet(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    if (pu == pv) {
        numCycles++;
        isCycle[pu] = true;
    } else {
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    long long totalPairs = (long long)M * (M + 1) / 2; // Total number of pairs

    vector<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        
        edges.push_back({u, v});
    }

    numCycles = 0;
    fill(isCycle, isCycle + MAXN, false);

    for (int i = 0; i < M; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        unionSets(u, v);

        if (numCycles == 0) {
            totalPairs -= i + 1;
        } else if (isCycle[findSet(u)]) {
            numCycles--;
        }
    }

    cout << totalPairs << endl;

    return 0;
}