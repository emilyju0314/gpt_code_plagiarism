#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0);
const int mod = 1000000007;
const int N = 1e5 + 7;
int n, w;
vector<int> a;
bool check(double x) {
  double g = x / (n * 3);
  double b = 2 * x / (n * 3);
  return a[0] >= g && a[n] >= b;
}
double BS(double lo, double hi) {
  for (int i = 0; i < (int)100; i++) {
    double mid = lo + (hi - lo) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  return lo;
}
void solve() {
  cin >> n >> w;
  a.resize(2 * n);
  for (int i = 0; i < (int)2 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  double ans = BS(0, w);
  printf("%0.6lf\n", ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
