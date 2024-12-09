#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
const int maxL = 20;
vector<int> a[maxN], xx[maxN];
int st[maxN], en[maxN], h[maxN], p[maxN];
int lca[maxN][maxL], cnt;
void dfs(int v, int par = 0) {
  st[v] = cnt++;
  lca[v][0] = par;
  for (int i = 1; i < maxL; i++) lca[v][i] = lca[lca[v][i - 1]][i - 1];
  xx[h[v]].push_back(st[v]);
  for (auto u : a[v])
    if (u - par) h[u] = h[v] + 1, dfs(u, v);
  en[v] = cnt;
}
int get_par(int v, int k) {
  for (int i = 0; i < maxL; i++)
    if (k >> i & 1) v = lca[v][i];
  return v;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> p[i];
    if (p[i]) a[p[i]].push_back(i);
  }
  for (int i = 1; i < n + 1; i++)
    if (p[i] == 0) dfs(i);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    int dis = h[v];
    if (k > dis) {
      cout << 0 << ' ';
      continue;
    }
    v = get_par(v, k);
    int psl =
        lower_bound(xx[dis].begin(), xx[dis].end(), st[v]) - xx[dis].begin();
    int psr =
        lower_bound(xx[dis].begin(), xx[dis].end(), en[v]) - xx[dis].begin();
    cout << psr - psl - 1 << ' ';
  }
  cout << endl;
  return 0;
}
