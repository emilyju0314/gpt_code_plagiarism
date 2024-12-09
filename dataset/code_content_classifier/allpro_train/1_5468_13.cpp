#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 5, mxM = 5e5 + 5;
int par[mxN], Size[mxN], u[mxM], v[mxM];
vector<int> adj[mxN];
int find_Set(int x) { return par[x] = x == par[x] ? x : find_Set(par[x]); }
void union_Set(int x, int y) {
  x = find_Set(x);
  y = find_Set(y);
  if (x != y) {
    if (Size[x] < Size[y]) swap(x, y);
    Size[x] += Size[y];
    par[y] = x;
  }
}
int main() {
  int q;
  cin >> q;
  set<int> aa, bb;
  while (q--) {
    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= m; ++i) scanf("%d%d", u + i, v + i);
    aa.clear(), bb.clear();
    for (int i = 1; i <= n; ++i) Size[i] = 1, par[i] = i;
    for (int i = 1; i <= m; ++i) {
      if (u[i] == a || v[i] == a) continue;
      union_Set(u[i], v[i]);
    }
    for (int i = 1; i <= n; ++i) find_Set(i);
    int look = par[b];
    for (int i = 1; i <= n; ++i) {
      if (par[i] == look && i != b) bb.insert(i);
      Size[i] = 1, par[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      if (u[i] == b || v[i] == b) continue;
      union_Set(u[i], v[i]);
    }
    for (int i = 1; i <= n; ++i) find_Set(i);
    look = par[a];
    for (int i = 1; i <= n; ++i) {
      if (par[i] == look && i != a) aa.insert(i);
      Size[i] = 1, par[i] = i;
    }
    long long cnt_a = 0, cnt_b = 0;
    set<int>::iterator it = aa.begin();
    while (it != aa.end()) {
      cnt_a += bb.find(*it) == bb.end();
      ++it;
    }
    it = bb.begin();
    while (it != bb.end()) {
      cnt_b += aa.find(*it) == aa.end();
      ++it;
    }
    printf("%lld\n", cnt_a * cnt_b);
  }
}
