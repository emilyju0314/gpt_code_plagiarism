#include <bits/stdc++.h>
using namespace std;
int dis[233333], dis2[233333], f[233333], dep[233333], hed[233333];
int a;
int x, y, k, n, m;
struct edge {
  int f, to, val, nxt;
} e[233333 << 1];
void ADD_edge(int x, int y, int k) {
  e[a].f = x;
  e[a].nxt = hed[x];
  e[a].to = y;
  e[a].val = k;
  hed[x] = a++;
}
void updata(int id, int k) {
  if (id < n) {
    dis2[e[id].to] = k;
  }
  int v = e[id].f;
  e[id].val = k;
  int tmp = 0x3f3f3f3f;
  while (v != 1) {
    for (int i = hed[v]; ~i; i = e[i].nxt) {
      int w = e[i].to;
      if (w == 1) tmp = e[i].val;
      if (dep[w] < dep[v]) continue;
      tmp = min(tmp, dis[w] + e[i].val);
    }
    if (tmp == dis[v]) {
      break;
    } else {
      dis[v] = tmp;
      v = f[v];
    }
  }
}
void dfs(int n) {
  for (int i = hed[n]; ~i; i = e[i].nxt) {
    int v = e[i].to;
    if (dep[v] > 0) continue;
    dep[v] = dep[n] + 1;
    dis2[v] = e[i].val;
    dfs(v);
    dis[n] = min(dis[v] + e[i].val, dis[n]);
  }
}
int quear(int x, int y) {
  int ans = 0;
  int v = y;
  if (dep[x] <= dep[y]) {
    while (dep[x] < dep[v]) {
      ans += dis2[v];
      v = f[v];
    }
    if (x == v) {
      return ans;
    }
  }
  while (v != 1) {
    ans += dis2[v];
    v = f[v];
  }
  return dis[x] + ans;
}
int main() {
  a = 1;
  cin >> n >> m;
  memset((dis), (0x3f), sizeof(dis));
  memset((hed), (-1), sizeof(hed));
  memset((f), (-1), sizeof(f));
  dis[1] = 0;
  dep[1] = 1;
  for (int(i) = 0; (i) < n - 1; (i)++) {
    scanf("%d%d%d", &x, &y, &k);
    f[y] = x;
    ADD_edge(x, y, k);
  }
  for (int(i) = 0; (i) < n - 1; (i)++) {
    scanf("%d%d%d", &x, &y, &k);
    dis[x] = k;
    ADD_edge(x, y, k);
  }
  dfs(1);
  for (int(i) = 0; (i) < m; (i)++) {
    scanf("%d%d%d", &x, &y, &k);
    if (x == 1) {
      updata(y, k);
    } else {
      printf("%d\n", quear(y, k));
    }
  }
}
