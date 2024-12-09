#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
template <typename T> T inf;
template <> const int inf<int> = 1e9;
template <> const ll inf<ll> = 1e18;
 
int N, K;
 
using graph = vector<vector<int>>;
 
int res = 0;
 
int dfs(graph const& g, int v, int p, vector<int>& sz) {
    sz[v] = 1;
    vector<pii> cnt;
    int cntK = 0;
    for(auto to : g[v]) {
        if(to == p) {
            continue;
        }
        cnt.push_back(make_pair(dfs(g, to, v, sz), to));
        sz[v] += sz[to];
        cntK += sz[to] >= K;
    }
    sort(cnt.rbegin(), cnt.rend());
 
    int par_size = N - sz[v];
    int t = 0;
    for(int i = 0; i < cnt.size(); ++i) {
        int ch = cnt[i].second;
        t = max(t, cnt[i].first + cntK - (sz[ch] >= K));
        res = max(res, t + (par_size >= K));
    }
 
    if(cnt.size() >= 2) {
        int t2 = cnt[0].first + cnt[1].first;
        t2 += cntK - (sz[cnt[0].second] >= K) - (sz[cnt[1].second] >= K) + (par_size >= K);
        res = max(res, t2);
    }
 
    t = max(t, cntK);
    return t;
}
 
int main() {
    cin >> N >> K;
    vector<vector<int>> g(N);
    for(int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
 
    vector<int> sz(N);
    dfs(g, 0, -1, sz);
    cout << res << endl;
}

