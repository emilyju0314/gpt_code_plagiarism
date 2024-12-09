#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 998244353;
const long long N = 100000 + 5, K = 105;
const int si = (1 << 20);
const long long add = 1e4;
const long long oo = (long long)2e9;
const long long M = 3e6 + 5;
const double INFdb = 1e10;
long long n;
long long a[N];
long long b[N];
long long dist[405][405];
long long dp[405][405];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> n;
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) b[++id] = a[i];
  }
  if (id > 3 * 64) return cout << 3, 0;
  long long minn = INF;
  for (int i = 1; i <= id; ++i) {
    for (int j = 1; j <= id; ++j) {
      if (i != j && ((b[i] & b[j]) != 0)) {
        dist[i][j] = 1;
        dp[i][j] = 1;
      } else {
        dist[i][j] = INF;
        dp[i][j] = INF;
      }
    }
  }
  for (int k = 1; k <= id; ++k) {
    for (int i = 1; i < k; ++i) {
      for (int j = i + 1; j < k; ++j)
        minn = min(minn, dp[i][j] + dist[i][k] + dist[k][j]);
    }
    for (int i = 1; i <= id; ++i) {
      for (int j = 1; j <= id; ++j)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
  }
  if (minn >= INF) return cout << -1, 0;
  cout << minn;
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
