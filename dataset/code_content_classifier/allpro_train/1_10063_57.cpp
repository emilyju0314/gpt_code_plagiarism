#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int x, y, a, b;
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    long long int ans = (y - x) % (a + b);
    long long int ans1 = (y - x) / (a + b);
    if (ans == 0)
      cout << ans1 << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
