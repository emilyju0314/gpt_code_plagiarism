#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long INFL = 1000000000000000007;
const long double INFS = 0.00000001;
const long long MOD = 1000000007;
const long double PI = 3.14159265;
int n, a, b;
int len;
vector<int> con[100001];
vector<int> son[100001];
int lev[100001];
int sz[100001];
int to[100001];
int root;
int bl[100001][21], logi;
int pow2[31];
void lcadfs(int pos, int fa) {
  int i;
  bl[pos][0] = fa;
  for (i = 1; i <= logi; i++) bl[pos][i] = bl[bl[pos][i - 1]][i - 1];
  for (i = 0; i < son[pos].size(); i++) lcadfs(son[pos][i], pos);
}
int lca(int u, int v) {
  int i;
  if (lev[u] < lev[v]) {
    int t = u;
    u = v, v = t;
  }
  for (i = logi; i >= 0; i--)
    if (lev[u] - pow2[i] >= lev[v]) u = bl[u][i];
  if (u == v) return u;
  for (i = logi; i >= 0; i--)
    if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
  return bl[u][0];
}
int binl(int p, int x) {
  int i;
  for (i = logi; i >= 0; i--)
    if (pow2[i] <= x) p = bl[p][i], x -= pow2[i];
  return p;
}
void rt(int x, int p, int level) {
  int i;
  if (x == root) {
    for (i = 1; i <= n; i++) son[i].clear();
  }
  sz[x] = 0, to[x] = x, lev[x] = level;
  for (i = 0; i < con[x].size(); i++) {
    int f = con[x][i];
    if (f != p) {
      son[x].push_back(f), rt(f, x, level + 1);
      if (sz[f] >= sz[x]) sz[x] = sz[f] + 1, to[x] = to[f];
    }
  }
}
int fd(int x, int up) {
  vector<pair<int, int> > bch;
  int ret = 0;
  int i;
  bch.push_back({up, 0});
  for (i = 0; i < son[x].size(); i++)
    bch.push_back({sz[son[x][i]] + 1, son[x][i]});
  sort(bch.begin(), bch.end());
  if (bch.size() >= 3 && bch[bch.size() - 1].first >= len - 1 &&
      bch[bch.size() - 2].first >= len - 1 &&
      bch[bch.size() - 3].first >= len - 1) {
    root = x;
    return 1;
  }
  for (i = 0; i < son[x].size(); i++) {
    int f = son[x][i];
    if (bch[bch.size() - 1].second != f)
      ret = fd(f, bch[bch.size() - 1].first + 1);
    else
      ret = fd(f, bch[bch.size() - 2].first + 1);
    if (ret == 1) return 1;
  }
  return 0;
}
int wk2() {
  int i;
  for (i = 1; i <= 2 * n; i++) {
    int top = lca(a, b);
    if (sz[a] == 0) {
      int t = a;
      a = b, b = t;
    }
    if (lev[top] == lev[b]) return 1;
    if (lev[to[a]] - lev[top] + 1 >= len) return 1;
    b = binl(b, lev[to[a]] - lev[a]), a = to[a];
  }
  return 0;
}
void ini() {
  int i;
  for (i = 1; i <= n; i++) con[i].clear();
  pow2[0] = 1;
  for (i = 1; i <= 30; i++) pow2[i] = pow2[i - 1] * 2;
}
void wk() {
  int i;
  cin >> n >> a >> b, logi = log(n) / log(2);
  ini();
  for (i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    con[x].push_back(y);
    con[y].push_back(x);
  }
  root = 1;
  rt(root, -1, 1);
  lcadfs(root, 0);
  len = lev[a] + lev[b] - 2 * lev[lca(a, b)] + 1;
  if (!fd(root, 0)) {
    cout << "NO" << endl;
    return;
  }
  rt(root, -1, 1);
  lcadfs(root, 0);
  if (wk2())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  int i;
  cin >> t;
  for (i = 1; i <= t; i++) wk();
  return 0;
}
