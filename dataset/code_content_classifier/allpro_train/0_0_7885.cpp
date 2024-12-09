#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w, idx;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    vector<vector<int>> adjList(n + 1);
    vector<bool> good(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].idx = i + 1;
        adjList[edges[i].u].push_back(i);
        adjList[edges[i].v].push_back(i);
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> ans;
    for (int i = 0; i < k; i++) {
        good.assign(n + 1, false);

        // DFS from vertex 1 to mark good vertices
        vector<bool> visited(n + 1, false);
        vector<int> stack;
        stack.push_back(1);
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            good[u] = true;
            visited[u] = true;
            for (int idx : adjList[u]) {
                int v = (edges[idx].u == u) ? edges[idx].v : edges[idx].u;
                if (!visited[v]) {
                    stack.push_back(v);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            if (!good[j]) {
                ans.push_back(edges[i].idx);
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << " ";
    }

    return 0;
}