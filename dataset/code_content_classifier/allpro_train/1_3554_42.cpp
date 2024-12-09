#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first == b.first) return (a.second < b.second);
  return a.first < b.first;
}
long long nCr(long long n, long long r) {
  long long res = 1;
  for (int i = n; i > max(r, n - r); i--) res *= i, res %= 1000000007;
  for (int i = 2; i <= min(r, n - r); i++) res /= i;
  return res % 1000000007;
}
long long exp(long long n, long long j) {
  long long i = n, res = 1;
  while (j > 0) {
    if (j & 1) res *= i;
    res %= 1000000007;
    i = i * i;
    i %= 1000000007;
    j >>= 1;
  }
  return res % 1000000007;
}
int main() {
  int T = 1;
  while (T--) {
    long long n, q, i, j;
    cin >> n >> q;
    string a;
    cin >> a;
    long long cone[n + 1];
    cone[0] = 0;
    for (i = 1; i < n + 1; i++) {
      cone[i] = (a[i - 1] == '1') + cone[i - 1];
    }
    while (q--) {
      long long l, r;
      cin >> l >> r;
      long long ones = cone[r] - cone[l - 1];
      long long zeros = (r - l + 1) - ones;
      long long x = (exp(2ll, ones) - 1ll) % 1000000007;
      long long y = (x * (exp(2ll, zeros) - 1)) % 1000000007;
      cout << ((x + y) % 1000000007) << '\n';
    }
  }
}
