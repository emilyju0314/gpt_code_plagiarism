#include <bits/stdc++.h>
using namespace std;
enum STATE { IN, OUT, BOUNDRY };
const double PI = acos(-1.0);
void fast_in_out() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int lx[] = {2, 2, -1, 1, -2, -2, -1, 1};
int ly[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int N = 16, M = 1e4 + 10, mod = 1e4;
const double eps = 1e-9;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, m;
bool adj1[N][N], adj2[N][N];
int ar[N][M], vid;
int mn1[N][N], mn2[N][N];
int vis[N][(1 << N)];
bool dp[N][(1 << N)];
bool solve(int ind, int st, int mask) {
  if (mask == (1 << n) - 1) {
    return adj2[st][ind];
  }
  bool &ret = dp[ind][mask];
  if (vis[ind][mask] == vid) return ret;
  vis[ind][mask] = vid;
  ret = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) continue;
    if (adj1[ind][i]) ret |= solve(i, st, mask | (1 << i));
  }
  return ret;
}
bool check(int k) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      adj1[i][j] = (mn1[i][j] >= k);
      adj2[i][j] = (mn2[i][j] >= k);
    }
  for (int i = 0; i < n; i++) {
    ++vid;
    if (solve(i, i, 1 << i)) return 1;
  }
  return 0;
}
int main() {
  fast_in_out();
  cout << fixed << setprecision(2);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ar[i][j];
  if (n == 1) {
    int ans = 1e9;
    for (int i = 1; i < m; i++) ans = min(ans, abs(ar[0][i] - ar[0][i - 1]));
    cout << ans;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      mn1[i][j] = mn2[i][j] = 2e9;
      for (int k = 0; k < m; k++)
        mn1[i][j] = min(mn1[i][j], abs(ar[i][k] - ar[j][k]));
      for (int k = 1; k < m; k++)
        mn2[i][j] = min(mn2[i][j], abs(ar[i][k - 1] - ar[j][k]));
    }
  }
  int s = 0, e = 1e9, ret = 0;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (check(mid)) {
      s = mid + 1;
      ret = mid;
    } else {
      e = mid - 1;
    }
  }
  cout << ret;
  return 0;
}
