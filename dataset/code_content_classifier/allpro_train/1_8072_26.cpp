#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
int n, m;
vector<int> p, sz, stt;
vector<vector<int>> adj, edge, grp;
vector<double> val;
double base;
int par(int x) {
  if (x != p[x]) p[x] = par(p[x]);
  return p[x];
}
void uni(int x, int y) {
  x = par(x);
  y = par(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
}
void reset(int pp, double first) {
  for (int x : grp[pp]) val[x] = stt[x] = 0;
  val[pp] = first;
}
long long getSum(int pp) {
  long long res = 0;
  for (int x : grp[pp]) res += abs((long long)val[x]);
  return res;
}
int other(int cur, int e) {
  if (edge[e][0] == cur) return edge[e][1];
  return edge[e][0];
}
int dfa(int cur, int par) {
  for (int e : adj[cur]) {
    int x = other(cur, e);
    if (x == par) continue;
    if (!stt[x]) {
      val[x] = edge[e][2] - val[cur];
      stt[x] = stt[cur] % 2 + 1;
      int res = dfa(x, cur);
      if (res) return res;
    } else {
      int s = stt[cur] % 2 + 1;
      double v = edge[e][2] - val[cur];
      if (s == stt[x] && v != val[x])
        return -1;
      else if (s != stt[x]) {
        if (s == 1)
          base = (val[x] - v) / 2;
        else
          base = (v - val[x]) / 2;
        return 1;
      }
    }
  }
  return 0;
}
void dfb(int cur) {
  for (int e : adj[cur]) {
    int x = other(cur, e);
    if (stt[x]) continue;
    stt[x] = 1;
    val[x] = edge[e][2] - val[cur];
    dfb(x);
  }
}
bool cek(int pp) {
  for (int cur : grp[pp]) {
    for (int e : adj[cur]) {
      int x = other(cur, e);
      if (val[cur] + val[x] != edge[e][2]) return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  edge = vector<vector<int>>(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) cin >> edge[i][j];
    adj[--edge[i][0]].push_back(i);
    adj[--edge[i][1]].push_back(i);
  }
  p = vector<int>(n);
  sz = vector<int>(n, 1);
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m; i++) uni(edge[i][0], edge[i][1]);
  grp = vector<vector<int>>(n);
  for (int i = 0; i < n; i++) grp[par(i)].push_back(i);
  stt = vector<int>(n);
  val = vector<double>(n);
  for (int i = 0; i < n; i++) {
    if (grp[i].empty()) continue;
    stt[i] = 1;
    int res = dfa(i, -1);
    if (res == -1) {
      cout << "NO\n";
      return 0;
    } else if (res == 1) {
      reset(i, base);
      dfb(i);
      if (!cek(i)) {
        cout << "NO\n";
        return 0;
      }
    } else {
      int l = -MX, r = MX;
      while (r - l > 3) {
        int ma = (l + r) / 2;
        int mb = ma + 1;
        long long ra, rb;
        reset(i, ma);
        dfb(i);
        ra = getSum(i);
        reset(i, mb);
        dfb(i);
        rb = getSum(i);
        if (ra < rb)
          r = mb;
        else
          l = ma;
      }
      long long best, res = 1e18;
      for (int j = l; j <= r; j++) {
        reset(i, j);
        dfb(i);
        long long rc = getSum(i);
        if (rc <= res) {
          res = rc;
          best = j;
        }
      }
      reset(i, best);
      dfb(i);
    }
  }
  cout << "YES\n";
  for (double x : val) cout << x << ' ';
  cout << '\n';
}
