#include <bits/stdc++.h>
using namespace std;
const int N = 16505;
const int inf = 1e9 + 7;
char s[N];
int fa[N * 2], rk[N * 2];
bool c[N], p[N];
inline int C(char q) {
  if (q <= '9')
    return q - '0';
  else
    return q - 'A' + 10;
}
int tot;
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void Unite(int x, int y, int type) {
  x = find(x);
  y = find(y);
  if (x != y) tot -= type;
  if (rk[x] < rk[y])
    fa[x] = y;
  else
    fa[y] = x;
  if (rk[x] == rk[y]) rk[x]++;
}
int vis[N * 2], t[N], pos[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m * 2); i++) fa[i] = i;
  for (int i = (1); i <= (m); i++) t[i] = i;
  for (int T = (1); T <= (n); T++) {
    for (int i = (1); i <= (m); i++) p[i] = c[i];
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = (1); i <= (m / 4); i++) {
      int pq = C(s[i]);
      for (int k = (0); k <= (3); k++) {
        ++cnt;
        if (pq & (1 << (3 - k)))
          c[cnt] = 1;
        else
          c[cnt] = 0;
      }
    }
    for (int i = (1); i <= (m); i++)
      if (c[i]) {
        if (p[i]) Unite(i, i + m, 1);
        if (i < m && c[i + 1]) Unite(i + m, i + m + 1, 1);
        tot++;
      }
    memset(vis, 0, sizeof(vis));
    int xjt = 0;
    for (int i = (m + 1); i <= (m * 2); i++) {
      if (c[i - m]) {
        int x = find(i);
        if (!vis[x]) {
          vis[x] = ++xjt;
          pos[xjt] = i - m;
        }
        t[i - m] = vis[x];
      } else
        t[i - m] = 0;
    }
    for (int i = (1); i <= (m * 2); i++) fa[i] = i;
    memset(rk, 0, sizeof(rk));
    for (int i = (1); i <= (m); i++)
      if (t[i]) Unite(i, pos[t[i]], 0);
    for (int i = (1); i <= (m - 1); i++)
      if (p[i] && p[i + 1]) Unite(i, i + 1, 0);
  }
  printf("%d\n", tot);
  return 0;
}
