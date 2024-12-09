#include <bits/stdc++.h>
using namespace std;
long long n, q, a, p[20005][35], dp[35][20005];
string s;
char c;
int main() {
  cin >> n;
  cin >> s;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    if (i != 1)
      for (int j = 0; j <= 27; j++) {
        p[i][j] = p[i - 1][j];
      }
    p[i][s[i] - 'a']++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = 0; k <= 27; k++) {
        long long x = j - i + 1;
        long long y = p[j][k] - p[i - 1][k];
        dp[k][x - y] = max(dp[k][x - y], x);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 27; j++) {
      dp[j][i] = max(dp[j][i], dp[j][i - 1]);
    }
  }
  cin >> q;
  while (q--) {
    cin >> a >> c;
    cout << dp[c - 'a'][a] << endl;
  }
}
