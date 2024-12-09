#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int x, int y, vector<int>& parent) {
    int px = findParent(x, parent);
    int py = findParent(y, parent);
    if (px != py) {
        parent[px] = py;
    }
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> colors(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> colors[i];
    }

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<vector<Edge>> graph(K + 1);
    for (int i = 0; i < M; i++) {
        int u = colors[edges[i].u];
        int v = colors[edges[i].v];

        if (u != 0 && v != 0 && u != v) {
            graph[u].push_back({u, v, edges[i].w});
            graph[v].push_back({v, u, edges[i].w});
        }
    }

    long long totalLength = 0;
    for (int i = 1; i <= K; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);

        vector<int> parent(K + 1);
        for (int j = 1; j <= K; j++) {
            parent[j] = j;
        }

        long long sum = 0;
        for (Edge edge : graph[i]) {
            if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
                unionSet(edge.u, edge.v, parent);
                sum += edge.w;
            }
        }

        if (sum == 0 && !graph[i].empty()) {
            cout << -1 << endl;
            return 0;
        }

        totalLength += sum;
    }

    cout << totalLength << endl;

    return 0;
}