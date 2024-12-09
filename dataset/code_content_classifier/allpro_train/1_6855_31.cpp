#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
int f(string s) {
  int ans = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') ans += 1 << i;
  return ans;
}
const int maxn = 2001;
int M[maxn],
    OSTAD[10] = {f("1110111"), f("10010"),   f("1011101"), f("1011011"),
                 f("111010"),  f("1101011"), f("1101111"), f("1010010"),
                 f("1111111"), f("1111011")};
string dp[2][maxn];
char c[maxn][maxn];
int par[maxn][maxn];
vector<pair<int, int> > V[maxn];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    M[i] = f(s);
    for (int j = 9; j >= 0; j--) {
      if ((M[i] & OSTAD[j]) == M[i]) {
        V[i].push_back(pair<int, int>(
            j, __builtin_popcount(OSTAD[j]) - __builtin_popcount(M[i])));
      }
    }
  }
  reverse(V, V + n);
  dp[0][0] = "";
  for (int i = 1; i <= k; i++) dp[0][i] = "N";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[(i + 1) % 2][j] = "N";
      for (auto P : V[i]) {
        if (j >= P.second && dp[i % 2][j - P.second] != "N") {
          c[i + 1][j] = P.first + '0';
          par[i + 1][j] = j - P.second;
          dp[(i + 1) % 2][j] = (char)(P.first + '0') + dp[i % 2][j - P.second];
          break;
        }
      }
    }
  }
  if (dp[n % 2][k] == "N")
    cout << -1;
  else {
    int i = n, j = k;
    while (i) {
      cout << c[i][j];
      j = par[i][j];
      i--;
    }
  }
}
