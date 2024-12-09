#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
inline char gc() {
  static char buf[1 << 16], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 1 << 16, stdin);
    if (p2 == p1) return EOF;
  }
  return *p1++;
}
template <class t>
inline t read(t &x) {
  char c = gc();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = gc();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
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
const int N = 5e5 + 5;
int n, m, col[N];
pair<int, int> a[N];
bool exi[N];
vector<int> g[N];
signed main() {
  read(n);
  read(m);
  for (int second = 1, x, y; second <= m; second++) {
    read(x);
    read(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int second = 1, x; second <= n; second++)
    a[second] = pair<int, int>(read(x), second);
  sort(a + 1, a + 1 + n);
  for (int second = 1; second <= n; second++) {
    int x = a[second].second, first = a[second].first, cnt = 0;
    if (g[x].size() == 0) {
      col[x] = 1;
      continue;
    }
    for (int y : g[x]) {
      if (col[y] && col[y] < first && !exi[col[y]]) exi[col[y]] = 1, cnt++;
      if (col[y] == first) {
        write(-1);
        return 0;
      }
    }
    if (cnt != first - 1) {
      write(-1);
      return 0;
    }
    for (int y : g[x])
      if (col[y] && col[y] < first) exi[col[y]] = 0;
    col[x] = first;
  }
  for (int second = 1; second <= n; second++)
    write(a[second].second), putchar(' ');
}
