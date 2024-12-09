#include <bits/stdc++.h>
using namespace std;
const int nmax = 100005;
const int mmax = 1500000;
const long long linf = 1e18;
const long long mod = 998244353;
const int inf = INT_MAX;
long long n, a[nmax], b[nmax];
bool g1(long long a, long long b);
bool g2(long long a, long long b) {
  assert(a <= b);
  if (a * 2 > b) {
    return true;
  } else {
    return g1(a, b / 2);
  }
}
bool g1(long long a, long long b) {
  assert(a <= b);
  if (b % 2 == 1) {
    return a % 2 != 1;
  } else {
    if (a * 2 > b) {
      return a % 2;
    }
    if (a * 4 > b) {
      return 1;
    }
    return g1(a, b / 4);
  }
}
bool dp[nmax][3];
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  cin >> n;
  for (int i = 1; i <= (int)n; ++i) {
    cin >> a[i] >> b[i];
  }
  dp[n][1] = g1(a[n], b[n]);
  dp[n][2] = g2(a[n], b[n]);
  for (int i = n - 1; i > 0; i--) {
    if (g1(a[i], b[i])) {
      dp[i][1] |= !dp[i + 1][1];
      dp[i][2] |= !dp[i + 1][2];
    }
    if (g2(a[i], b[i])) {
      dp[i][1] |= dp[i + 1][1];
      dp[i][2] |= dp[i + 1][2];
    }
  }
  cout << (dp[1][1] ? '1' : '0') << ' ' << (dp[1][2] ? '1' : '0') << '\n';
}
