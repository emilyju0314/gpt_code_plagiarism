#include <bits/stdc++.h>
using namespace std;

template<class E, class T> struct Rerooting {
    using F = function<T(T, T)>;
    using H = function<T(T, E)>;
private : 
    struct Edge {
        int to;
        E data;
        T dp, sum;
        Edge (int to, E data, T dp, T sum) : 
            to(to), data(data), dp(dp), sum(sum) { }
    };
    vector<vector<Edge>> g;
    vector<T> subdp, dp;
    const T id;
    const F f;
    const H h;
    int edges;

public : 
    Rerooting (int n, const F &f, const H &h, const T id) : 
        g(n), f(f), h(h), id(id), subdp(n, id), dp(n, id) { edges = 0; }

    void add_edge (int v, int u, const E &val) {
        assert(++edges < (int)g.size());
        g[v].emplace_back(u, val, id, id);
        g[u].emplace_back(v, val, id, id);
    }

    void add_edge2 (int v, int u, const E &val1, const E &val2) {
        assert(++edges < (int)g.size());
        g[v].emplace_back(u, val1, id, id);
        g[u].emplace_back(v, val2, id, id);
    }

    void dfs1 (int v, int p) {
        for (const auto &e : g[v]) {
            if (e.to == p) continue;
            dfs1(e.to, v);
            subdp[v] = f(subdp[v], h(subdp[e.to], e.data));
        }
    }

    void dfs2 (int v, int p, const T &top) {
        T buff = id;
        for (int i = 0; i < (int)g[v].size(); i++) {
            Edge &e = g[v][i];
            e.sum = buff;
            e.dp = h(e.to == p ? top : subdp[e.to], e.data);
            buff = f(buff, e.dp);
        }
        dp[v] = buff;
        buff = id;
        for (int i = (int)g[v].size() - 1; i >= 0; i--) {
            Edge &e = g[v][i];
            if (e.to != p) dfs2(e.to, v, f(buff, e.sum));
            e.sum = f(e.sum, buff);
            buff = f(buff, e.dp);
        }
    }

    vector<T> build(int s = 0) {
        dfs1(s, -1);
        dfs2(s, -1, id);
        return dp;
    }

};


int main() {
    int n;
    cin >> n;
    
    auto f = [](int a, int b) { return max(a, b); };
    auto h = [](int a, int b) { return a + b; };
    Rerooting<int, int> g(n, f, h, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g.add_edge(--a, --b, 1);
    }
    
    for (const auto &e : g.build()) {
        cout << (n - 1) * 2 - e << endl;
    }
    return 0;
}
