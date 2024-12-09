#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::swap;
using std::vector;
using ll = long long;
void testc() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (auto &[first, second] : v) cin >> first >> second;
  ll ans = ll(n) * (n - 1) * (n - 2) / 6;
  std::map<int, int> sx, sy;
  for (auto [first, second] : v) sx[first]++, sy[second]++;
  for (auto [first, second] : v) ans -= ll(sx[first] - 1) * (sy[second] - 1);
  cout << ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    testc();
    if (t) putchar('\n');
  }
  return 0;
}
