#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long cnt = 0, ans = 0, f = 0;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    if (x > 0) ans += x - 1;
    if (x < 0) ans += -1 - x, ++cnt;
    if (x == 0) ans += 1, f = 1;
  }
  if (cnt % 2 == 1 && f == 0) ans += 2;
  cout << ans;
  return 0;
}
