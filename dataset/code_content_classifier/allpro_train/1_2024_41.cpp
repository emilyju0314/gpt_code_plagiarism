#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v;
long long p, ta, pp, ss, tb, ans;
long long disc, c1, c2, y, squ;
long long ttc;
void check(long long disc, long long a, long long b, long long y) {
  squ = sqrt(disc * 1.0 + 1e-6);
  if (squ * squ != disc) return;
  c1 = -y - squ;
  if (c1 % 2 == 0 && c1 / 2 - a >= b) {
    ttc = c1 / 2 - a;
    if (a != b && b != ttc)
      ans += 6;
    else if (a != b || b != ttc)
      ans += 3;
    else
      ++ans;
  }
  c2 = -y + squ;
  if (c2 % 2 == 0 && c2 / 2 - a >= b) {
    ttc = c2 / 2 - a;
    if (a != b && b != ttc)
      ans += 6;
    else if (a != b || b != ttc)
      ans += 3;
    else
      ++ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n % 3) {
    cout << 0 << endl;
    return 0;
  }
  n /= 3;
  for (long long i = 1; i * i * i <= n; i++)
    if (n % i == 0) {
      v.push_back(i);
    }
  for (int div = 0; div < v.size(); div++) {
    ss = v[div];
    for (long long p = 1; p <= ss; ++p) {
      ta = p;
      tb = ss - p;
      if (tb < ta) break;
      pp = n / (ta + tb);
      if (pp * (ta + tb) != n) continue;
      if (ta * tb * 4 > pp) continue;
      y = tb - ta;
      disc = y * y + 4 * pp;
      if (disc < 0) continue;
      check(disc, ta, tb, y);
    }
  }
  cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
