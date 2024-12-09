#include <bits/stdc++.h>
using namespace std;
const int kN = 1510;
const int kM = 1e6 + 10;
const int kMod = 998244353;
const int kInf = 1e9;
int p[kM], q[kM];
vector<int> pos[kN];
int low[kN][kN];
int dp[kN][kN];
bool vis[kN][kN];
void add(int &a, int b) {
  a += b;
  if (a >= kMod) a -= kMod;
}
int dfs(int l, int r) {
  if (l == r) return 1;
  if (vis[l][r]) return dp[l][r];
  vis[l][r] = 1;
  int le = 0, ri = 0;
  int c = low[l][r];
  int x_mn = pos[c][0], x_mx = pos[c].back();
  if (x_mn < l || x_mx >= r) return dp[l][r] = 0;
  for (int i = l; i <= x_mn; i++)
    add(le, 1LL * dfs(l, i) * dfs(i, x_mn) % kMod);
  for (int i = x_mx + 1; i <= r; i++)
    add(ri, 1LL * dfs(x_mx + 1, i) * dfs(i, r) % kMod);
  dp[l][r] = 1LL * le * ri % kMod;
  for (int i = 0; i < int(pos[c].size()) - 1; i++)
    dp[l][r] = 1LL * dp[l][r] * dfs(pos[c][i] + 1, pos[c][i + 1]) % kMod;
  return dp[l][r];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", p + i), p[i]--;
  int M = 0;
  for (int i = 0; i < m; i++) {
    if (M == 0 || p[i] != q[M - 1]) q[M++] = p[i];
    if (M >= 2 * n + 10) break;
  }
  m = M;
  if (m >= 2 * n + 10) return puts("0"), 0;
  for (int i = 0; i < m; i++) pos[q[i]].push_back(i);
  for (int i = 0; i < m; i++) {
    int mn = kInf;
    for (int j = i; j < m; j++) {
      mn = min(mn, q[j]);
      low[i][j + 1] = mn;
    }
  }
  printf("%d\n", dfs(0, m));
  return 0;
}
