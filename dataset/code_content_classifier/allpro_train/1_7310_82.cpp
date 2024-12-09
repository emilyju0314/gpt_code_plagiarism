#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const long double EPSILON = 2.7182818284590452353602874713527;
long long n, m, k;
long long ans;
void my() {
  cin >> n >> m >> k;
  if (n + m - 2 < k) {
    ans = -1;
  } else {
    long long x = 0;
    long long xpi = 0;
    if (k > m - 1) x = k - (m - 1);
    ans = (n / (x + 1)) * (m / (k - x + 1));
    if (k > n - 1) xpi = k - (n - 1);
    ans = max(ans, (n / (k - xpi + 1)) * (m / (xpi + 1)));
  }
  cout << ans << endl;
}
void enum_floor() {
  cin >> n >> m >> k;
  if (n + m - 2 < k) {
    ans = -1;
  } else {
    ans = max(n * (m / (k + 1)), (n / (k + 1)) * m);
    for (int i = 1, next = 1; i <= n; i = next + 1) {
      next = n / (n / i);
      int kn = next - 1;
      int km = k - kn;
      if (km + 1 > 0) ans = max(ans, (n / (kn + 1)) * (m / (km + 1)));
    }
  }
  cout << ans << endl;
}
int main() {
  enum_floor();
  return 0;
}
