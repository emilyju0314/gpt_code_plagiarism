#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using si = set<int>;
const ld PI = acos((ld)-1);
const ll mod = 1e9 + 7;
void solve() {
  ll x, y, possible = 0;
  cin >> x >> y;
  map<int, int> mp;
  while (mp[x] == 0 && x > 1) {
    ++mp[x];
    if (x % 2 == 0)
      x = 3 * x / 2;
    else
      --x;
    if (x >= y) break;
  }
  cout << (x >= y ? "Yes" : "No") << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cout << setprecision(12) << fixed;
  int t = 1;
  cin >> t;
  while (t--) solve();
}
