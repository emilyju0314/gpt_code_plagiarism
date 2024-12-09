#include <bits/stdc++.h>
using namespace std;
int Read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 5005, M = 200005;
int n, m, K, ecnt;
int delta[M], col[M];
struct Edge {
  int u, v, w, id, val;
} e[M];
bool cmp(Edge a, Edge b) {
  if (a.val ^ b.val)
    return a.val < b.val;
  else
    return col[a.id] > col[b.id];
}
int fa[N];
int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
int Check(int del) {
  for (int i = 1; i <= m; ++i) e[i].val = e[i].w + col[e[i].id] * del;
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  int res = 0, cnt = 1;
  for (int i = 1; i <= m && cnt <= n - 1; ++i) {
    int x = e[i].u, y = e[i].v;
    x = gf(x), y = gf(y);
    if (x ^ y) fa[x] = y, ++cnt, res += col[e[i].id];
  }
  if (cnt != n)
    return -1;
  else
    return res;
}
int ans[N], tot;
void print() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  int res = 0, cnt = 1;
  for (int i = 1; i <= m && cnt <= n - 1; ++i) {
    int j = i;
    while (e[j + 1].val == e[i].val) ++j;
    for (int k = i; k <= j; ++k) {
      if (res == K && col[e[k].id]) continue;
      int x = e[k].u, y = e[k].v;
      x = gf(x), y = gf(y);
      if (x ^ y) fa[x] = y, ++cnt, res += col[e[k].id], ans[++tot] = e[k].id;
    }
    i = j;
  }
  if (cnt ^ n)
    puts("-1");
  else {
    printf("%d\n", n - 1);
    for (int i = 1; i <= tot; ++i) printf("%d ", ans[i]);
  }
}
int main() {
  n = Read(), m = Read(), K = Read();
  for (int i = 1, x, y, z; i <= m; ++i)
    e[i].u = Read(), e[i].v = Read(), e[i].w = Read(), e[i].id = i,
    col[i] = e[i].u == 1 || e[i].v == 1;
  int l = -100000, r = 100000, an = -200000;
  while (l <= r) {
    int md = l + r >> 1;
    int tmp = Check(md);
    if (tmp >= K)
      an = md, l = md + 1;
    else
      r = md - 1;
  }
  if (an == -200000)
    puts("-1");
  else
    Check(an), print();
  return 0;
}
