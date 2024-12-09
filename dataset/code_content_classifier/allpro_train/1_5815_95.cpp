#include <bits/stdc++.h>
using namespace std;
unsigned long long ans = 1e18;
unsigned long long sq(int x) { return 1ll * x * x; }
void solve(vector<int> a, vector<int> b, vector<int> c) {
  for (auto x : a) {
    auto y = lower_bound(b.begin(), b.end(), x);
    auto z = upper_bound(c.begin(), c.end(), x);
    if (y == b.end() || z == c.begin()) {
      continue;
    }
    z--;
    ans = min(ans, sq(x - *y) + sq(*y - *z) + sq(*z - x));
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, g, b;
    cin >> r >> g >> b;
    ans = 1e19;
    vector<int> red(r), gre(g), blu(b);
    for (int i = 0; i < r; i++) cin >> red[i];
    for (int i = 0; i < g; i++) cin >> gre[i];
    for (int i = 0; i < b; i++) cin >> blu[i];
    sort(red.begin(), red.end());
    sort(gre.begin(), gre.end());
    sort(blu.begin(), blu.end());
    solve(red, gre, blu);
    solve(red, blu, gre);
    solve(blu, gre, red);
    solve(blu, red, gre);
    solve(gre, red, blu);
    solve(gre, blu, red);
    cout << ans << endl;
  }
  return 0;
}
