#include <bits/stdc++.h>
using namespace std;
int dp[5002][5002];
vector<int> inst;
int mod = 1000 * 1000 * 1000 + 7;
int f(int i, int j) {
  if (j < 0) return 0;
  int k = 0;
  if (i > 0) k = inst[i - 1];
  if (dp[i][j] != -1) return dp[i][j];
  if (i >= inst.size()) return dp[i][j] = 1;
  if (k == 1) return dp[i][j] = f(i + 1, j + inst[i]) % mod;
  return dp[i][j] = (f(i, j - 1) % mod + f(i + 1, j + inst[i]) % mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  inst.resize(n);
  for (int i = 0; i < 5002; i++) {
    for (int j = 0; j < 5002; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 's')
      inst[i] = 0;
    else
      inst[i] = 1;
  }
  cout << f(0, 0) % mod;
}
