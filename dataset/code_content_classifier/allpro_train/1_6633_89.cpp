#include <bits/stdc++.h>
using namespace std;
long long f(long long n, long long k) {
  return (n - k) + min((k * (k - 1)) / 2, n - k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long lo = 1, hi = n;
    while (hi - lo > 1) {
      long long mid = (lo + hi) / 2;
      if (f(n, mid) >= f(n, mid - 1) && f(n, mid) <= f(n, mid + 1))
        lo = mid;
      else if (f(n, mid) <= f(n, mid - 1) && f(n, mid) >= f(n, mid + 1))
        hi = mid;
      else if (f(n, mid) >= f(n, mid - 1) && f(n, mid) >= f(n, mid + 1))
        lo = hi = mid;
    }
    cout << max(f(n, lo), f(n, hi)) << "\n";
  }
  return 0;
}
