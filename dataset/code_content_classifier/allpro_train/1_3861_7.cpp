#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > car;
vector<int> o;
int main() {
  int n, k, s, t;
  cin >> n >> k >> s >> t;
  int x, y;
  car.assign(n, {0, 0});
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    car[i] = {y, x};
  }
  k += 2;
  o.assign(k, 0);
  o[0] = 0;
  o[k - 1] = s;
  for (int i = 1; i < k - 1; ++i) {
    scanf("%d", &o[i]);
  }
  sort(o.begin(), o.end());
  sort(car.begin(), car.end());
  int res = 2e9;
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    int v = car[mid].first, time = 0;
    bool f = 1;
    for (int i = 0; i < k - 1; ++i) {
      int dis = o[i + 1] - o[i];
      if (dis > v) {
        f = 0;
        break;
      }
      int ll = min(v - dis, dis);
      int res2 = min(dis * 2, ll + (dis - ll) * 2);
      time += res2;
    }
    if (f && time <= t) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  int ans = 2e9;
  for (int i = res; i < n; ++i) ans = min(ans, car[i].second);
  if (ans == 2e9)
    cout << -1;
  else
    cout << ans;
  return 0;
}
