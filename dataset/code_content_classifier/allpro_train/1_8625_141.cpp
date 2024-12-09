#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int nax = 200005;
set<long long> s;
long long pow(long long a, long long to) {
  long long ans = 1;
  for (int i = 1; i <= to; i++) {
    ans *= a;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long x, y, l, r;
  cin >> x >> y >> l >> r;
  for (long long a = 0; a <= 64; a++) {
    for (long long b = 0; b <= 64; b++) {
      long long now_a = 0, now_b = 0;
      if (log(2e18 + 66) >= a * log(x)) {
        now_a = pow(x, a);
      }
      if (log(2e18 + 66) >= b * log(y)) {
        now_b = pow(y, b);
      }
      if (now_a != 0 && now_b != 0 && now_a <= 2e18 - now_b) {
        s.insert(now_a + now_b);
      }
    }
  }
  long long now = l;
  long long nxt;
  auto it = s.upper_bound(now);
  if (it == s.end()) {
    nxt = r + 1;
  } else {
    nxt = *s.upper_bound(now);
    nxt = min(nxt, r + 1);
  }
  long long sub = 0;
  if (s.count(l)) sub = 1;
  long long ans = nxt - now - sub;
  now = nxt;
  while (now < r) {
    auto it = s.upper_bound(now);
    long long nxt = 0;
    if (it == s.end()) {
      nxt = r + 1;
    } else {
      nxt = min(r + 1, *it);
    }
    ans = max(ans, nxt - now - 1);
    now = nxt;
  }
  cout << ans << '\n';
  return 0;
}
