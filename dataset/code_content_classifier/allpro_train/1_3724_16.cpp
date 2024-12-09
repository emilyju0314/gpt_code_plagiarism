#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
template <class T>
ostream& operator<<(ostream& s, vector<T>& d) {
    REP(i, d.size()) s << d[i] << (i == d.size() - 1 ? "" : " ");
    return s;
}
using Int = long long;

struct DirectedGraph {
    struct Edge {
        Int to, cost;
    };
    vector<vector<Edge>> G;
    Int V;
    DirectedGraph(Int V_) : G(V_), V(V_) {}
    void add_edge(Int u, Int v, Int cost) { G[u].push_back({v, cost}); }
    vector<Int> dijkstra(Int s) {
        vector<Int> d(V, 1e18);
        d[s] = 0;
        using ii = pair<Int, Int>;
        priority_queue<ii, vector<ii>, greater<ii>> q;
        q.push({0, s});
        while (!q.empty()) {
            ii p = q.top();
            q.pop();
            Int v = p.second;
            if (d[v] < p.first) continue;
            for (auto& e : G[v]) {
                Int tmp = d[v] + e.cost;
                if (d[e.to] <= tmp) continue;
                d[e.to] = tmp;
                q.push({tmp, e.to});
            }
        }
        return d;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<Int> d(n);
    REP(i, n) cin >> d[i];
    DirectedGraph g(n);
    REP(i, n - 1) { g.add_edge(i + 1, i, 0); }
    REP(i, m) {
        Int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, d[b]);
    }
    auto dist = g.dijkstra(s);
    // cerr << dist << endl;
    cout << dist[t] << endl;
}

