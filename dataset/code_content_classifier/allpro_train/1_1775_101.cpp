#include <bits/stdc++.h>
using namespace std;
int cnt[200010 + 1];
int operation[200010];
const int mod = 998244353;
bool prime[200010];
vector<int> v;
void solve() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  bool ok = false;
  if (c + e <= a && max(d, f) <= b) {
    ok = true;
  } else if (c + e <= b && max(d, f) <= a) {
    ok = true;
  } else if (d + f <= a && max(c, e) <= b)
    ok = true;
  else if (d + f <= b && max(c, e) <= a)
    ok = true;
  else if (c + f <= a && max(d, e) <= b)
    ok = true;
  else if (c + f <= b && max(d, e) <= a)
    ok = true;
  else if (d + e <= a && max(c, f) <= b)
    ok = true;
  else if (d + e <= b && max(c, f) <= a)
    ok = true;
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
