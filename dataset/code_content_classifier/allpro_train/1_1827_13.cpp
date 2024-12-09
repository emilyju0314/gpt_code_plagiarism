#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1000000007ll;
long long mod2 = 998244353ll;
long long k = 0;
long long a[300001];
bool vis[300001];
vector<vector<long long> > v(300001);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2);
  p = (p * p) % mod1;
  if (y % 2) return (p * x) % mod1;
  return p;
}
pair<long long, long long> dfs(long long in) {
  long long ma = 0;
  if (v[in].size() == 0) return {k, 1};
  if (a[in] == 0) {
    for (long long i = 0; i < v[in].size(); i++) {
      pair<long long, long long> p;
      p = dfs(v[in][i]);
      ma += p.second;
    }
    return {k - ma + 1, ma};
  } else {
    ma = k;
    for (long long i = 0; i < v[in].size(); i++) {
      pair<long long, long long> p;
      p = dfs(v[in][i]);
      ma = min(p.second, ma);
    }
    return {k - ma + 1, ma};
  }
}
void solve() {
  long long n, ans = 0;
  cin >> n;
  long long b[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = 0;
  }
  long long x;
  for (long long i = 2; i <= n; i++) {
    cin >> x;
    v[x].push_back(i);
    b[x]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (b[i] == 0) k++;
  }
  pair<long long, long long> p = dfs(1);
  cout << p.first << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
