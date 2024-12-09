#include <bits/stdc++.h>
using namespace std;
int st[610], aim[(300010)], nxt[(300010)], ln;
int flow[(300010)], con[(300010)], cost[(300010)];
int inq[610], dis[610];
int g[610], e[610];
int q[610];
int a[610];
int d[610 << 3], tag[610 << 3], dn;
int num[610];
int N, source, remit;
int ans;
int n, m;
void in_edge(int x, int y, int f, int c) {
  aim[ln] = y;
  nxt[ln] = st[x];
  flow[ln] = 0;
  con[ln] = f;
  cost[ln] = c;
  st[x] = ln++;
  aim[ln] = x;
  nxt[ln] = st[y];
  flow[ln] = con[ln] = 0;
  cost[ln] = -c;
  st[y] = ln++;
}
int calc(int x) {
  int ret = 0;
  while (x) ret += (x & 1), x >>= 1;
  return ret;
}
int spfa() {
  int qn = 1;
  for (int i = 0; i <= remit; i++) dis[i] = (10000000);
  memset(inq, 0, sizeof(inq));
  dis[source] = 0;
  inq[source] = 1;
  q[0] = source;
  for (int p = 0; p != qn;) {
    int u = q[p];
    p++;
    if (p == 610) p = 0;
    inq[u] = 0;
    for (int i = st[u]; i != -1; i = nxt[i])
      if (flow[i] < con[i]) {
        int v = aim[i];
        if (dis[u] + cost[i] < dis[v]) {
          dis[v] = dis[u] + cost[i];
          g[v] = u;
          e[v] = i;
          if (!inq[v]) {
            inq[v] = 1;
            q[qn] = v;
            ++qn;
            if (qn == 610) qn = 0;
          }
        }
      }
  }
  if (dis[remit] == (10000000)) return 0;
  int delta = (10000000);
  for (int i = remit; i != source; i = g[i])
    delta = min(delta, con[e[i]] - flow[e[i]]);
  for (int i = remit; i != source; i = g[i]) {
    int x = e[i];
    flow[x] += delta;
    flow[x ^ 1] -= delta;
  }
  ans += delta * dis[remit];
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  source = n + n + m;
  remit = source + 1;
  memset(st, -1, sizeof(st));
  ln = 0;
  for (int i = 0; i < m; i++) in_edge(source, (n << 1) + i, 1, 0);
  for (int i = 0; i < n; i++) {
    in_edge(source, n + i, 1, 0);
    in_edge(i, remit, 1, 0);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) in_edge((n << 1) + i, j, 1, calc(a[j]));
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] == a[j])
        in_edge(n + i, j, 1, 0);
      else
        in_edge(n + i, j, 1, calc(a[j]));
  ans = 0;
  while (spfa())
    ;
  int dn = 0;
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = st[i]; j != -1; j = nxt[j])
      if (flow[j] < con[j]) {
        int v = aim[j];
        if (v >= (n << 1) && v < source) {
          tag[dn] = 0;
          d[dn++] = i;
          tag[dn] = 1;
          d[dn++] = v - (n << 1);
          num[i] = v - (n << 1);
        } else if (v >= n && v <= (n << 1)) {
          int p = v - n;
          if (a[p] != a[i]) {
            tag[dn] = 0;
            d[dn++] = i;
          }
          tag[dn] = 1;
          d[dn++] = num[p];
          num[i] = num[p];
        }
      }
  }
  printf("%d %d\n", dn, ans);
  for (int i = 0; i < dn; i++)
    if (!tag[i]) {
      printf("%c=%d\n", 'a' + num[d[i]], a[d[i]]);
    } else {
      printf("print(%c)\n", 'a' + d[i]);
    }
  return 0;
}
