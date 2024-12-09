#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
namespace DSU {
const int maxn = 1e5 + 5;
int f[maxn], siz[maxn];
vector<pair<int*, int>> sta;
void init(int n) {
  for (int i = 1; i <= n; ++i) f[i] = i, siz[i] = 1;
}
int find(int x) { return x == f[x] ? x : find(f[x]); }
bool Union(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  if (siz[u] < siz[v]) swap(u, v);
  sta.push_back({&f[v], f[v]});
  sta.push_back({&siz[u], siz[u]});
  f[v] = u;
  siz[u] += siz[v];
  return true;
}
void undo(int x) {
  while (sta.size() > x) {
    *sta.back().first = sta.back().second;
    sta.pop_back();
  }
}
};  // namespace DSU
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  int day = 0, ques = 0;
  vector<tuple<int, int, int, int>> edges;
  vector<pii> query;
  vector<int> eday;
  for (int i = 1; i <= q; ++i) {
    int t, x, y, z;
    cin >> t;
    switch (t) {
      case 1: {
        cin >> x >> y;
        edges.push_back({x, y, ques, day});
        break;
      }
      case 2: {
        cin >> z;
        query.push_back({ques, z});
        ++ques;
        break;
      }
      case 3: {
        eday.push_back(ques);
        day++;
        break;
      }
    }
  }
  eday.push_back(ques);
  vector<vector<pii>> Seg(4 * ques);
  function<void(int, int, int, int, int, pii)> add =
      [&](int p, int l, int r, int x, int y, pii edge) {
        if (y <= l || x >= r) return;
        if (x <= l && r <= y) {
          Seg[p].push_back(edge);
          return;
        }
        int mid = l + (r - l) / 2;
        add(p * 2, l, mid, x, y, edge);
        add(p * 2 + 1, mid, r, x, y, edge);
      };
  for (auto [u, v, q, d] : edges) {
    add(1, 0, ques, q, eday[min(d + k - 1, day)], {u, v});
  }
  int now = 0;
  DSU::init(n);
  function<void(int, int, int)> solve = [&](int p, int l, int r) {
    int state = DSU::sta.size();
    for (auto [u, v] : Seg[p]) {
      DSU::Union(u, v);
    }
    if (r - l == 1) {
      while (now < query.size() && query[now].first == l) {
        int ans = DSU::siz[DSU::find(query[now++].second)];
        cout << ans << '\n';
      }
    } else {
      int mid = (l + r) / 2;
      solve(p * 2, l, mid);
      solve(p * 2 + 1, mid, r);
    }
    DSU::undo(state);
  };
  solve(1, 0, ques);
  return 0;
}
