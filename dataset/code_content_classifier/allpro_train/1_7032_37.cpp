#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
inline int lowbit(int x) { return x & (-x); }
int vis[3010], used[3010];
int tot, bel[3010], a[3010][3], n, deg[3010], has[3010];
int fa[3010];
int st[3010], top, id[3010];
int d[3010][3], c[3010];
int main() {
  n = read();
  for (register int i = 1; i <= 3 * n; i++) {
    vis[read()] = 1;
  }
  for (register int i = 1; i <= 6 * n; i++) {
    if (!top || (vis[i] != vis[d[top][0]])) {
      top++;
      d[top][0] = i;
      c[top] = 1;
      id[top] = ++tot;
    } else {
      d[top][c[top]++] = i;
      if (c[top] == 3) {
        int x = id[top];
        fa[x] = id[top - 1];
        deg[fa[x]]++;
        for (register int i = 0; i <= 2; i++) a[x][i] = d[top][i];
        bel[x] = vis[a[x][0]];
        top--;
      }
    }
  }
  int res = 0;
  for (register int i = 1; i <= tot; i++)
    if (fa[i] == 0 && bel[i] == 0) res++;
  for (register int i = 1; i <= 2 * n; i++) {
    int c = i & 1, x = 0;
    for (register int j = 1; j <= tot; j++)
      if (deg[j] == 0 && !has[j] && bel[j] == c) {
        if (i != 2 * n && c == 0 && fa[j] == 0 && res == 1) continue;
        x = j;
        break;
      }
    cout << a[x][0] << " " << a[x][1] << " " << a[x][2] << '\n';
    deg[fa[x]]--;
    has[x] = 1;
    if (c == 0 && fa[x] == 0) res--;
  }
  return 0;
}
