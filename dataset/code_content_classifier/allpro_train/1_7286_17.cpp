#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = 4e18;
const int inf = 1e9;
const int N = 2e5 + 5;
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
void solve() {
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xs, ys, t, ans = 0;
  cin >> xs >> ys >> t;
  vector<ll> x(1), y(1);
  x[0] = x0;
  y[0] = y0;
  while (true) {
    ll new_x = x.back(), new_y = y.back();
    if (INF / new_x < ax) {
      break;
    }
    if (INF / new_y < ay) {
      break;
    }
    new_x = x.back() * ax + bx, new_y = y.back() * ay + by;
    x.push_back(new_x);
    y.push_back(new_y);
  }
  ll mx = 0;
  for (int i = 0; i < x.size(); i++) {
    ll now_x = xs, now_y = ys, sum = 0, tt = t;
    ll pos = i;
    while (pos >= 0) {
      if (abs(now_x - x[pos]) + abs(now_y - y[pos]) <= tt) {
        sum++;
        tt -= abs(now_x - x[pos]) + abs(now_y - y[pos]);
      } else {
        break;
      }
      now_x = x[pos];
      now_y = y[pos];
      pos--;
    }
    mx = max(mx, sum);
    pos = i;
    now_x = xs, now_y = ys;
    sum = 0, tt = t;
    while (pos < x.size()) {
      if (abs(now_x - x[pos]) + abs(now_y - y[pos]) <= tt) {
        sum++;
        tt -= abs(now_x - x[pos]) + abs(now_y - y[pos]);
      } else {
        break;
      }
      now_x = x[pos];
      now_y = y[pos];
      pos++;
    }
    mx = max(mx, sum);
  }
  cout << mx << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
