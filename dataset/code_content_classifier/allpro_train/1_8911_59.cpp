#include <bits/stdc++.h>

using namespace std;

namespace {
    int V, E;
    int S, T;

    struct Edge {
        int from, to, cap, rev, index;
        Edge() {}
        Edge(int from, int to, int index, int cap, int rev) : from(from), to(to), index(index), cap(cap), rev(rev) {}
    };
    vector< vector<Edge> > G;
    vector<bool> used;
    void init() {
        G.clear(); G.resize(V);
        used.clear(); used.resize(V);
    }
    void addEdge(int from, int to, int index) {
        G[from].push_back(Edge(from, to, index, 1, G[to].size()));
        G[to].push_back(Edge(to, from, index, 1, int(G[from].size()) - 1));
    }
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            Edge& e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, 1e9);
            if (f == 0) return flow;
            flow += f;
        }
    }

    vector< vector<bool> > U;
    void input() {
        cin >> V >> E;
        init();
        U.clear(); U.resize(V, vector<bool>(V, false));
        for (int i = 0; i < E; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            U[x][y] = true;
            addEdge(x, y, i);
        }
        cin >> S >> T;
        S--; T--;
    }

    void solve() {
        cout << maxflow(S, T) << endl;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                Edge& e = G[i][j];
                if (e.cap == 0 && U[e.to][e.from]) {
                    ans.push_back(e.index);
                }
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}