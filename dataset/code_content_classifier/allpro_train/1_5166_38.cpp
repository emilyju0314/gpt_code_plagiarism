#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
int n, m, d[MAXN], dp[2][MAXN];
int c[MAXN];
int lowbit(int x) { return x & (-x); }
void update(int x, int k) {
  x++;
  for (int i = x; i < MAXN; i += lowbit(i)) c[i] = max(c[i], k);
}
int query(int x) {
  x++;
  int ans = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ans = max(ans, c[i]);
  return ans;
}
void cal(int d[], int dp[]) {
  memset(c, 0, sizeof c);
  for (int i = 1; i <= m; i++) {
    int pre = query(d[i]);
    dp[i] = pre + 1;
    update(d[i], dp[i]);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    d[l]++;
    d[r + 1]--;
  }
  for (int i = 1; i <= m; i++) d[i] += d[i - 1];
  cal(d, dp[0]);
  reverse(d + 1, d + 1 + m);
  cal(d, dp[1]);
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, dp[0][i] + dp[1][m - i + 1] - 1);
  cout << ans << endl;
  return 0;
}
