#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 998244353;

const int N = 2e5;
ll dp[N][2][3][3][3];

int solve2(string s) {
  if(s[0] == s[1]) return 1;
  return 2;
}

int solve3(string s) {
  if(s[0] == s[1] && s[1] == s[2]) return 1;
  if(s[0] == s[1] || s[1] == s[2]) return 6;
  if(s[0] == s[2]) return 7;
  return 3;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  int sum = 0;
  if(n == 2) return (cout << solve2(s) << endl, 0);
  if(n == 3) {
    cout << solve3(s) << endl;
    return 0;
  }
  int f = 1;
  int same = 1;
  for(int i = 0; i < n; i++) {
    sum += s[i] - 'a';
    if(i && s[i] == s[i - 1]) f = 0;
    if(i && s[i] != s[i - 1]) same = 0;
  }
  if(same) return (cout << 1 << endl, 0);
  sum %= 3;
  for(int i = 0; i < 3; i++) dp[0][0][0][i][i] = 1;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) {
      for(int l = 0; l < 2; l++) for(int m = 0; m < 3; m++)
        for(int o = 0; o < 3; o++) {
          (dp[i][l || (j == k)][j][k][(o + k) % 3] +=
           dp[i - 1][l][m][j][o]) %= mod;
        }
    }
  }
  ll ans = 0;
  for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
    ans += dp[n - 1][1][i][j][sum % 3];
  }
  ans += f;
  ans %= mod;
  cout << ans << endl;
}
