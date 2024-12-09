#include <bits/stdc++.h>
using namespace std;
int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int N = 210;
const double err = 1e-11;
const int inf = ~0u >> 2;
const long long INF = ~0ull >> 2;
long long read() {
  long long x;
  if (scanf("%lld", &x) == -1) exit(0);
  return x;
}
const double pi = acos(-1.0);
double readf() {
  double x;
  if (scanf("%lf", &x) == -1) exit(0);
  return x;
}
template <typename T>
T sqr(const T &x) {
  return x * x;
}
const int mod = (1 ? 1000000007 : 998244353);
long long mul(long long a, long long b, long long m = mod) { return a * b % m; }
long long qpow(long long a, long long b, long long m = mod) {
  long long ans = 1;
  for (; b; a = mul(a, a, m), b >>= 1)
    if (b & 1) ans = mul(ans, a, m);
  return ans;
}
long long getinv(long long v, long long m = mod) { return qpow(v, m - 2, m); }
int n, m;
bool a[N][N];
vector<int> p[N];
int c[N], lab[N], pos[N];
vector<int> rec;
vector<vector<int>> ans;
void remove(int x, int y) {
  a[x][y] = 0;
  c[y]--;
}
void resume(int x, int y) {
  a[x][y] = 1;
  c[y]++;
}
void work(int x, int y, int dep) {
  if (!a[x][y]) return;
  if (c[y] != 1) return;
  if (dep == n) {
    if (p[x].size() != 2) return;
    rec.push_back(p[x][0]);
    rec.push_back(p[x][1]);
    ans.push_back(rec);
    reverse(ans.back().begin(), ans.back().end());
    if (lab[ans.back()[0]] > lab[ans.back()[1]])
      swap(ans.back()[0], ans.back()[1]);
    rec.pop_back();
    rec.pop_back();
    return;
  }
  rec.push_back(y);
  for (auto j : p[x]) remove(x, j);
  for (auto j : p[x])
    for (int i = (0), _ = (n); i < _; i++) {
      work(i, j, dep + 1);
    }
  for (auto j : p[x]) resume(x, j);
  rec.pop_back();
  return;
}
void output(const vector<int> &ans) {
  for (auto i : ans) cout << i + 1 << ' ';
  cout << endl;
}
bool ok(const vector<int> &ans) {
  for (int i = (0), _ = (ans.size()); i < _; i++) pos[ans[i]] = i;
  static vector<int> a;
  for (int x = (0), _ = (n); x < _; x++) {
    a.clear();
    for (auto y : p[x]) {
      a.push_back(pos[y]);
    }
    sort(a.begin(), a.end());
    for (int i = (0), _ = (a.size() - 1); i < _; i++)
      if (a[i] != a[i + 1] - 1) return 0;
  }
  return 1;
}
void work0() {
  for (int i = (0), _ = (n); i < _; i++)
    for (int j = (0), _ = (m); j < _; j++) work(i, j, 1);
  for (auto &i : ans)
    if (ok(i)) {
      output(i);
      return;
    }
}
signed main() {
  for (int T = read(); T--;) {
    n = read() - 1;
    m = n + 1;
    for (int i = (0), _ = (m); i < _; i++)
      for (int j = (0), _ = (m); j < _; j++) a[i][j] = 0;
    for (int i = (0), _ = (m); i < _; i++) c[i] = lab[i] = 0;
    for (int i = (0), _ = (m); i < _; i++) p[i].clear();
    ans.clear();
    for (int x = (0), _ = (n); x < _; x++) {
      int t = read();
      while (t--) {
        int y = read() - 1;
        a[x][y] = 1;
        c[y]++;
        lab[y]++;
        p[x].push_back(y);
      }
    }
    work0();
  }
  return 0;
}
