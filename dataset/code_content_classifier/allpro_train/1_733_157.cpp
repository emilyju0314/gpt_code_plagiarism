#include <bits/stdc++.h>
using namespace std;
struct EE {
  int x, bit;
};
const int maxN = 1e5 * 3 + 10;
int n, m, k, M;
int a[20], d[20][20];
long long R[maxN][20];
EE E[maxN];
int dembit(int k) {
  int res = 0;
  for (int i = 0; i <= 20; i++) res += 1 & (k >> i);
  return res;
}
bool cmp(EE X, EE Y) { return X.bit < Y.bit; }
int laybit(int t, int i) { return 1 & (t >> i); }
int tatbit(int t, int i) {
  t = t & (~(1 << i));
  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) d[i][j] = 0;
  for (int i = 1; i <= k; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    d[--u][--v] = c;
  }
  M = 1 << n;
  for (int i = 0; i < M; i++) {
    E[i].x = i;
    E[i].bit = dembit(i);
  }
  for (int i = 0; i < M; i++)
    for (int j = 0; j <= n; j++) R[i][j] = -1;
  sort(E, E + M, cmp);
  int t = 1;
  while (E[t].bit == 1) {
    int u = E[t].x;
    for (int i = 0; i < n; i++)
      if (laybit(u, i) == 1) R[u][i] = a[i];
    t++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, (long long)a[i]);
  while (E[t].bit <= m) {
    int u = E[t].x;
    for (int i = 0; i < n; i++)
      if (laybit(u, i) == 1) {
        int v = tatbit(u, i);
        for (int j = 0; j < n; j++)
          if (i != j && R[v][j] > -1)
            R[u][i] = max(R[u][i], R[v][j] + a[i] + d[j][i]);
        if (E[t].bit == m) ans = max(ans, R[u][i]);
      }
    t++;
    if (t == M) break;
  }
  cout << ans;
}
