#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e2 + 10;
const int INF = 1e8 + 100;
int dp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];
int memo(int r, int d, int R) {
  if (vis[r][d][R]) return dp[r][d][R];
  vis[r][d][R] = true;
  int D = r + d - R;
  int &res = dp[r][d][R];
  res = -INF;
  if (r + d == 0) {
    res = a[0][0];
    return res;
  }
  int temp = a[r][d] + a[R][D];
  if (R == r) temp = a[r][d];
  if (r && R) res = max(res, temp + memo(r - 1, d, R - 1));
  if (r && D) res = max(res, temp + memo(r - 1, d, R));
  if (d && R) res = max(res, temp + memo(r, d - 1, R - 1));
  if (d && D) res = max(res, temp + memo(r, d - 1, R));
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  cout << memo(n - 1, n - 1, n - 1);
}
