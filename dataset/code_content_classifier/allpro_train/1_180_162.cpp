#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
ll powmod(ll base, ll exp, const ll MOD) {
  ll ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return ans;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll modInverse(ll n, const ll p) { return powmod(n, p - 2, p); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(b.begin(), b.end());
  int ans = 1e9 + 9;
  for (int i = 0; i < n; ++i) {
    int x = (b[i] - a[0] + m) % m;
    vector<int> tmp = a;
    for (int i = 0; i < n; ++i) tmp[i] = (tmp[i] + x) % m;
    sort(tmp.begin(), tmp.end());
    if (tmp == b) {
      ans = min(ans, x);
    }
  }
  cout << ans;
  return 0;
}
