#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
void put1() { puts("Yes"); }
void put2() { puts("No"); }
void debug() { printf("我在这里\n"); }
void put3() { puts("-1"); }
long long qpf(long long a, long long b, long long p) {
  long long ret = 0;
  while (b) {
    if (b & 1) ret = (ret + a) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  return ret % p;
}
long long qp(long long a, long long n, long long p) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = qpf(ret, a, p);
    a = qpf(a, a, p);
    n >>= 1;
  }
  return ret % p;
}
const int manx = 2e5 + 5;
vector<long long> g[manx], G[manx];
long long a[manx], d[manx], vis[manx];
long long n, m, p;
void dij() {
  for (int i = 1; i <= n; i++) vis[i] = 0, d[i] = 1e9;
  priority_queue<pair<long long, long long> > q;
  q.push(make_pair(0, a[p]));
  d[a[p]] = 0;
  while (q.size()) {
    long long u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      long long v = G[u][i];
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(make_pair(-d[v], v));
      }
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    long long u = read(), v = read();
    g[u].push_back(v);
    G[v].push_back(u);
  }
  p = read();
  for (int i = 1; i <= p; i++) a[i] = read();
  dij();
  long long ans1 = 0, ans2 = 0;
  for (int i = 1; i < p; i++) {
    long long u = a[i], v = a[i + 1];
    if (d[u] != d[v] + 1)
      ++ans1, ++ans2;
    else {
      for (int j = 0; j < g[u].size(); j++) {
        long long x = g[u][j];
        if (d[x] == d[u] - 1 && x != v) {
          ans2++;
          break;
        }
      }
    }
  }
  printf("%lld %lld", ans1, ans2);
  return 0;
}
