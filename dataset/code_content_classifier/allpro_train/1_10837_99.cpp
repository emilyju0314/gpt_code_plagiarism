#include <bits/stdc++.h>
using namespace std;
bool OF(long long a, long long b) {
  if ((a * b) / a == b)
    return false;
  else
    return true;
}
long long mo = 1e9 + 7;
vector<long long> v;
long long ans = 1, now = 1, x, n;
int main() {
  ios_base::sync_with_stdio(0);
  long long d;
  cin >> x >> n;
  set<long long> se;
  d = x;
  for (int i = 2; i * i <= x; i++) {
    if (d % i == 0ll) {
      se.insert(i);
      d /= i;
      i--;
    }
  }
  for (auto i : se) {
    v.push_back(i);
  }
  if (d != 1) v.push_back(d);
  for (long long i : v) {
    long long d = i, sum = 0;
    while (d <= n) {
      long long k = n / d;
      sum += k;
      if (!OF(d, i))
        d *= i;
      else
        break;
    }
    long long r = i;
    for (int j = 0; j < 63; j++) {
      if (sum & (1ll << j)) {
        ans *= r;
        ans %= mo;
      }
      r = (r * r);
      r %= mo;
    }
  }
  cout << ans << endl;
}
