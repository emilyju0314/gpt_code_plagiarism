#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;
struct eT {
  void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
  int u, v, last;
} edge[MAXN];
int n, t, k, ke;
int a[MAXN];
int la[MAXN];
int pl[MAXN], pr[MAXN], lev[MAXN];
int en[MAXN];
void init();
void input();
void work();
void addedge(int u, int v) {
  edge[ke].setd(u, v, la[u]);
  la[u] = ke++;
}
void dfs(int now) {
  for (int i = la[now]; i ^ -1; i = edge[i].last) {
    printf("%d %d\n", edge[i].u, edge[i].v);
    dfs(edge[i].v);
  }
}
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d%d", &n, &t, &k);
  for (int i = 1; i <= t; ++i) scanf("%d", &a[i]);
}
void work() {
  pl[0] = pr[0] = 1;
  lev[1] = 0;
  for (int i = 1; i <= t; ++i) {
    pl[i] = pr[i - 1] + 1;
    pr[i] = pl[i] + a[i] - 1;
    for (int j = pl[i]; j <= pr[i]; ++j) lev[j] = i;
  }
  memset(en, 0, sizeof(en));
  memset(la, -1, sizeof(la));
  ke = 1;
  a[0] = 1;
  for (int i = 1; i < t; ++i) {
    if (a[i] > a[i + 1]) {
      en[i] = a[i] - a[i + 1];
      k -= en[i];
    }
  }
  en[t] = a[t];
  k -= en[t];
  if (k < 0) {
    printf("-1\n");
    return;
  }
  int del;
  for (int i = 1; i < t; ++i) {
    del = (((a[i] - en[i] - 1) < (k)) ? (a[i] - en[i] - 1) : (k));
    en[i] += del;
    k -= del;
    if (!k) break;
  }
  if (k) {
    printf("-1\n");
    return;
  }
  en[0] = 0;
  int tto, nid;
  for (int i = 0; i < t; ++i) {
    tto = pr[i] - en[i];
    nid = pl[i + 1];
    for (int j = pl[i]; j <= tto; ++j) {
      addedge(j, nid++);
    }
    while (nid <= pr[i + 1]) addedge(pl[i], nid++);
  }
  printf("%d\n", n);
  dfs(1);
}
