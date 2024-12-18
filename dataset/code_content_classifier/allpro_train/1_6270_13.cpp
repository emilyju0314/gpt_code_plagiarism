#include <bits/stdc++.h>
using namespace std;
const long long oo = 0x7fffffff;
int fa[200010];
long long r[200010], d[200010], mn[200010], mx[200010];
int find(int x) {
  if (fa[x] == x) return x;
  int tmp = fa[x];
  fa[x] = find(fa[x]);
  r[x] += r[tmp];
  return fa[x];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  mn[1] = mn[n] = oo;
  mx[1] = mx[n] = -oo;
  long long tot = 0, nmx = -oo;
  for (int i = 1; i <= m; i++) {
    int x, y;
    long long a, b;
    scanf("%d%d%I64d%I64d", &x, &y, &a, &b);
    d[x] += b;
    d[y] -= b;
    int fx = find(x), fy = find(y);
    if (fx == fy) {
      if (r[x] + a * b == r[y]) continue;
      printf("BAD %d\n", i);
      return 0;
    }
    r[fy] = r[x] + a * b - r[y];
    mn[fx] = min(mn[fy] + r[fy], mn[fx]);
    mx[fx] = max(mx[fy] + r[fy], mx[fx]);
    nmx = max(nmx, mx[fx] - mn[fx]);
    fa[fy] = fx;
    find(y);
    if (mn[find(1)] <= r[1] || mx[find(n)] >= r[n] ||
        (find(1) == find(n) && (nmx >= r[n] - r[1] || r[n] <= r[1]))) {
      printf("BAD %d\n", i);
      return 0;
    }
  }
  if (find(1) != find(n))
    printf("UNKNOWN\n");
  else
    printf("%I64d\n", r[n] - r[1]);
  return 0;
}
