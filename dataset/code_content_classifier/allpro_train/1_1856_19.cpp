#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
template <class t>
inline void writeln(t x) {
  write(x);
  putchar('\n');
  return;
}
template <class t>
inline void write_blank(t x) {
  write(x);
  putchar(' ');
  return;
}
long long n, m, a[100010], head[100010], cnt;
bool vis[100010];
struct Edge {
  long long to, next;
} edge[100010 << 1];
void add_edge(long long u, long long v) {
  cnt++;
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
  return;
}
vector<long long> res;
void dfs(long long u, long long father) {
  vis[u] = true;
  res.push_back(u);
  a[u] ^= 1;
  for (long long i = head[u]; i; i = edge[i].next) {
    long long v = edge[i].to;
    if (vis[v]) continue;
    dfs(v, u);
    res.push_back(u);
    a[u] ^= 1;
  }
  if (a[u]) {
    res.push_back(father);
    a[father] ^= 1;
    res.push_back(u);
    a[u] ^= 1;
  }
  return;
}
signed main() {
  read(n);
  read(m);
  for (long long i = 1, x, y; i <= m; i++) {
    read(x);
    read(y);
    add_edge(x, y);
    add_edge(y, x);
  }
  for (long long i = 1; i <= n; i++) {
    read(a[i]);
  }
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] == 1) {
      s = i;
      break;
    }
  }
  if (s != 0) {
    dfs(s, 0);
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i] && a[i] == 1) {
      write(-1);
      return 0;
    }
  }
  if (a[0] == 1) {
    res.pop_back();
    res.pop_back();
    res.pop_back();
  }
  writeln(res.size());
  for (long long u : res) {
    write_blank(u);
  }
  return 0;
}
