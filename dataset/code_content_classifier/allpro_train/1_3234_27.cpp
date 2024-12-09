#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, g, b;
  cin >> r >> g >> b;
  long long j = min(r, min(g, b));
  if (r == g && g == b) {
    cout << r;
    return 0;
  }
  long long x = r / 3;
  long long k = x * 3;
  k = r - k;
  long long ans = INT_MIN;
  for (long long i = 0; i <= j && i < 3; i++) {
    long long temp = 0;
    temp += i;
    long long tr, tg, tb;
    tr = r - i;
    tg = g - i;
    tb = b - i;
    temp += tr / 3 + tg / 3 + tb / 3;
    ans = max(ans, temp);
  }
  cout << ans;
  return 0;
}
