#include <bits/stdc++.h>
using namespace std;
long long p[65];
int main() {
  p[0] = 1;
  for (int i = 1; i <= 62; i++) p[i] = p[i - 1] * (long long)2;
  long long l, r;
  cin >> l >> r;
  int f = 0;
  long long ans = 0;
  for (int i = 62; i >= 0; i--) {
    long long b1 = p[i] & l;
    long long b2 = p[i] & r;
    if ((f == 1) || (r - l >= p[i]) || (b1 && !b2) || (b2 && !b1)) {
      ans += p[i];
      f = 1;
    }
  }
  cout << ans << "\n";
}
