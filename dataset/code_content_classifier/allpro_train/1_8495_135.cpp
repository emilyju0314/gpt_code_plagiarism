#include <bits/stdc++.h>
using namespace std;
inline void Boost() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int n, k, a, b;
long long int mn = LLONG_MAX;
long long int mx = LLONG_MIN;
long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
void Solve(long long int pos) {
  if (pos <= 0) pos += n * k;
  if (pos > n * k) pos -= n * k;
  long long int B = n * k;
  for (long long int i = 0; i < n; ++i) {
    for (long long int after : {1 + i * k + b, 1 + i * k - b}) {
      if (after > B) after -= B;
      if (after <= 0) after += B;
      long long int l = after - pos;
      if (l <= 0) l += B;
      long long int want = 1;
      if (l == n * k) {
        want = 1;
      } else {
        long long int g = gcd(l, n * k);
        want = n * k / g;
      }
      mn = min(mn, want);
      mx = max(mx, want);
    }
  }
}
int main() {
  Boost();
  cin >> n >> k >> a >> b;
  Solve(1 + a);
  Solve(1 - a);
  cout << mn << " " << mx << endl;
  return 0;
}
