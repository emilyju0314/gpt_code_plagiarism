#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, l, r;
int dp[N][3];
int add(int a, int b) {
  a += b;
  if (a >= (1000 * 1000 * 1000 + 7)) a -= (1000 * 1000 * 1000 + 7);
  return a;
}
int mul(int a, int b) { return (long long)a * b % (1000 * 1000 * 1000 + 7); }
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i;
  cin >> n >> l >> r;
  int a = r / 3 - (l + 2) / 3 + 1;
  int b = a;
  int c = a;
  int len = r - l + 1;
  if (len % 3 == 1) {
    if (l % 3 == 1) {
      b++;
    } else if (l % 3 == 2) {
      c++;
    } else {
      b--;
      a--;
    }
  } else if (len % 3 == 2) {
    if (l % 3 == 1) {
      b++;
      c++;
    } else if (l % 3 == 2) {
      b--;
    } else {
      c--;
    }
  }
  dp[1][0] = a;
  dp[1][1] = b;
  dp[1][2] = c;
  for (i = 2; 2 < n + 1 ? i < n + 1 : i > n + 1; 2 < n + 1 ? i += 1 : i -= 1) {
    dp[i][0] = add(mul(b, dp[i - 1][2]), mul(c, dp[i - 1][1]));
    dp[i][0] = add(dp[i][0], mul(a, dp[i - 1][0]));
    dp[i][1] = add(mul(b, dp[i - 1][0]), mul(a, dp[i - 1][1]));
    dp[i][1] = add(dp[i][1], mul(c, dp[i - 1][2]));
    dp[i][2] = add(mul(c, dp[i - 1][0]), mul(a, dp[i - 1][2]));
    dp[i][2] = add(dp[i][2], mul(b, dp[i - 1][1]));
  }
  cout << dp[n][0] << endl;
  return 0;
}
