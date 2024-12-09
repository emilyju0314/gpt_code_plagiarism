#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long mul(const long long& a, const long long& b) { return (a * b) % mod; }
long long add(const long long& a, const long long& b) { return (a + b) % mod; }
long long pwr(const long long& a, const long long& b) {
  if (!b) return 1;
  long long h = pwr(a, b >> 1);
  h = mul(h, h);
  if (b & 1) h = mul(h, a);
  return h;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long length = mul(n, pwr(m + 1, mod - 2)) + 1;
  long long times = 1;
  long long h = 0;
  for (int i = 1; i <= n; i++) h = add(h, mul(1, pwr(i, mod - 2)));
  times = add(times, mul(h, m));
  cout << mul(length, times) << "\n";
  return 0;
}
