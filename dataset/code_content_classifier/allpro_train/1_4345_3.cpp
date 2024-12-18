#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const long long INF = 1e18;
vector<int> g[N], path;
int col[N], second[N], t[N];
int n, m, k;
int cntv[N], cntu[N];
bool was[N];
void dfs(int v, int a, int b) {
  for (auto it : g[v]) {
    int u = second[it] ^ t[it] ^ v;
    if (!was[it] && col[it] == a) {
      was[it] = 1;
      path.push_back(it);
      dfs(u, b, a);
      break;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    int richard;
    scanf("%d", &richard);
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v, --u;
    for (int j = 0; j < k; j++) cntv[j] = cntu[j] = 0;
    for (auto it : g[v]) cntv[col[it]]++;
    for (auto it : g[u]) cntu[col[it]]++;
    int mnv = inf, mnu = inf;
    for (int j = 0; j < k; j++) {
      mnv = min(mnv, cntv[j]);
      mnu = min(mnu, cntu[j]);
    }
    int a = -1, b = -1, c = -1;
    for (int j = 0; j < k; j++) {
      int cv = cntv[j] - mnv;
      int cu = cntu[j] - mnu;
      if (cv == 0 && cu == 2) a = j;
      if (cv == 2 && cu == 0) b = j;
      if (cv != 2 && cu != 2) c = j;
    }
    if (c == -1) {
      for (int j = 0; j < m; j++) was[j] = 0;
      path.clear();
      dfs(u, a, b);
      for (auto it : path) col[it] ^= (a ^ b);
      c = a;
    }
    col[i] = c;
    second[i] = v, t[i] = u;
    g[v].push_back(i);
    g[u].push_back(i);
  }
  for (int i = 0; i < m; i++) printf("%d\n", col[i] + 1);
  return 0;
}
