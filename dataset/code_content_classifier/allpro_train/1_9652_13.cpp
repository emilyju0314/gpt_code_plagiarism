#include <bits/stdc++.h>
using namespace std;
string make(int i, int j) {
  return "(" + to_string(i + 1) + "," + to_string(j + 1) + ")";
}
int main() {
  int n = 4, m = 4, k = 16;
  cin >> n >> m >> k;
  vector<vector<string>> dp(n, vector<string>(m, ""));
  dp[0][0] = "(1,1)";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int I = i + 1;
      int J = j + 1;
      if (I < n) {
        dp[I][j] = dp[i][j] + make(I, j);
      }
      if (J < m) {
        dp[i][J] = dp[i][j] + make(i, J);
      }
    }
  }
  vector<string> result(k);
  int tot = 0;
  for (int le = 0; le < n + m; le++) {
    for (int i = 0; i <= le && k > 0; i++) {
      int j = le - i;
      if (i < n && j < m) {
        result[k - 1] = dp[i][j];
        k--;
        tot += le + 1;
      }
    }
  }
  cout << tot << endl;
  for (string i : result) {
    cout << i << endl;
  }
}
