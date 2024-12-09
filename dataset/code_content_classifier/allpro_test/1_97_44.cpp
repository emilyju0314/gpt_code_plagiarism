#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3F3F3F3F;
vector<int> G[N];
int n, m, cnt;
int a[N], sz[N], fa[N], dfn[N];
long long ans[N];
bool del[N];
set<pair<int, int> > S;
struct rec {
  int x, k, id;
  bool operator<(const rec &b) const { return k < b.k; }
} q[N];
namespace FastIn {
char Buf[1 << 22], *S(Buf), *T(Buf);
inline int ReadInt() {
  int x = 0, sign = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      sign = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * sign;
}
}  // namespace FastIn
void DFS(int x, int pre) {
  fa[x] = pre;
  dfn[x] = ++cnt;
  sz[x] = 1, a[x] = -1;
  for (auto y : G[x]) {
    if (y != pre) {
      ++a[x], DFS(y, x);
      sz[x] += sz[y];
    }
  }
}
struct DSU {
  int pre[N];
  void Init(int sz) {
    for (int i = 1; i <= sz; ++i) {
      pre[i] = i;
    }
  }
  inline int find(int x) {
    if (x == pre[x]) {
      return x;
    } else {
      return pre[x] = find(pre[x]);
    }
  }
  inline void merge(int x, int y) { pre[find(x)] = find(y); }
} DS;
struct BIT {
  long long dt[N];
  inline void update(int x, long long v) {
    for (; x <= n; x += x & -x) {
      dt[x] += v;
    }
  }
  inline long long query(int x) {
    long long ret = 0;
    for (; x; x -= x & -x) {
      ret += dt[x];
    }
    return ret;
  }
} T[2];
void GetTop(long long &v, long long &id) {
  if (S.empty()) {
    id = v = INF;
    return;
  }
  int x = S.begin()->second;
  while (del[x]) {
    S.erase(S.begin());
    if (S.empty()) {
      id = v = INF;
      return;
    }
    x = S.begin()->second;
  }
  id = x, v = S.begin()->first;
}
inline long long Get(int x, bool tp) {
  return T[tp].query(dfn[x] + sz[x] - 1) - T[tp].query(dfn[x] - 1);
}
inline void update(int x) {
  S.insert(make_pair(ceil((long double)-Get(x, 0) / Get(x, 1)), x));
}
inline long long query(int x, int k) { return Get(x, 0) + Get(x, 1) * k; }
int main() {
  n = FastIn ::ReadInt();
  for (int i = 1; i < n; ++i) {
    int x = FastIn ::ReadInt();
    int y = FastIn ::ReadInt();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  DS.Init(n), DFS(1, 0);
  m = FastIn ::ReadInt();
  for (int i = 1; i <= m; ++i) {
    q[i].x = FastIn ::ReadInt();
    q[i].k = -FastIn ::ReadInt();
    q[i].id = i;
  }
  sort(q + 1, q + m + 1);
  for (int i = 1; i <= n; ++i) {
    T[0].update(dfn[i], a[i]);
    T[1].update(dfn[i], 1);
    if (fa[i]) {
      T[0].update(dfn[fa[i]], -a[i]);
      T[1].update(dfn[fa[i]], -1);
    }
    if (i > 1) {
      S.insert(make_pair(-a[i], i));
    }
  }
  for (int i = 1; i <= m; ++i) {
    long long v, x, sz, dt, nxt;
    GetTop(v, x);
    while (v <= q[i].k) {
      sz = Get(x, 1);
      dt = Get(x, 0);
      nxt = DS.find(fa[x]);
      DS.merge(x, fa[x]);
      S.erase(S.begin());
      del[x] = 1;
      T[0].update(dfn[fa[x]], dt);
      T[1].update(dfn[fa[x]], sz);
      if (fa[nxt]) {
        T[0].update(dfn[fa[nxt]], -dt);
        T[1].update(dfn[fa[nxt]], -sz);
        update(nxt);
      }
      GetTop(v, x);
    }
    ans[q[i].id] =
        max(query(q[i].x, q[i].k) - q[i].k + 1, (long long)a[q[i].x] + 1);
  }
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
