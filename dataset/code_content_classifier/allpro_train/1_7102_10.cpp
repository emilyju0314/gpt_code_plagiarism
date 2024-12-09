#include <bits/stdc++.h>
namespace IO {
char buf[1000000], *p1, *p2;
inline char getc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 10, stdin);
  return p1 == p2 ? EOF : *(p1++);
}
template <typename tp>
inline void r(tp &n) {
  n = 0;
  char c = getc();
  int f = 1;
  while (!isdigit(c) && c != '-') c = getc();
  if (c == '-') c = getc(), f = -1;
  while (isdigit(c)) n = n * 10 + c - 48, c = getc();
  n *= f;
}
template <typename tp>
inline void w(tp n) {
  if (n < 0) putchar('-'), n = -n;
  if (n / 10) w(n / 10);
  putchar(n % 10 + 48);
}
};  // namespace IO
using namespace IO;
const int N = 6e2 + 5, M = 2e3 + 5, INF = 1e9, MAX = 1e8;
using namespace std;
int n, S, T, num = 1;
int d[N], v[N];
int head[N], nt[M << 1], to[M << 1], cap[M << 1];
long long ans;
bool BFS() {
  for (int i = S; i <= T; ++i) d[i] = 0;
  queue<int> q;
  q.push(S);
  d[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nt[i]) {
      if (!cap[i] || d[to[i]]) continue;
      d[to[i]] = d[u] + 1;
      q.push(to[i]);
      if (to[i] == T) return true;
    }
  }
  return false;
}
int dinic(int p, int flow) {
  if (p == T) return flow;
  int res = flow;
  for (int i = head[p]; i && res; i = nt[i]) {
    if (!cap[i] || d[to[i]] != d[p] + 1) continue;
    int k = dinic(to[i], min(cap[i], res));
    if (!k) d[to[i]] = 0;
    cap[i] -= k;
    cap[i ^ 1] += k;
    res -= k;
  }
  return flow - res;
}
void Add(int x, int y, int z) {
  ++num;
  nt[num] = head[x];
  head[x] = num;
  to[num] = y;
  cap[num] = z;
  ++num;
  nt[num] = head[y];
  head[y] = num;
  to[num] = x;
  cap[num] = 0;
}
int main() {
  r(n);
  S = 0, T = n + n + 1;
  for (int i = 1, k, x; i <= n; ++i) {
    r(k);
    while (k--) r(x), Add(i, x + n, INF);
  }
  for (int i = 1; i <= n; ++i)
    r(v[i]), Add(S, i, MAX - v[i]), Add(i + n, T, MAX), ans += MAX - v[i];
  int flow;
  while (BFS())
    while (flow = dinic(S, INF)) ans -= flow;
  w(min(-ans, 0ll));
  return 0;
}
