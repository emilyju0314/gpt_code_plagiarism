#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2.5 * 1e5 + 5;

int N, M;
vector<int> adj[MAX_N], parent(MAX_N, -1), rankArr(MAX_N, 0), cycleSize(MAX_N, 0);
int answer = 0;

int find(int u) {
    if (u == parent[u]) {
        return u;
    } else {
        return parent[u] = find(parent[u]);
    }
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (rankArr[u] < rankArr[v]) {
            swap(u, v);
        }

        parent[v] = u;
        rankArr[u] += rankArr[v];
        cycleSize[u] = max({cycleSize[u], cycleSize[v], (rankArr[v] + 1) / 2 + (rankArr[u] + 1) / 2 + 1});
    }
}

bool findCycle(int u, int p) {
    parent[u] = p;
    
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        if (parent[v] != -1) {
            int cur = u;
            vector<int> cycle = {cur};
            while (cur != v) {
                cur = parent[cur];
                cycle.push_back(cur);
            }

            int cycleSize = cycle.size();
            while (!cycle.empty()) {
                int node = cycle.back();
                cycle.pop_back();
                unite(node, u);
            }
            return true;
        } else {
            if (findCycle(v, u)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1 && findCycle(i, -1)) {
            answer += cycleSize[find(i)];
        }
    }

    cout << (M - answer) << endl;

    return 0;
}