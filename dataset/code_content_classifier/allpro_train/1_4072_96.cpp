#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, fa[N << 1], q, ans = -1;
int fd(int x) {
  if (fa[x] != x) fa[x] = fd(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int i;
  for (i = 1; i <= n + m; ++i) fa[i] = i;
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    int u1 = fd(u), u2 = fd(v + n);
    if (u1 != u2) {
      fa[u1] = u2;
    }
  }
  for (i = 1; i <= n + m; ++i)
    if (fa[i] == i) ++ans;
  printf("%d", ans);
}
