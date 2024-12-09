#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 11, INF = 1e11 + 85, MOD = 1e9 + 7;
long long n, m, k, x, mx = -1, y, id_1, id_2, z, dp[MAX], ps[MAX], b, d, p, nl,
                      np, l, t, t1, t2, t3, cnt, f1, ans2, f, ans, mn2 = INF,
                      mn = INF, sum;
bool mark;
string mp[MAX];
vector<char> v[MAX];
vector<int64_t> m1, m2;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  dp[0] = 1;
  for (long long i = 1; i < 1e6 + 10; i++) {
    if (i >= k) {
      dp[i] = dp[i - k];
    }
    dp[i] += (dp[i - 1]) % MOD;
    ps[i] = (ps[i - 1] + dp[i]) % MOD;
  }
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    cout << (ps[y] - ps[x] + dp[x] + MOD) % MOD << '\n';
  }
}
