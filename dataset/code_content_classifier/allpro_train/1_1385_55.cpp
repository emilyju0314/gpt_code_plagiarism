#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

using edge = PII;
struct dynamicConnectivity {
    int n, sz;
    vector<ll> ans;
    vector<vector<edge>> edges;

    vector<pair<PII, edge>> pending;
    map<edge, int> cnt, appear;

    // セグ木に追加
    void update(int a, int b, const edge &e, int k, int l, int r) {
        if(r <= a || b <= l) return;
        if(a <= l && r <= b) {
            edges[k].emplace_back(e);
            return;
        }
        update(a, b, e, 2*k+1, l, (l+r)/2);
        update(a, b, e, 2*k+2, (l+r)/2, r);
    }
    void update(int a, int b, const edge &e) { update(a, b, e, 0, 0, sz); }

    dynamicConnectivity(int n, int q) : n(q), ans(q) {
        sz = 1;
        while(sz < q) sz <<= 1;
        edges.resize(2 * sz - 1);
    }
    // idx番目のクエリで辺eを追加/削除する
    void insert(int idx, edge e) {
        if(e.first > e.second) swap(e.first, e.second);
        if(cnt[e]++ == 0) appear[e] = idx;
    }
    void erase(int idx, edge e) {
        if(e.first > e.second) swap(e.first, e.second);
        if(--cnt[e] == 0) pending.emplace_back(PII(appear[e], idx), e);
    }
    // クエリを変換してセグ木に追加する
    void build() {
        for(auto &p : cnt) if(p.second > 0) {
            pending.emplace_back(PII(appear[p.first], sz), p.first);
        }
        for(auto &s : pending) update(s.first.first, s.first.second, s.second);
    }
    // セグ木上を探索
    void execute(function<void(ll)> f, function<void(edge)> add, function<void(void)> undo, int k = 0) {
        for(auto &e : edges[k]) add(e);
        if(k < sz-1) {
            execute(f, add, undo, 2*k+1);
            execute(f, add, undo, 2*k+2);
        } else if(k-sz+1 < n) {
            // 時刻k-sz+1での処理
            f(k-sz+1);
        }
        REP(i, edges[k].size()) undo();
    }
};

struct UnionFind {
    vector<int> data;
    stack<PII> st;

    UnionFind(int sz) : data(sz, -1) {}

    int find(int k) {
        if(data[k] < 0) return (k);
        return (find(data[k]));
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        st.emplace(x, data[x]);
        st.emplace(y, data[y]);
        if(x == y) return;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }
    void undo() {
        data[st.top().first] = st.top().second;
        st.pop();
        data[st.top().first] = st.top().second;
        st.pop();
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int k) { return (-data[find(k)]); }
};

int main(void) {
    ll n, q;
    cin >> n >> q;
    dynamicConnectivity dc(n, q);
    vector<ll> t(q), u(q), v(q);
    REP(i, q) {
        cin >> t[i] >> u[i] >> v[i];
        if(t[i] == 1) dc.insert(i, {u[i], v[i]});
        else if(t[i] == 2) dc.erase(i, {u[i], v[i]});
    }
    dc.build();

    UnionFind uf(n);
    auto add = [&](edge e) {
        uf.unite(e.first, e.second);
    };
    auto undo = [&] {
        uf.undo();
    };
    auto f = [&](ll x) {
        if(x < q && t[x] == 3) {
            cout << (uf.same(u[x], v[x]) ? "YES" : "NO") << endl;
        }
    };
    dc.execute(f, add, undo);

    return 0;
}
