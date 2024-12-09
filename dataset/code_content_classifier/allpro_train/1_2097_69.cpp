#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t > 0) {
    t--;
    long long n, x;
    cin >> n >> x;
    long long l = n + 1, r = -1;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      sum += a;
      if (a % x != 0) {
        l = min(l, i + 1);
        r = max(r, i + 1);
      }
    }
    if (sum % x != 0) {
      cout << n;
    } else {
      if (l == -1) {
        cout << -1;
      } else {
        cout << max(n - l, r - 1);
      }
    }
    cout << "\n";
  }
  return 0;
}
