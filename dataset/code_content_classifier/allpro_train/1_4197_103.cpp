#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  int ans = v[0].second;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].second >= ans)
      ans = v[i].second;
    else
      ans = v[i].first;
  }
  cout << ans << endl;
  return 0;
}
