#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void XsliferX() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
long long f_p(long long x, int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return f_p(x * x, y / 2);
  else
    return x * f_p(x * x, y / 2);
}
long long l_p(long long n) {
  n = n | (n >> 1);
  n = n | (n >> 2);
  n = n | (n >> 4);
  n = n | (n >> 8);
  return (n + 1) >> 1;
}
int dp[5005];
int a[5005];
int n;
int L[5005], R[5005];
bool vis[5005];
int solve(int idx) {
  int x = 0;
  int lft = L[a[idx]], rit = R[a[idx]];
  if (idx == n) return 0;
  if (dp[idx] != -1) return dp[idx];
  for (int i = L[a[idx]]; i <= R[a[idx]]; i++) {
    if (lft > L[a[i]]) lft = L[a[i]];
    if (rit < R[a[i]]) rit = R[a[i]];
  }
  bool v[5005] = {0};
  if (idx == lft) {
    int xo = 0;
    for (int i = lft; i <= rit; i++) {
      if (!v[a[i]]) {
        xo ^= a[i];
        v[a[i]] = 1;
      }
      vis[a[i]] = 1;
    }
    x = max(x, solve(rit + 1) + xo);
    for (int i = lft; i < rit; i++) {
      vis[a[i]] = 0;
    }
  }
  vis[a[idx]] = 1;
  x = max(x, solve(idx + 1));
  vis[a[idx]] = 0;
  return dp[idx] = x;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], R[a[i]] = i;
  memset(L, -1, sizeof L);
  for (int i = 0; i < n; i++)
    if (L[a[i]] == -1) L[a[i]] = i;
  cout << solve(0) << '\n';
  return 0;
}
