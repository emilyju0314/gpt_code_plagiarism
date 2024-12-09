#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i < n; i++) {
    if (n % i == 0) {
      ans++;
    }
  }
  cout << ans << "\n";
}
