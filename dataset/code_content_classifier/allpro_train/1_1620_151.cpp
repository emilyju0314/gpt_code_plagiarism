#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 1010;
long long dp[maxn][3000][2];
int t, k;
string s1, s2;
long long dfs(int pos, int dis, int isok) {
  if (pos == 0) return isok;
  if (dp[pos][dis][isok] != -1) return dp[pos][dis][isok];
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    if (i == 4 || i == 7) {
      ans += dfs(pos - 1, 1, isok | (dis <= k));
      ans %= mod;
    } else {
      ans += dfs(pos - 1, dis + 1, isok);
      ans %= mod;
    }
  }
  dp[pos][dis][isok] = ans;
  return ans;
}
long long DP(string s, int a) {
  int isok = 0, dis = k + 1;
  int pos = s.length();
  long long ret = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < s[i] - '0'; j++) {
      if (j == 4 || j == 7) {
        ret += dfs(pos - i - 1, 1, isok | (dis <= k));
        ret %= mod;
      } else {
        ret += dfs(pos - i - 1, dis + 1, isok);
        ret %= mod;
      }
    }
    if (s[i] == '4' || s[i] == '7') {
      if (dis <= k) {
        isok = 1;
      }
      dis = 0;
    }
    dis++;
  }
  if (a == 1) ret += isok;
  ret %= mod;
  return ret;
}
int main() {
  cin >> t >> k;
  memset(dp, -1, sizeof(dp));
  while (t--) {
    cin >> s1 >> s2;
    cout << (DP(s2, 1) - DP(s1, 0) + mod) % mod << endl;
  }
  return 0;
}
