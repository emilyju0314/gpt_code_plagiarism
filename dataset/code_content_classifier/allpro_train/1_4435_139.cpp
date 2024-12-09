#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << ' ' << n / 2 << '\n';
      continue;
    }
    long long res = 1;
    for (long long i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        res = n / i;
        break;
      }
    }
    cout << res << ' ' << n - res << '\n';
  }
  return 0;
}
