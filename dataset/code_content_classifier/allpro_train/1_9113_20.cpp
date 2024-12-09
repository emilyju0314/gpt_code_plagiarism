#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
} eg[500010];
struct node {
  int v, fr, w;
} e[500010 << 1];
int n, m, K, col[500010], tail[500010], cnt = 0, nosum = 0, block_col[500010];
int fa[500010], dep[500010], hav = 0, bw[500010], fro[500010], tot = 0,
                             new_col[500010];
int label[500010], now = 0;
bool tag[500010], no[500010];
long long ans = 0;
vector<int> to[500010];
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? 1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
inline void add(int u, int v, int w) {
  e[++cnt] = (node){v, tail[u], w};
  tail[u] = cnt;
}
void dfs(int x, int color) {
  if (no[color]) return;
  tag[x] = 1, fro[x] = tot;
  for (int p = tail[x], v; p; p = e[p].fr) {
    if (col[x] != col[v = e[p].v]) continue;
    if (!tag[v])
      bw[v] = bw[x] ^ 1, dfs(v, color);
    else if (bw[v] == bw[x]) {
      no[color] = 1;
      return;
    }
  }
}
inline bool cmp(edge x, edge y) {
  return col[x.u] == col[y.u] ? col[x.v] < col[y.v] : col[x.u] < col[y.u];
}
bool check(int x) {
  label[x] = now;
  for (int p = tail[x], v; p; p = e[p].fr) {
    v = e[p].v;
    if (!new_col[v]) {
      new_col[v] = new_col[x] ^ e[p].w;
      if (!check(v)) return 0;
    } else {
      if (new_col[v] == (new_col[x] ^ e[p].w)) continue;
      if (label[v] != now) {
        new_col[v] = new_col[x] ^ e[p].w;
        if (!check(v)) return 0;
      } else
        return 0;
    }
  }
  return 1;
}
void calc(int col_1, int col_2) {
  int len = to[col_1].size() - 1;
  for (int i = (0); i <= (len); i++) {
    if (!new_col[to[col_1][i]]) {
      new_col[to[col_1][i]] = 2;
      now++;
      if (!check(to[col_1][i])) {
        ans--;
        break;
      }
    }
  }
  for (int i = (0); i <= (len); i++)
    tail[to[col_1][i]] = new_col[to[col_1][i]] = 0;
  len = to[col_2].size() - 1;
  for (int i = (0); i <= (len); i++)
    tail[to[col_2][i]] = new_col[to[col_2][i]] = 0;
  cnt = 0;
}
int main() {
  n = read(), m = read(), K = read();
  for (int i = (1); i <= (n); i++) col[i] = read();
  for (int i = (1); i <= (m); i++) {
    int u = read(), v = read();
    add(u, v, -1), add(v, u, -1);
    if (col[u] == col[v]) continue;
    if (col[u] < col[v])
      eg[++hav] = (edge){u, v};
    else
      eg[++hav] = (edge){v, u};
  }
  for (int i = (1); i <= (n); i++) {
    if (tag[i] || no[col[i]]) continue;
    ++tot, block_col[tot] = col[i];
    to[col[i]].push_back(tot), dfs(i, col[i]);
    if (no[col[i]]) nosum++;
  }
  ans = (long long)(K - nosum) * (K - nosum - 1) / 2;
  sort(eg + 1, eg + hav + 1, cmp);
  memset(tail, 0, sizeof tail), cnt = 0;
  int col_1 = 0, col_2 = 0;
  for (int i = (1); i <= (hav); i++) {
    if (no[col[eg[i].u]] || no[col[eg[i].v]]) continue;
    if ((col[eg[i].u] != col_1 || col[eg[i].v] != col_2) && col_1) {
      calc(col_1, col_2), col_1 = col_2 = 0;
    }
    col_1 = col[eg[i].u], col_2 = col[eg[i].v];
    if (bw[eg[i].u] != bw[eg[i].v])
      add(fro[eg[i].u], fro[eg[i].v], 0), add(fro[eg[i].v], fro[eg[i].u], 0);
    else
      add(fro[eg[i].u], fro[eg[i].v], 1), add(fro[eg[i].v], fro[eg[i].u], 1);
  }
  calc(col_1, col_2);
  printf("%lld\n", ans);
  return 0;
}
