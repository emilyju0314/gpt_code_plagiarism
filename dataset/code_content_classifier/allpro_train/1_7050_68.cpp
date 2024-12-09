#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, m;
int g[maxn];
int v[maxn];
int b[maxn];
bool died[maxn];
bool know[maxn];
int cnt[maxn];
int res = 0;
int over, len;
void go(int x, int life) {
  know[x] = 1;
  if (died[x] == false) res++, died[x] = 1;
  life -= cnt[x];
  if (life <= 0) {
    over = g[x], len = cnt[x];
  } else {
    if (g[x] == -1 || know[g[x]]) {
      over = -1, len = cnt[x];
    } else {
      go(g[x], life);
      len += cnt[x];
      g[x] = over, cnt[x] = len;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &g[i]), cnt[i] = 1;
  for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  memset(died, 0, sizeof(died));
  for (int i = 1; i <= m; i++) {
    int who = (v[i] + res - 1) % n + 1;
    res = 0;
    memset(know, 0, sizeof(know));
    go(who, b[i]);
    printf("%d\n", res);
  }
  return 0;
}
