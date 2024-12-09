#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, int> > v;
    int n, x, m, mx, mn;
    cin >> n >> x >> m;
    x--;
    mx = x, mn = x;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    for (int i = 0; i < m; i++) {
      v[i].first--, v[i].second--;
      if (v[i].second < mn || v[i].first > mx) continue;
      mn = min(mn, v[i].first);
      mx = max(mx, v[i].second);
    }
    cout << mx - mn + 1 << endl;
  }
}
