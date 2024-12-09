#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, a, b, ans = 0;
  cin >> k >> a >> b;
  if (a < 0 && b < 0) swap(a, b), a *= -1, b *= -1;
  if (a == 0) ans++;
  (a - abs(a) == b - abs(b) && k != 1) ? ans += b / k - ((a - 1) / k)
                                       : ans = (b / k - a / k) + 1;
  cout << ans;
  return 0;
}
