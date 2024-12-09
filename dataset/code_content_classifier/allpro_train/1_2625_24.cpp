#include <bits/stdc++.h>
using namespace std;
template <class T>
T xabs(const T &x) {
  return x < 0 ? -x : x;
}
int main() {
  int n, d;
  cin >> n >> d;
  vector<string> as(n), bs(n);
  vector<int> a(n), b(n), t(n);
  for (int i = 0; i < n; ++i) cin >> as[i] >> bs[i] >> t[i];
  map<string, int> names;
  for (int i = 0; i < n; ++i) {
    int sz = names.size();
    if (!names.count(as[i])) names[as[i]] = sz;
    sz = names.size();
    if (!names.count(bs[i])) names[bs[i]] = sz;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = names[as[i]];
    b[i] = names[bs[i]];
  }
  vector<vector<int> > dist(names.size(), vector<int>(names.size(), 0));
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j)
      if (a[i] == b[j] && b[i] == a[j]) {
        int x = a[i];
        int y = b[i];
        if (x > y) swap(x, y);
        int lng = xabs(t[j] - t[i]);
        if (lng != 0 && (dist[x][y] == 0 || dist[x][y] > lng)) {
          dist[x][y] = lng;
          break;
        }
      }
  vector<pair<int, int> > res;
  for (int i = 0; i < names.size() - 1; ++i)
    for (int j = i + 1; j < names.size(); ++j)
      if (0 < dist[i][j] && dist[i][j] <= d) res.push_back(make_pair(i, j));
  map<int, string> nums;
  for (map<string, int>::iterator it = names.begin(); it != names.end(); ++it)
    nums[it->second] = it->first;
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i)
    cout << nums[res[i].first] << " " << nums[res[i].second] << endl;
  return 0;
}
