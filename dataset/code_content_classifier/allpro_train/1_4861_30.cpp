#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x] += z;
    a[y] -= z;
  }
  vector<pair<long long, int>> u, v;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      u.emplace_back(a[i], i);
    } else if (a[i] < 0) {
      v.emplace_back(-a[i], i);
    }
  }
  if (v.size() == 0) {
    cout << "0\n";
    return 0;
  }
  size_t i = 0, j = 0;
  vector<tuple<int, int, long long>> sol;
  while (1) {
    long long amt = min(u[i].first, v[j].first);
    sol.emplace_back(u[i].second, v[j].second, amt);
    u[i].first -= amt;
    v[j].first -= amt;
    if (!u[i].first) i++;
    if (!v[j].first) j++;
    if (i == u.size()) break;
  }
  cout << sol.size() << '\n';
  for (auto [x, y, z] : sol) cout << x << ' ' << y << ' ' << z << '\n';
}
