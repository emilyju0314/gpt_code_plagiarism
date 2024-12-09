#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 524288, maxlevel = 20;
struct seg_tree {
  int f[maxn << 1];
  int query(int L, int R) {
    int ret = 0x3F3F3F3F;
    for (L += maxn - 1, R += maxn + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
      if (~L & 1) chkmin(ret, f[L ^ 1]);
      if (R & 1) chkmin(ret, f[R ^ 1]);
    }
    return ret;
  }
  void build(seg_tree &g) {
    for (int i = 1; i < maxn; ++i) f[maxn + i] = g.query(g.f[maxn + i], i);
    for (int i = maxn - 1; i; --i) f[i] = min(f[i * 2], f[i * 2 + 1]);
  }
};
seg_tree f[maxlevel];
int main() {
  ios_base::sync_with_stdio(false);
  int n, level = 0;
  cin >> n;
  for (int i = 1, x; i <= n; ++i)
    cin >> x, f[0].f[maxn + i] = max(i - x, 1),
                            f[0].f[maxn + i + n] = max(i - x + n, 1);
  for (int i = maxn - 1; i; --i)
    f[0].f[i] = min(f[0].f[i * 2], f[0].f[i * 2 + 1]);
  for (int i = 1; 1 << i <= n * 2; ++i) f[i].build(f[i - 1]), level = i;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int L = i + n - 1, ret = 0x3F3F3F3F, now = 0;
    for (int b = level, t; b >= 0; --b)
      if ((t = f[b].query(L, i + n - 1)) <= i)
        ret = now | 1 << b;
      else
        L = t, now += 1 << b;
    ans += ret;
  }
  cout << ans << endl;
  return 0;
}
