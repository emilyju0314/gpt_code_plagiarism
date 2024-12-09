#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long ans = a[0];
    for (long long i = 1; i < n; i++) {
      ans = ans ^ a[i];
    }
    if (sum == 2 * ans) {
      cout << 0 << endl << endl;
      continue;
    }
    cout << 2 << endl;
    cout << ans << " " << ans + sum << endl;
  }
}
