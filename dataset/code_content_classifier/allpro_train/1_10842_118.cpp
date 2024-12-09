#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == 1 || b == 1) {
      long long ans = ceil(max(a, b) / 2.0);
      cout << ans << '\n';
    } else {
      if (a < b) {
        swap(a, b);
      }
      long long ans = 0;
      bool f = 0;
      if (b > 1 && b & 1) {
        b--;
        f = 1;
      }
      ans += a * ceil(b / 2.0);
      if (f) {
        ans += ceil(a / 2.0);
      }
      cout << ans << '\n';
    }
  }
}
