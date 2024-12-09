#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll p = 1e9 + 7;
ll qsm(ll b, ll e) {
  return e ? (e & 1 ? b : 1) * qsm(b * b % p, e >> 1) % p : 1;
}
int main() {
  ll n, m;
  cin >> n >> m;
  ll one = (qsm(2, m) + p - 1) % p;
  ll ans = qsm(one, n);
  cout << ans;
}
