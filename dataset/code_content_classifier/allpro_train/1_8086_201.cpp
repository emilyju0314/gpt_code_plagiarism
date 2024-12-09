#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxx = 100000 + 5;
struct node {
  int l, r;
} x[maxx];
int cnt = 1;
int vis[maxx];
bool ok(int a, int b) {
  if (x[b].l < x[a].l && x[a].l < x[b].r) return true;
  if (x[b].l < x[a].r && x[a].r < x[b].r) return true;
  return false;
}
bool dfs(int a, int b) {
  if (a == b) return true;
  vis[a] = 1;
  for (int i = 1; i < cnt; i++) {
    if (!vis[i] && ok(a, i) && dfs(i, b)) {
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    cnt = 1;
    int q, a, b;
    for (int i = 0; i < n; i++) {
      memset(vis, 0, sizeof(vis));
      scanf("%d%d%d", &q, &a, &b);
      if (q == 1) {
        x[cnt].l = a, x[cnt++].r = b;
      } else {
        if (dfs(a, b))
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
  }
}
