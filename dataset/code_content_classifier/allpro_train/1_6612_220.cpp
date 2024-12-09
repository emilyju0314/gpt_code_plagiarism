#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void solve() {
  long long int x, y, n;
  cin >> x >> y >> n;
  double cur = x / (double)(y);
  double a = x, b;
  if (y > n)
    b = n;
  else
    b = y;
  double ansa = x, ansb = b;
  double ans = (a / b);
  while (a >= 0 && b > 0) {
    while (a >= 0 && a / b >= cur) {
      if (abs(a / b - cur) <= abs(ans - cur)) {
        ans = (a / b);
        ansa = a;
        ansb = b;
      }
      a--;
    }
    if (a >= 0) {
      if (abs(a / b - cur) <= abs(ans - cur)) {
        ans = (a / b);
        ansa = a;
        ansb = b;
      }
    }
    b--;
  }
  cout << ansa << "/" << ansb << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  ;
  long long int t = 1;
  while (t--) {
    solve();
  }
}
