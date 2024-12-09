#include <bits/stdc++.h>
using namespace std;
const int N = 301;
const int INF = (int)2e9;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int n;
int l[N], c[N];
map<pair<int, int>, int> dp;
int solve(int pos, int g) {
  if (pos == n) {
    if (g == 1)
      return 0;
    else
      return INF;
  }
  pair<int, int> p(pos, g);
  if (dp.find(p) != dp.end()) return dp[p];
  int tmp1 = solve(pos + 1, g);
  int tmp2;
  if (g == INF)
    tmp2 = solve(pos + 1, l[pos]);
  else
    tmp2 = solve(pos + 1, gcd(g, l[pos]));
  int ans = INF;
  if (tmp1 != INF) ans = tmp1;
  if (tmp2 != INF) ans = min(ans, tmp2 + c[pos]);
  dp[p] = ans;
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  int ans = solve(0, INF);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
