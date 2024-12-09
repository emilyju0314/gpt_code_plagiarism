#include <bits/stdc++.h>
using namespace std;
int n, dp[100006], l, r;
string s;
int main() {
  cin >> s;
  dp[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1])
      dp[i] = dp[i - 1] + 1;
    else
      dp[i] = dp[i - 1];
  }
  cin >> n;
  while (n--) {
    cin >> l >> r;
    l--;
    r--;
    int k = dp[r] - dp[l];
    cout << k << endl;
  }
  return 0;
}
