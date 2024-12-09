#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long Bpow(long long a, long long s) {
  if (s == 0) {
    return 1;
  }
  long long u = Bpow(a, s / 2);
  if (s & 1)
    return u * u % mod * a % mod;
  else
    return u * u % mod;
}
vector<map<long long, long long>> ma(2e5 + 7);
vector<vector<long long>> g(2e5 + 7);
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
vector<long long> x(2e5 + 7);
long long ans = 0;
void dfs(long long v, long long p = -1) {
  if (p != -1) {
    for (auto& el : ma[p]) {
      ma[v][gcd(el.first, x[v])] += el.second;
    }
  }
  ma[v][x[v]]++;
  for (auto& el : ma[v]) {
    ans += el.first % mod * el.second % mod;
    ans %= mod;
  }
  for (auto& to : g[v]) {
    if (to != p) dfs(to, v);
  }
}
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) {
    cin >> x[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  cout << ans;
}
