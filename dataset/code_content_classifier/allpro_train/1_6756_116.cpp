#include <bits/stdc++.h>
using namespace std;
long long int inv[1000005];
long long int dp[1000005];
long long int prex[1000005];
long long int prey[1000005];
long long int presq[1000005];
long long int predp[1000005];
long long int Power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 998244353ll;
    }
    a = (a * a) % 998244353ll;
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  inv[0] = Power(1, 998244353ll - 2ll);
  for (long long int i = 1; i <= 1000000; i++) {
    inv[i] = Power(i, 998244353ll - 2ll);
  }
  long long int n, m;
  cin >> n >> m;
  vector<array<long long int, 3>> v;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      long long int x;
      cin >> x;
      v.push_back({x, i, j});
    }
  }
  long long int r, c;
  cin >> r >> c;
  sort(v.begin(), v.end());
  for (long long int i = 0; i < n * m; i++) {
    v[i][0] %= 998244353ll;
  }
  prex[0] = v[0][1];
  prey[0] = v[0][2];
  presq[0] = (v[0][1] * v[0][1]) % 998244353ll;
  presq[0] += (v[0][2] * v[0][2]) % 998244353ll;
  presq[0] %= 998244353ll;
  if (v[0][1] == r && v[0][2] == c) {
    cout << dp[0] << "\n";
    return 0;
  }
  long long int cur = 0;
  for (long long int i = 1; i < n * m; i++) {
    if (v[i][0] == v[0][0]) {
      prex[i] = (prex[i - 1ll] + v[i][1]) % 998244353ll;
      prey[i] = (prey[i - 1ll] + v[i][2]) % 998244353ll;
      presq[i] = presq[i - 1ll];
      presq[i] += (v[i][1] * v[i][1]) % 998244353ll;
      presq[i] %= 998244353ll;
      presq[i] += (v[i][2] * v[i][2]) % 998244353ll;
      presq[i] %= 998244353ll;
      if (v[i][1] == r && v[i][2] == c) {
        cout << dp[i] << "\n";
        return 0;
      }
      continue;
    }
    if (v[i][0] != v[i - 1ll][0]) {
      cur = i - 1ll;
    }
    long long int z = (v[i][1] * v[i][1]) % 998244353ll;
    z += (v[i][2] * v[i][2]) % 998244353ll;
    z %= 998244353ll;
    presq[i] = presq[i - 1ll];
    presq[i] = (presq[i] + z) % 998244353ll;
    z = (z * (cur + 1ll)) % 998244353ll;
    z = (z + presq[cur]) % 998244353ll;
    z = (z + 998244353ll - (2ll * v[i][1] * prex[cur]) % 998244353ll) %
        998244353ll;
    z = (z + 998244353ll - (2ll * v[i][2] * prey[cur]) % 998244353ll) %
        998244353ll;
    z = (z + predp[cur]) % 998244353ll;
    dp[i] = (z * inv[cur + 1ll]) % 998244353ll;
    prex[i] = (prex[i - 1ll] + v[i][1]) % 998244353ll;
    prey[i] = (prey[i - 1ll] + v[i][2]) % 998244353ll;
    predp[i] = (predp[i - 1ll] + dp[i]) % 998244353ll;
    if (v[i][1] == r && v[i][2] == c) {
      cout << dp[i] << "\n";
      return 0;
    }
  }
}
