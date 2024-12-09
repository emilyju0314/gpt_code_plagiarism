#include <bits/stdc++.h>
using namespace std;
const int N = 201110, T = 510;
struct Quer {
  int l, r, id;
} quer[N];
int s[N], DP[N], P[N], res[N];
vector<int> G[N];
int n, m, Q;
bool comp(Quer u, Quer v) { return u.r < v.r; }
void update(int x, int v) {
  for (; x <= n; x += x & -x) s[x] = max(s[x], v);
}
int getMax(int x) {
  int ans = 0;
  for (; x > 0; x -= x & -x) ans = max(ans, s[x]);
  return ans;
}
void reset(int k) {
  memset(s, 0, sizeof(s));
  update(k, k);
  for (int u = k - 1; u >= 1; u--) {
    DP[u] = u;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (v <= k) DP[u] = max(DP[u], getMax(v));
    }
    update(u, DP[u]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) P[i] = i;
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    P[v] = u;
    G[u].push_back(v);
  }
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &quer[i].l, &quer[i].r);
    quer[i].id = i;
  }
  sort(quer + 1, quer + Q + 1, comp);
  int k = 0;
  for (int i = 1; i <= n; i++) DP[i] = i;
  for (int i = 1; i <= Q; i++) {
    while (k < quer[i].r) {
      k++;
      if (k % T == 0) reset(k);
    }
    res[quer[i].id] = DP[quer[i].l];
    for (int j = (k / T) * T + 1; j <= quer[i].r; j++)
      if (P[j] >= quer[i].l && P[j] <= res[quer[i].id]) res[quer[i].id] = j;
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", res[i]);
}
