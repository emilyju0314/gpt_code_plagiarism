#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (k == 1)
      cout << n << endl;
    else {
      if (n <= k) {
        cout << 1 << endl;
      } else {
        long long int ans = n;
        for (long long int i = 2; i <= sqrt(n); i++) {
          if (n % i == 0) {
            if (i <= k) {
              ans = min(ans, n / i);
            }
            if (n / i <= k) {
              ans = min(ans, i);
            }
          }
        }
        cout << ans << endl;
      }
    }
  }
}
