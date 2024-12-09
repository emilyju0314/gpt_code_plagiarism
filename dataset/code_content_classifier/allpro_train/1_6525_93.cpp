#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long x, y, m;
  cin >> x >> y >> m;
  if (x > y) swap(x, y);
  long long ans = 0;
  if (y >= m) {
    cout << "0" << endl;
    return 0;
  }
  if (y <= 0) {
    cout << "-1";
    return 0;
  }
  if (x <= 0) {
    long long num = -x;
    ans += num / y + 1;
    x += y * ans;
  }
  long long x_prev = 0, y_prev = 1, x_curr = 1, y_curr = 1;
  long long num = 1;
  while (1) {
    if (x_curr * x + y_curr * y >= m) {
      ans += num;
      break;
    }
    long long t = x_prev;
    x_prev = x_curr;
    x_curr += t;
    t = y_prev;
    y_prev = y_curr;
    y_curr += t;
    num++;
  }
  cout << ans;
}
