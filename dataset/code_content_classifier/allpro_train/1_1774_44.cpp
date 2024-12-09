#include <bits/stdc++.h>
using namespace std;
long long a, b, l, t, m;
int bin(long long x, long long y) {
  while (x < y) {
    long long mid = (x + y + 1) / 2;
    if (a + (mid - 1) * b <= t &&
        ((mid - l + 1) * a + ((mid * (mid - 1) - (l - 2) * (l - 1)) * b) / 2) <=
            t * m) {
      x = mid;
    } else {
      y = mid - 1;
    }
  }
  return x;
}
void solve() {
  long long n;
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    if (a + (l - 1) * b > t) {
      cout << "-1\n";
      continue;
    }
    cout << bin(l, t) << endl;
  }
}
int main() {
  int z = 1;
  for (int i = 1; i <= z; i++) {
    solve();
  }
}
