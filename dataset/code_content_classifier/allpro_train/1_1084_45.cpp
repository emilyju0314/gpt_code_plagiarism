#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, p;
long long l, r;
struct node {
  long long h;
  int x, id;
} a[N];
bool operator<(node x, node y) { return x.h / x.x > y.h / y.x; }
priority_queue<node> q;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? x : -x;
}
bool check(long long h) {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++)
    if (h - 1ll * a[i].x * m < a[i].h) q.push((node){h, a[i].x, i});
  if (q.empty()) return 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) {
      node x = q.top();
      if (x.h < 1ll * x.x * i) return 0;
      q.pop(), x.h += p;
      if (x.h - 1ll * x.x * m < a[x.id].h) q.push(x);
      if (q.empty()) return 1;
    }
  return 0;
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  for (int i = 1; i <= n; i++)
    a[i].h = read(), a[i].x = read(), l = max(l, 1ll * a[i].x),
    r = max(r, a[i].h + 1ll * a[i].x * m);
  while (l < r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld", r);
  return 0;
}
