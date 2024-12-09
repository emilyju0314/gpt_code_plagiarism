#include <bits/stdc++.h>
using namespace std;
int n, m, q, cnt, top, zh, qwq;
int tot = 1, head[100005], nx[1000005], to[1000005];
int low[100005], dfx[100005], vis[100005], zhan[100005];
int TOT, HEAD[200005], NX[1000005], TO[1000005];
int dep[200005], dis[200005], st[400005][21], id[200005];
int read() {
  char ch = getchar();
  int x = 0, ff = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * ff;
}
void write(int aa) {
  if (aa < 0) putchar('-'), aa = -aa;
  if (aa > 9) write(aa / 10);
  putchar(aa % 10 + '0');
  return;
}
void jia(int aa, int bb) {
  tot++;
  nx[tot] = head[aa];
  to[tot] = bb;
  head[aa] = tot;
  return;
}
void JIA(int AA, int BB) {
  TOT++;
  NX[TOT] = HEAD[AA];
  TO[TOT] = BB;
  HEAD[AA] = TOT;
  return;
}
void tajan(int rt, int fa) {
  dfx[rt] = ++cnt;
  low[rt] = cnt;
  zhan[++top] = rt;
  vis[rt] = 1;
  for (int i = head[rt]; i; i = nx[i]) {
    int yy = to[i];
    if (yy == fa) continue;
    if (!dfx[yy]) {
      tajan(yy, rt);
      low[rt] = min(low[rt], low[yy]);
      if (low[yy] >= dfx[rt]) {
        zh++;
        while (zhan[top] != yy) {
          int kk = zhan[top];
          JIA(kk, n + zh);
          JIA(n + zh, kk);
          vis[kk] = 0;
          top--;
        }
        JIA(yy, n + zh);
        JIA(n + zh, yy);
        vis[yy] = 0;
        top--;
        JIA(rt, n + zh);
        JIA(n + zh, rt);
      }
    } else if (vis[yy])
      low[rt] = min(low[rt], dfx[yy]);
  }
  return;
}
void dfs(int rt, int fa, int ndep, int ndis) {
  st[++qwq][0] = rt;
  id[rt] = qwq;
  dep[rt] = ndep;
  dis[rt] = ndis;
  for (int i = HEAD[rt]; i; i = NX[i]) {
    int yy = TO[i];
    if (yy == fa) continue;
    dfs(yy, rt, ndep + 1, ndis + (yy <= n));
    st[++qwq][0] = rt;
  }
  return;
}
int mn(int aa, int bb) { return dep[aa] < dep[bb] ? aa : bb; }
void init() {
  for (int i = 1; (1 << i) <= qwq; ++i)
    for (int j = 1; j + (1 << i) - 1 <= qwq; ++j) {
      st[j][i] = mn(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
  return;
}
int getlca(int ll, int rr) {
  if (ll > rr) swap(ll, rr);
  int len = rr - ll + 1, oo = 0;
  while (1 << (oo + 1) <= len) oo++;
  return mn(st[ll][oo], st[rr - (1 << oo) + 1][oo]);
}
int main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    jia(x, y);
    jia(y, x);
  }
  tajan(1, 1);
  dfs(1, 1, 1, 1);
  init();
  while (q--) {
    int x = read(), y = read();
    int lc = getlca(id[x], id[y]);
    write(dis[x] + dis[y] - dis[lc] * 2 - (lc > n));
    puts("");
  }
  return 0;
}
