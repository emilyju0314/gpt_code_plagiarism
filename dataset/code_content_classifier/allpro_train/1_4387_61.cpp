#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v.begin() + 1, v.end());
  v[0] = v[1];
  auto get = [&](int x) {
    vector<int> p;
    p.emplace_back(0);
    for (int i = 1; i <= n; i++) {
      int left = lower_bound(v.begin(), v.end(), v[i] - x) - v.begin() - 1;
      int right = i - k;
      auto it = lower_bound(p.begin(), p.end(), left);
      if (it != p.end() and *it <= right) {
        p.emplace_back(i);
      }
    }
    return (find(p.begin(), p.end(), n) != p.end());
  };
  int lo = 0, hi = (v[n] - v[1]), ans = 1e9;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    if (get(md))
      ans = md, hi = md - 1;
    else
      lo = md + 1;
  }
  cout << ans << '\n';
}
