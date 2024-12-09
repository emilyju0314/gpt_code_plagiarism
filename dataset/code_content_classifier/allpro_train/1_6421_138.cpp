#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> mins, maxs;
  long long ans = 0;
  long long acc = 0;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    int mn = 1e9, mx = -1;
    bool ok = false;
    for (int j = 0, x; j < m; ++j) {
      cin >> x;
      mn = min(mn, x);
      mx = max(mx, x);
      if (x > mn) ok = true;
    }
    if (ok)
      acc++;
    else {
      mins.push_back(mn);
      maxs.push_back(mx);
    }
  }
  ans = acc * acc + 2 * acc * (n - acc);
  sort(maxs.begin(), maxs.end());
  long long limit = maxs.size();
  for (int i = 0; i < mins.size(); ++i) {
    int idx = upper_bound(maxs.begin(), maxs.end(), mins[i]) - maxs.begin();
    ans += limit - idx;
  }
  cout << ans << '\n';
  return 0;
}
