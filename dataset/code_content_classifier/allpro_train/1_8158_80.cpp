#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  vector<pair<long long int, long long int>> v;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  long long int x = v[0].first, y = v[0].second;
  long long int num = 0;
  for (long long int i = 1; i < v.size(); i++) {
    if (v[i].first > x and v[i].first < y and v[i].second > x and
        v[i].second < y)
      num++;
    else
      x = v[i].first, y = v[i].second;
  }
  cout << num << "\n";
  return 0;
}
