#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, curr;
  cin >> n;
  for (long long i = 0; i <= n / 3; i++) {
    for (long long j = 0; j <= n / 5; j++) {
      for (long long k = 0; k <= n / 7; k++) {
        curr = 3 * i + 5 * j + 7 * k;
        if (curr == n) {
          cout << i << " " << j << " " << k << '\n';
          return;
        }
      }
    }
  }
  cout << "-1" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
