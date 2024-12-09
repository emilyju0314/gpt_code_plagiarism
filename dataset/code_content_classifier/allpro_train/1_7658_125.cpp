#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int MOD1 = 998244353;
mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a[n];
  long long int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<int> v[n];
  for (int i = 0; i < m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    t1--;
    t2--;
    v[t1].emplace_back(t2);
    v[t2].emplace_back(t1);
  }
  sort(a, a + n);
  for (int i = 0; i < n;) {
    int j = a[i].second;
    if (v[j].size() > 0) {
      res += a[i].first;
      int t = v[j].back();
      v[j].pop_back();
      auto it = find(v[t].begin(), v[t].end(), j);
      v[t].erase(it);
    }
    if (v[j].size() == 0) i++;
  }
  cout << res << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
