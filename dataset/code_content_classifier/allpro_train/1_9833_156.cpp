#include <bits/stdc++.h>
using namespace std;
void read(bool out = 0) {}
long long fact[10 * 500009];
long long dp[2009];
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a, ans %= 1000000007;
    b /= 2;
    a *= a;
    a %= 1000000007;
  }
  return ans;
}
void fix(long long& x) {
  x %= 1000000007;
  x += 1000000007;
  x %= 1000000007;
}
long long ways(long long x, long long y, long long u, long long v) {
  if (x > u || y > v) return 0;
  long long up = fact[u - x + v - y];
  long long down = fact[u - x] * fact[v - y];
  fix(down);
  down = power(down, 1000000007 - 2);
  up *= down;
  fix(up);
  return up;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  long long n, m, k;
  cin >> n >> m >> k;
  vector<pair<long long, long long> > v;
  for (int i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  v.push_back(make_pair(n, m));
  sort(v.begin(), v.end());
  fact[0] = 1;
  for (int i = 1; i < 10 * 500009; i++)
    fact[i] = i * fact[i - 1], fact[i] %= 1000000007;
  for (int i = 0; i < v.size(); i++) {
    long long x = v[i].first;
    long long y = v[i].second;
    long long total = ways(1, 1, x, y);
    for (int j = 0; j < i; j++) {
      total -= dp[j] * ways(v[j].first, v[j].second, x, y);
      fix(total);
    }
    dp[i] = total;
  }
  cout << dp[v.size() - 1] << "\n";
}
