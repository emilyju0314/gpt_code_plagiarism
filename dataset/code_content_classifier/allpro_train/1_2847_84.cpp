#include <bits/stdc++.h>
using namespace std;

using graph = std::vector<vector<int>>;

using ll = long long;
constexpr ll MOD = 1e9+7;

void add_edge(graph& g, int from, int to) {
    g[from].push_back(to);
}

int scc(graph& g, std::vector<int>& cmp) {
    int V = g.size();
    std::vector<vector<int>> rg(V);
    std::vector<bool> used(V, false);
    std::vector<int> vs;
    cmp.resize(V);
    for(int i=0; i<V; ++i) {
        for(auto to : g[i]) {
            rg[to].push_back(i);
        }
    }
    std::function<void(int)> dfs = [&g, &vs, &used, &dfs](int v) {
        used[v] = true;
        for(auto i : g[v]) {
            if(!used[i]) {
                dfs(i);
            }
        }
        vs.push_back(v);
    };
    std::function<void(int, int)> rdfs = [&rg, &cmp, &used, &rdfs](int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for(int i : rg[v]) {
            if(!used[i]) {
                rdfs(i, k);
            }
        }
    };
    for(int v=0; v<V; ++v) {
        if(!used[v]) {
            dfs(v);
        }
    }
    std::fill(used.begin(), used.end(), false);
    int k = 0;
    for(int i=vs.size()-1; i>=0; --i) {
        if(!used[vs[i]]) {
            rdfs(vs[i], k++);
        }
    }
    return k;
}

vector<vector<int>> build_graph(graph const& g, vector<int> const& cmp, int K) {
    int V = g.size();
    std::vector<std::set<int>> s(K);
    std::vector<std::vector<int>> res(K);
    for(int i=0; i<V; ++i) {
        for(auto to : g[i]) {
            s[cmp[i]].insert(cmp[to]);
        }
    }
    for(int i=0; i<K; ++i) {
        for(auto j : s[i]) {
            if(i != j) {
                res[i].push_back(j);
            }
        }
    }
    return res;
}


ll solve(int v, graph& g) {
    if(g[v].size() == 0) {
        return 2;
    }
    ll res = 1;
    for(auto to : g[v]) {
        res = (res*solve(to, g)) % MOD;
    }
    res += 1;
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    graph g(N);
    for(int i=0; i<M; ++i) {
        int s, d;
        cin >> s >> d;
        s--; d--;
        add_edge(g, s, d);
    }
    vector<int> cmp;
    int K = scc(g, cmp);
    g = build_graph(g, cmp, K);
    graph rg(K);
    for(int i=0; i<g.size(); ++i) {
        for(int j=0; j<g[i].size(); ++j) {
            rg[g[i][j]].push_back(i);
        }
    }
    ll res = 1;
    for(int i=0; i<K; ++i) {
        if(g[i].size() == 0) {
            res = (res*solve(i, rg)) % MOD;
        }
    }
    cout << res << endl;
}
