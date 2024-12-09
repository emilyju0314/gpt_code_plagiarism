#include <bits/stdc++.h>
using namespace std;
void ans(int64_t a) {
  cout << a;
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  vector<pair<int64_t, int64_t> > v;
  for (int64_t i = 0; i < 3; ++i) {
    int64_t a, b = 0;
    cin >> a;
    char c;
    cin >> c;
    if (c == 'm') b = 1;
    if (c == 'p') b = 2;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  if (v[0] == v[1] && v[1] == v[2]) ans(0);
  if (v[0].second == v[1].second && v[1].second == v[2].second &&
      v[0].first + 1 == v[1].first && v[1].first + 1 == v[2].first)
    ans(0);
  if (v[0].second == v[1].second && v[0].first + 3 > v[1].first) ans(1);
  if (v[1].second == v[2].second && v[1].first + 3 > v[2].first) ans(1);
  if (v[0].second == v[2].second && v[0].first + 3 > v[2].first) ans(1);
  ans(2);
}
