#include <bits/stdc++.h>
using namespace std;
vector<int> v[2];
long long mind[2], minc[2];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (int i = 0; i < 2; i++) sort(v[i].begin(), v[i].end());
  long long cnt = 0;
  for (int i = 0; i < 2; i++) {
    for (auto k : v[i]) {
      long long pl =
          lower_bound(v[i ^ 1].begin(), v[i ^ 1].end(), k) - v[i ^ 1].begin();
      long long pr =
          upper_bound(v[i ^ 1].begin(), v[i ^ 1].end(), k) - v[i ^ 1].begin();
      cnt += pl * ((long long)v[i ^ 1].size() - pr);
      cnt += (pr - pl) * ((long long)v[i ^ 1].size() - pr + pl) +
             (pr - pl) * (pr - pl - 1) / 2;
    }
  }
  if (cnt) {
    cout << cnt << '\n';
    return 0;
  }
  for (int i = 0; i < 2; i++) {
    if ((int)v[i].size() == 0) continue;
    long long c1 = 0, c2 = 0;
    for (auto k : v[i]) {
      if (k == v[i][0]) c1++;
      if (k == v[i][(int)v[i].size() - 1]) c2++;
    }
    mind[i] = v[i][(int)v[i].size() - 1] - v[i][0];
    if (mind[i] == 0)
      minc[i] = c1 * (c1 - 1) * (c1 - 2) / 6;
    else
      minc[i] = c1 * c2 * (m - c1 - c2) + c1 * c2 * (c1 + c2 - 2) / 2;
  }
  if (!v[0].size() || !v[1].size()) {
    cout << minc[0] + minc[1] << endl;
    return 0;
  }
  int i = 0;
  if (v[0][0] < v[1][0]) i = 1;
  long long mn = v[i][0], mnc = 0, mx = v[1 - i][(int)v[1 - i].size() - 1],
            mxc = 0;
  for (auto k : v[i])
    if (k == mn) mnc++;
  for (auto k : v[1 - i])
    if (k == mx) mxc++;
  cout << mnc * mxc * (m - mnc - mxc) + mnc * mxc * (mnc + mxc - 2) / 2 << endl;
}
