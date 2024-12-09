#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (int)1e9 + 7;
long long solve(long long x) {
  long long odd = 0, even = 0;
  long long jump = 1, cur = 0;
  bool c = true;
  while (cur < x) {
    if (c) {
      odd += min(jump, x - cur);
      cur += jump;
    } else {
      even += min(jump, x - cur);
      cur += jump;
    }
    jump *= 2;
    c = !c;
  }
  assert(odd + even == x);
  odd %= mod;
  even %= mod;
  long long oddsum = (odd * odd) % mod;
  long long evensum = (even * (even + 1)) % mod;
  return (oddsum + evensum) % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long l, r;
  cin >> l >> r;
  cout << (solve(r) - solve(l - 1) + mod) % mod << '\n';
  return 0;
}
