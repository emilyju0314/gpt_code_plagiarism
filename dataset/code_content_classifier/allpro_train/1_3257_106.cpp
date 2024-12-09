#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long *X, long long *Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
inline int STRLEN(char *s) {
  int p = 0;
  while (s[p]) p++;
  return p;
}
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
const long long inf = 2147383647LL;
const long long mod = 1e9 + 7;
const int Size = 200005;
int N;
int deg[Size];
int indeg[Size];
int vis[Size];
int color[Size];
vector<int> RG[Size], G[Size];
int id = 0, cycleHead;
vector<int> List, self;
long long res = 1;
long long call(int u) {
  long long res = ((long long)(RG[u]).size());
  for (int i = 0; i < ((long long)(RG[u]).size()); i++) {
    int v = RG[u][i];
    res += call(v);
  }
  return res;
}
void mark(int u) {
  vis[u] = 1;
  for (int i = 0; i < ((long long)(RG[u]).size()); i++) {
    int v = RG[u][i];
    if (!vis[v]) mark(v);
  }
}
bool findcycle(int u) {
  if (color[u] == id) {
    cycleHead = u;
    return true;
  }
  if (color[u] != 0) return false;
  color[u] = id;
  for (int i = 0; i < ((long long)(G[u]).size()); i++) {
    int v = G[u][i];
    if (findcycle(v)) return true;
  }
  return false;
}
void vanishCycle() {
  for (int i = 0; i < ((long long)(List).size()); i++) {
    int u = List[i];
    if (color[u] != 0) continue;
    id++;
    if (findcycle(u)) {
      int cur = cycleHead, cnt = 0;
      while (1) {
        cnt++;
        cur = G[cur][0];
        if (cur == cycleHead) break;
      }
      if (cnt > 1) res = (res * 2LL) % mod;
      mark(cycleHead);
    }
  }
}
int main() {
  scanf("%d", &N);
  memset(deg, 0, sizeof(deg));
  memset(vis, 0, sizeof(vis));
  memset(color, 0, sizeof(color));
  for (int i = 0; i < N; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    RG[v].push_back(u);
    deg[u]++;
    List.push_back(u);
    List.push_back(v);
  }
  vanishCycle();
  sort((List).begin(), (List).end());
  (List).erase(unique((List).begin(), (List).end()), (List).end());
  for (int i = 0; i < ((long long)(List).size()); i++) {
    int u = List[i];
    if (vis[u]) continue;
    if (deg[u] == 0) {
      long long ret = call(u) + 1;
      res = (res * ret) % mod;
      mark(u);
    }
  }
  cout << res << endl;
  return 0;
}
