#include <bits/stdc++.h>
int N, K, head[55], lk[10005], next[10005], w[10005], c[10005], d[55], p[55],
    q[100005];
bool b[55];
void add(int u, int v, int x, int y, int& t) {
  lk[++t] = v, c[t] = x, w[t] = y, next[t] = head[u], head[u] = t;
  lk[++t] = u, c[t] = 0, w[t] = -y, next[t] = head[v], head[v] = t;
}
void init() {
  scanf("%d%d", &N, &K);
  for (int i = 1, t = 1; i <= N; i++)
    for (int j = 1, x; j <= N; j++) {
      scanf("%d", &x);
      if (x) add(i, j, x, 0, t), add(i, j, 1e9, 1, t);
    }
}
bool spfa() {
  memset(d, 63, sizeof(d));
  q[1] = 1, d[1] = 0;
  for (int l = 1, r = 1; l <= r; l++) {
    int u = q[l];
    b[u] = 0;
    for (int i = head[u], v; v = lk[i], i; i = next[i])
      if (c[i] && d[u] + w[i] < d[v]) {
        d[v] = d[u] + w[i], p[v] = i;
        if (!b[v]) b[v] = 1, q[++r] = v;
      }
  }
  return d[N] < 1e9;
}
void doit() {
  int flow = 0;
  for (; spfa();) {
    int f = 1e9;
    for (int i = N; i != 1; i = lk[p[i] ^ 1]) f = std::min(f, c[p[i]]);
    for (int i = N; i != 1; i = lk[p[i] ^ 1]) c[p[i]] -= f, c[p[i] ^ 1] += f;
    if (1ll * f * d[N] <= K)
      K -= f * d[N], flow += f;
    else {
      flow += K / d[N], K = 0;
      break;
    }
  }
  printf("%d\n", flow);
}
int main() {
  init();
  doit();
  return 0;
}
