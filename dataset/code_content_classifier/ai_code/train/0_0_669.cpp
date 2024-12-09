#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adjList, reversedAdjList;
vector<int> disc, low, scc;
vector<bool> onStack;
vector<pair<int, int>> edges;

int N, M, timer = 0, SCC = 0;

void tarjanSCC(int u) {
    disc[u] = low[u] = ++timer;
    onStack[u] = true;
    for (int v : adjList[u]) {
        if (disc[v] == 0) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        SCC++;
        while (true) {
            int v = edges.back().first;
            edges.pop_back();
            scc[v] = SCC;
            onStack[v] = false;
            if (u == v) break;
        }
    }
}

int main() {
    cin >> N >> M;
    adjList.resize(N + 1);
    reversedAdjList.resize(N + 1);
    disc.resize(N + 1);
    low.resize(N + 1);
    scc.resize(N + 1);
    onStack.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        reversedAdjList[b].push_back(a);
        edges.push_back({a, b});
    }

    fill(disc.begin(), disc.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(scc.begin(), scc.end(), 0);
    fill(onStack.begin(), onStack.end(), false);

    for (int i = 1; i <= N; i++) {
        if (disc[i] == 0) {
            tarjanSCC(i);
        }
    }

    for (pair<int, int> edge : edges) {
        int u = edge.first, v = edge.second;
        if (scc[u] == scc[v]) {
            cout << "same" << endl;
        } else {
            cout << "diff" << endl;
        }
    }

    return 0;
}