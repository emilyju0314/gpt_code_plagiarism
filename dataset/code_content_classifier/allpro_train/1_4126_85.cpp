#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 10;
long long dp[MAX][2], qt;
int v[MAX], freq[MAX];
void insert(int p) {
  qt += freq[v[p]];
  freq[v[p]]++;
}
void erase(int p) {
  freq[v[p]]--;
  qt -= freq[v[p]];
}
long long query(int l, int r) {
  static int L = 0, R = 0;
  r++;
  while (L > l) insert(--L);
  while (R < r) insert(R++);
  while (L < l) erase(L++);
  while (R > r) erase(--R);
  return qt;
}
void solve(int k, int l, int r, int lk, int rk) {
  if (l > r) return;
  int m = (l + r) / 2, p = -1;
  long long& ans = dp[m][k & 1] = LINF;
  for (int i = lk; i <= min(rk, m); i++) {
    long long at = dp[i - 1][~k & 1] + query(i, m);
    if (at < ans) ans = at, p = i;
  }
  solve(k, l, m - 1, lk, p), solve(k, m + 1, r, p, rk);
}
long long DC(int n, int k) {
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) dp[i][0] = LINF;
  for (int i = 1; i <= k; i++) solve(i, i, n, i, n);
  return dp[n][k & 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> v[i];
  cout << DC(n, k) << '\n';
  exit(0);
}
