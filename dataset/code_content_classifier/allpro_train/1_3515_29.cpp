#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int maxm = 50005;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int n, m, G, S;
struct edge {
  int u, v, g, s;
  edge(int u = 0, int v = 0, int g = 0, int s = 0) : u(u), v(v), g(g), s(s) {}
  bool operator<(const edge &rhs) const {
    if (g == rhs.g)
      return s < rhs.s;
    else
      return g < rhs.g;
  }
};
edge e[maxm];
int fa[maxn], sz;
void init_uns() {
  for (register int i = 1; i <= n; i++) fa[i] = i;
  sz = n;
}
int find(int x) {
  if (fa[x] == x)
    return x;
  else
    return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  int t1 = find(x), t2 = find(y);
  if (t1 != t2) {
    fa[t1] = t2;
    sz--;
    return true;
  }
  return false;
}
void input() {
  int x, y, a, b;
  cin >> n >> m;
  cin >> G >> S;
  for (register int i = 1; i <= m; i++) {
    cin >> x >> y >> a >> b;
    e[i] = edge(x, y, a, b);
  }
  sort(e + 1, e + m + 1);
}
vector<int> mst[2];
int vr = 0;
void solve() {
  long long ans = inf;
  for (register int i = 1; i <= m; i++) {
    if (mst[vr].size() == 0)
      mst[vr].push_back(i);
    else {
      for (register int j = 0, ed = mst[vr].size(); j <= ed; j++) {
        if (e[i].s < e[mst[vr][j]].s || j == ed) {
          mst[vr].insert(mst[vr].begin() + j, i);
          break;
        }
      }
    }
    vr ^= 1, init_uns();
    mst[vr].clear();
    for (register int j = 0, ed = mst[vr ^ 1].size(); j < ed; j++) {
      int id = mst[vr ^ 1][j];
      int x = e[id].u, y = e[id].v;
      if (merge(x, y)) {
        mst[vr].push_back(id);
      }
      if (sz == 1) break;
    }
    if (sz == 1) {
      ans = min(ans,
                1ll * e[i].g * G + 1ll * e[mst[vr][mst[vr].size() - 1]].s * S);
    }
  }
  if (ans != inf)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
int main() {
  input();
  solve();
  return 0;
}
