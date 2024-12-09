#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int dp[2005][105][2];
int b[2005], n, k;
int a[2005];

int dfs(int pos, int mex, int flag) {
  if (pos == n) return flag;
  if (dp[pos][mex][flag] != -1) return dp[pos][mex][flag];
  
  int &res = dp[pos][mex][flag];
  res = 0;

  for (int i = 0; i <= (flag ? 9 : a[pos]); i++) {
    int nmex = (i == mex ? mex + 1 : mex);
    res += dfs(pos + 1, nmex, flag || i < a[pos]);
    res %= MOD;
  }

  return res;
}

int solve() {
  int ans = 0;
  for (a[0] = 0; a[0] <= 9; a[0]++) {
    memset(dp, -1, sizeof(dp));
    
    int diff = max(b[0] - k, a[0]) - min(b[0] + k, a[0]);
    if (diff <= k) ans += dfs(1, a[0] + 1, diff < 0);
    ans %= MOD;
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> b[i];
  cout << solve() << endl;
  return 0;
}