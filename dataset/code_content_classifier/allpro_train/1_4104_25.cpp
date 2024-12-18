#include <bits/stdc++.h>
using namespace std;
int a[300005];
vector<int> v[1000005];
pair<int, int> p[1000005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  for (int i = 1; i <= n; i++) {
    v[max(1, a[i] - k)].push_back(i);
    v[a[i]].push_back(-i);
  }
  int f = 1, s = 1;
  for (int i = 1; i <= a[n]; i++) {
    for (int j = 0; j < v[i].size(); j++) s = max(s, v[i][j] + 1);
    p[i] = make_pair(f, s);
    for (int j = 0; j < v[i].size(); j++) f = max(f, -v[i][j] + 1);
  }
  int ans = 1;
  for (int i = 1; i <= a[n]; i++) {
    int pooshesh = 0, s = 1;
    for (int j = i; j <= a[n]; j += i) {
      pooshesh += min(p[j].second - p[j].first, p[j].second - s);
      s = max(s, p[j].second);
    }
    if (pooshesh == n) ans = i;
  }
  cout << ans << endl;
  return 0;
}
