#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int lim = 20;
struct node {
  int u, to;
} E[maxn << 1];
int head[maxn], cnt, dep[maxn], n, m;
int anc[maxn][lim];
inline void add(int x, int y) {
  cnt++;
  E[cnt].u = y;
  E[cnt].to = head[x];
  head[x] = cnt;
  return;
}
inline void update(int x, int fx) {
  anc[x][0] = fx;
  for (int i = 1; i < lim; ++i) {
    anc[x][i] = anc[anc[x][i - 1]][i - 1];
  }
  dep[x] = dep[fx] + 1;
  return;
}
inline void swim(int &x, int h) {
  for (int i = 0; h > 0; ++i) {
    if (h & 1) {
      x = anc[x][i];
    }
    h >>= 1;
  }
  return;
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  swim(x, dep[x] - dep[y]);
  if (x == y) return x;
  for (int i = lim - 1; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  return anc[x][0];
}
void dfs(int u, int fa) {
  for (int i = head[u]; i > 0; i = E[i].to) {
    int v = E[i].u;
    if (v == fa) continue;
    update(v, u);
    dfs(v, u);
  }
  return;
}
int get_len(int x, int y) {
  int xy = lca(x, y);
  return dep[x] + dep[y] - dep[xy] - dep[xy];
}
int k;
bool judge(int x) { return (x <= k && ((x - k) % 2 == 0)); }
void sol() {
  int x, y, a, b;
  int len;
  while (m--) {
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    bool flag = false;
    len = get_len(a, b);
    flag |= judge(len);
    len = get_len(a, x) + 1 + get_len(b, y);
    flag |= judge(len);
    len = get_len(a, y) + 1 + get_len(b, x);
    flag |= judge(len);
    len = get_len(a, x) + get_len(x, y) + get_len(y, b);
    flag |= judge(len);
    len = get_len(a, y) + get_len(x, y) + get_len(x, b);
    flag |= judge(len);
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) head[i] = -1;
  dep[1] = 0;
  cnt = 0;
  int x, y;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 1);
  scanf("%d", &m);
  sol();
  return 0;
}
