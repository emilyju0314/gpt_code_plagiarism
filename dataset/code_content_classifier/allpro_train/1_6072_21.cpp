#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210, INF = 1e9;
vector<int> e[MAXN];
int n, k, w[MAXN], u, v;
int f[MAXN][MAXN], depth[MAXN];
int tmp[MAXN], ans;
void pre(int u, int fa) {
  for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
    int v = *it;
    if (v == fa) continue;
    depth[v] = depth[u] + 1;
    pre(v, u);
  }
}
void dp(int u, int fa) {
  for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
    int v = *it;
    if (v == fa) continue;
    dp(v, u);
  }
  f[u][0] = w[u];
  for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
    int v = *it;
    if (v == fa) continue;
    for (long long i = (0); i <= (n + 1); i++) {
      tmp[i] = f[u][i];
    }
    for (long long i = (0); i <= (n + 1); i++) f[u][i] = 0;
    for (long long x = (0); x <= (n + 1); x++) {
      int L = (0 > k - x ? 0 : k - x);
      L = (L > x - 1 ? L : x - 1);
      f[u][x] = (f[u][x] > tmp[x] + f[v][L] ? f[u][x] : tmp[x] + f[v][L]);
    }
    for (long long y = (1); y <= (n + 1); y++) {
      int L = (0 > k - y + 1 ? 0 : k - y + 1);
      L = (L > y ? L : y);
      f[u][y] =
          (f[u][y] > tmp[L] + f[v][y - 1] ? f[u][y] : tmp[L] + f[v][y - 1]);
    }
  }
  for (long long i = (n); i >= (0); i--) {
    f[u][i] = (f[u][i] > f[u][i + 1] ? f[u][i] : f[u][i + 1]);
  }
}
int main() {
  cin >> n >> k;
  for (long long i = (1); i <= (n); i++) {
    cin >> w[i];
  }
  for (long long i = (1); i <= (n - 1); i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  depth[1] = 1;
  pre(1, 0);
  dp(1, 0);
  cout << f[1][0];
  return 0;
}
