#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N; cin>>N;
  vector<pair<double, double>> dot(N);
  for (auto& p : dot) {
    cin>>p.first>>p.second;
  }

  auto min_range = [&](double x, double y) {
    double r = 0;
    for (auto d : dot) {
      auto cr = sqrt(pow(d.first-x, 2) + pow(d.second-y, 2));
      r = max(cr, r);
    }
    return r;
  };

  const double phi = (sqrt(5)+1)/2;
  auto min_range_x = [&](double x) {
    double l = 0, h = 1000;
    while (h-l > 0.0000001) {
      auto cl = (l*phi+h)/(phi+1);
      auto ch = (l+h*phi)/(phi+1);
      auto rl = min_range(x, cl);
      auto rh = min_range(x, ch);
      if (rl > rh) {
        l = cl;
      } else {
        h = ch;
      }
    }
    return min_range(x, (l+h)/2);
  };
  double l = 0, r = 1000;
  double ans;
  while (r-l > 0.0000001) {
    auto cl = (l*phi+r)/(phi+1);
    auto cr = (l+r*phi)/(phi+1);
    auto rl = min_range_x(cl);
    auto rh = min_range_x(cr);
    if (rl > rh) {
      l = cl;
      ans = rh;
    } else {
      r = cr;
      ans = rl;
    }
  }
  cout << fixed << ans << endl;

  return 0;
}
