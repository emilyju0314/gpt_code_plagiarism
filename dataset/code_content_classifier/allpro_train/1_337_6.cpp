#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
    // cin.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin >> n;
    lint m; cin >> m;
    V<lint> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    auto vl = l, vr = r;
    auto v = l;
    v.insert(end(v), begin(r), end(r));
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    for (auto&& e : l) {
        e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    for (auto&& e : r) {
        e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    for (auto&& e : vl) {
        e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    for (auto&& e : vr) {
        e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    sort(begin(vl), end(vl));
    sort(begin(vr), end(vr));

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[l[i]] = max<lint>(mp[l[i]], r[i]);
    }

    m = v.size() - 1;
    // cerr << m << endl;
    int x = 0, p = 0;
    auto itr = begin(mp);
    while (p < m) {
        int np = p;
        while (itr != end(mp) and itr->first <= p) {
            np = max(np, itr->second);
            ++itr;
        }
        p = np;
        // cerr << np << endl;
        ++x;
    }
    int y = 0;
    for (int i = 0; i < m; ++i) {
        int z = upper_bound(begin(vr), end(vr), i) - begin(vr);
        z += end(vl) - lower_bound(begin(vl), end(vl), i + 1);
        y = max(y, z);
        // cerr << i << ' ' << z << endl;
    }
    cout << x << ' ' << y + 1 << '\n';
}
