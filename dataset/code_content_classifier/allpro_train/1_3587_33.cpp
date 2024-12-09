#include <bits/stdc++.h>
using namespace std;
int l;
int mo;
string n;
long long dp[1 << 18][100];
long long coun[10];
int fastmod[10004];
void pre() {
  for (int i = (1); i <= (10004 - 1); ++i) {
    fastmod[i] = i % mo;
  }
}
long long solve(int mask, int m) {
  if (mask == (1 << l) - 1) return m == 0;
  if (dp[mask][m] != -1) return dp[mask][m];
  long long ans = 0;
  for (int j = (0); j <= (l - 1); ++j) {
    if ((mask & (1 << j))) continue;
    ans += solve(mask | (1 << j), fastmod[m * 10 + (n[j] - '0')]);
  }
  return dp[mask][m] = ans;
}
int main() {
  cin >> n >> mo;
  l = n.size();
  pre();
  memset(dp, -1, sizeof(dp));
  long long int i, j, ans = 0;
  for (i = 0; i < l; i++) {
    coun[n[i] - '0']++;
    if (n[i] - '0' > 0) ans += solve(1 << i, (n[i] - '0') % mo);
  }
  for (i = 0; i < 10; i++) {
    for (j = 1; j <= coun[i]; j++) ans /= j;
  }
  cout << ans;
  return 0;
}
