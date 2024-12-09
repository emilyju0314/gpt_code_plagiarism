#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int f = 1, sum = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 3) + (sum << 1) + ch - '0';
    ch = getchar();
  }
  return f * sum;
}
const int N = 500010;
int n, m, f[N];
struct node {
  int u, v, w, id, a, b;
} e[N], edg[N];
bool cmp(node a, node b) { return a.w < b.w; }
bool cmpid(node a, node b) { return a.id < b.id; }
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
int main() {
  n = gi();
  m = gi();
  for (int i = 1; i <= m; i++)
    e[i].u = gi(), e[i].v = gi(), e[i].w = gi(), e[i].id = i;
  for (int i = 1; i <= n; i++) f[i] = i;
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int pos = i;
    while (e[pos].w == e[i].w) pos++;
    pos--;
    for (int j = i; j <= pos; j++) e[j].a = find(e[j].u), e[j].b = find(e[j].v);
    for (int j = i; j <= pos; j++)
      if (find(e[j].u) != find(e[j].v)) f[find(e[j].u)] = find(e[j].v);
    i = pos;
  }
  sort(e + 1, e + m + 1, cmpid);
  int Q = gi();
  while (Q--) {
    int S = gi(), flag = 0;
    for (int i = 1; i <= S; i++) edg[i] = e[gi()];
    sort(edg + 1, edg + S + 1, cmp);
    for (int i = 1; i <= S; i++) f[edg[i].a] = edg[i].a, f[edg[i].b] = edg[i].b;
    for (int i = 1; i <= S; i++) {
      if (find(edg[i].a) == find(edg[i].b)) {
        flag = 1;
        break;
      }
      f[find(edg[i].a)] = find(edg[i].b);
    }
    if (!flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
