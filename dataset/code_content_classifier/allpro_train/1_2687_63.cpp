#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int n, i, j, m, x, y, pos[N], id[N];
long long S;
struct P {
  int x, y;
  bool operator<(P a) const { return x < a.x || x == a.x && y < a.y; }
  P operator-(P a) const { return {x - a.x, y - a.y}; }
  long long operator^(P a) const { return 1ll * x * a.y - 1ll * a.x * y; }
} a[N];
struct K {
  int x, y;
  double k;
  bool operator<(K a) const { return k < a.k; }
} b[N * N];
long long cal(P A, P B, P C) { return abs((B - A) ^ (C - A)); }
void doit(int l, int r) {
  int t = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (cal(a[id[mid]], a[x], a[y]) >= S)
      r = mid - 1, t = id[mid];
    else
      l = mid + 1;
  }
  if (cal(a[t], a[x], a[y]) == S)
    printf("Yes\n%d %d\n%d %d\n%d %d", a[t].x, a[t].y, a[x].x, a[x].y, a[y].x,
           a[y].y),
        exit(0);
}
int main() {
  scanf("%d%lld", &n, &S), S *= 2;
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y), pos[i] = id[i] = i;
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      b[++m] = {i, j, atan2(a[j].y - a[i].y, a[j].x - a[i].x)};
  sort(b + 1, b + m + 1);
  for (i = 1; i <= m; i++) {
    x = b[i].x, y = b[i].y;
    if (pos[x] > pos[y]) swap(x, y);
    doit(1, pos[x] - 1), doit(pos[y] + 1, n);
    swap(pos[x], pos[y]), swap(id[pos[x]], id[pos[y]]);
  }
  puts("No");
}
