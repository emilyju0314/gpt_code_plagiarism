#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int vis[N], n, m, pos;
int main() {
  register int T;
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &n, &m);
    for (register int i = 1, b; i <= m; ++i) scanf("%*d%d%*d", &b), vis[b] = 1;
    for (register int i = 1; i <= n; ++i)
      if (!vis[i]) {
        pos = i;
        break;
      }
    for (register int i = 1; i <= n; ++i) {
      if (i == pos) continue;
      printf("%d %d\n", i, pos);
    }
  }
  getchar(), getchar();
  return 0;
}
