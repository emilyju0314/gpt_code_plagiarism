#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct E {
    int to;
};

struct SCC {
    V<int> id;
    VV<int> groups;
};

template<class E>
struct SCC_EXEC {
    const VV<E> &g;
    int tm = 0;
    V<bool> inS;
    V<int> id, low, ord, st;
    VV<int> groups;
    void dfs(int v) {
        low[v] = ord[v] = tm++;
        st.push_back(v);
        inS[v] = true;
        for (auto e: g[v]) {
            if (ord[e.to] == -1) {
                dfs(e.to);
                low[v] = min(low[v], low[e.to]);
            } else if (inS[e.to]) {
                low[v] = min(low[v], ord[e.to]);
            }
        }
        if (low[v] == ord[v]) {
            V<int> gr;
            while (true) {
                int u = st.back(); st.pop_back();
                gr.push_back(u);
                if (u == v) break;
            }
            for (int x: gr) inS[x] = false;
            groups.push_back(gr);
        }
    }
    SCC info;
    SCC_EXEC(const VV<E> &g) : g(g) {
        int n = int(g.size());
        inS = V<bool>(n); low = V<int>(n); ord = V<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(i);
        }
        reverse(begin(groups), end(groups));
        V<int> id(n);
        for (int i = 0; i < int(groups.size()); i++) {
            for (int x: groups[i]) {
                id[x] = i;
            }
        }
        info = SCC{id, groups};
    }
};
template<class E> SCC scc(const VV<E> &g) { return SCC_EXEC<E>(g).info; }

int n, N;
VV<E> g;

void adde(int i, int j) {
//    cout << "adde " << i << " -> " << j << endl;
    g[i].push_back(E{j});
}

struct Node {
    using NP = Node*;
    int sz;
    NP l, r;

    int id;

    Node(int sz, int off) : sz(sz) {
        id = N; N++;
        g.push_back(V<E>{});

        if (sz == 1) {
            adde(id, off);
            return;
        }
        l = new Node(sz/2, off);
        r = new Node(sz-sz/2, off+sz/2);
        adde(id, l->id);
        adde(id, r->id);
    }

    void add(int a, int b, int x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            adde(x, id);
            return;
        }
        l->add(a, b, x);
        r->add(a-sz/2, b-sz/2, x);
    }
};

V<int> solve(const V<int> &le, const V<int> &ri) {
    N = 2*n;
    g = VV<E>(2*n);
    auto tr = new Node(2*n, 0);
    for (int i = 0; i < n; i++) {
        int l = le[i], r = ri[i];
        if (l < r) {
            tr->add(l, r, i);
            tr->add(l+n, r+n, i+n);
        } else {
            if (i < r) {
                tr->add(0, r, i);
                tr->add(l, n+r, n+i);
            } else {
                tr->add(l, n+r, i);
                tr->add(n+l, 2*n, n+i);                
            }
        }
    }
    auto scci = scc(g);
    int m = int(scci.groups.size());
    V<int> dpmi(m, TEN(9)), dpma(m, -TEN(9));

    for (int i = m-1; i >= 0; i--) {
        for (int p: scci.groups[i]) {
            if (p < 2*n) {
                dpmi[i] = min(dpmi[i], p);
                dpma[i] = max(dpma[i], p);
            }
            assert(0 <= p && p < g.size());
            for (auto e: g[p]) {
                int q = e.to;
                //p -> q
                int j = scci.id[q];
                dpmi[i] = min(dpmi[i], dpmi[j]);
                dpma[i] = max(dpma[i], dpma[j]);
            }
        }
    }

    V<int> v(n);
    for (int p = 0; p < n; p++) {
        int i = scci.id[p];
        int ni = scci.id[n+p];
//        int l = dpmi[ni] - n, r = dpma[i];
        int l = min(dpmi[i], dpmi[ni] - n);
        int r = max(dpma[i], dpma[ni] - n);
//        cout << p << " " << l << " " << r << endl;
        v[p] = n-min(n, r-l+1);
    }
    return v;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> n;
    using P = pair<ll, ll>;
    using T = tuple<ll, P, ll>; // pid, pos, rad
    V<T> v(n);

    ll R;
    for (int i = 0; i < n; i++) {
        ll x, y, r, pid;
        cin >> x >> y >> r;
        R = abs(x) + abs(y);

        if (x >= 0 && y >= 0) {
            pid = y;
        } else if (x <= 0 && y >= 0) {
            pid = R - x;
        } else if (x <= 0 && y <= 0) {
            pid = 2*R - y;
        } else {
            pid = 3*R + x;
        }
        v[i] = T(pid, P(x, y), r);
    }

    V<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int a, int b){
        return v[a] < v[b];
    });

    V<P> p(2*n);
    V<ll> pid(2*n), r(2*n);

    for (int i = 0; i < n; i++) {
        tie(pid[i], p[i], r[i]) = v[idx[i]];
        tie(pid[n+i], p[n+i], r[n+i]) = v[idx[i]];
        pid[n+i] += 4*R;
    }

    auto hit = [&](int i, int j) {
        int di = 0;
        di += abs(p[i].first - p[j].first);
        di += abs(p[i].second - p[j].second);
        return di <= r[i];
    };

    V<int> le(n), ri(n);
    //left
    for (int i = 0; i < n; i++) {        
        int l, r = n+i;
        l = lower_bound(begin(pid), end(pid), pid[i] + 2*R) - begin(pid) - 1;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (!hit(n+i, md)) {
                l = md;
            } else {
                r = md;
            }
        }
        le[i] = r;
    }

    //right
    for (int i = 0; i < n; i++) {        
        int l = i, r;
        r = lower_bound(begin(pid), end(pid), pid[i] + 2*R) - begin(pid);
        while (r-l > 1) {
            int md = (l+r)/2;
            if (hit(i, md)) {
                l = md;
            } else {
                r = md;
            }
        }
        ri[i] = n+r;
    }

    for (int i = 0; i < n; i++) {
        if (ri[i] - le[i] >= n) {
            le[i] = 0; ri[i] = n;
        } else {
            le[i] %= n; ri[i] %= n;
        }
    }
/*    for (int i = 0; i < n; i++) {
        cout << idx[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].first << " " << p[i].second << " " << le[i] << " " << ri[i] << endl;
    }*/

    V<int> ans = solve(le, ri);
    V<int> lst(n);
    for (int i = 0; i < n; i++) {
        lst[idx[i]] = ans[i];
    }

    for (int d: lst) {
        cout << d << endl;
    }
    return 0;
}

