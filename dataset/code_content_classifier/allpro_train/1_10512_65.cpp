#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
int n, cnt;
bitset<maxn> q[maxn];
struct Edge {
  int from, to;
  double val;
  Edge() {}
  Edge(int a, int b, double t) {
    from = a;
    to = b;
    val = t;
  }
  friend inline bool operator<(const Edge& A, const Edge& B) {
    return A.val > B.val;
  }
} e[maxn * maxn];
struct Node {
  int x, y;
} a[maxn];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
double Cal(int xa, int ya, int xb, int yb) {
  return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].y = read();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      e[++cnt] = Edge(i, j, Cal(a[i].x, a[i].y, a[j].x, a[j].y));
  sort(e + 1, e + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    int u = e[i].from, v = e[i].to;
    if ((q[u] & q[v]).count()) {
      printf("%.20lf\n", e[i].val / 2.0);
      return 0;
    }
    q[u].set(v);
    q[v].set(u);
  }
  return 0;
}
