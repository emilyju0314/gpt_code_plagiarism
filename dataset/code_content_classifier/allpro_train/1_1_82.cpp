#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
long long x[N], y[N], deg[N];
vector<long long> vp[N];
long long removed[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
    vp[x[i]].push_back(y[i]);
    vp[y[i]].push_back(x[i]);
    deg[x[i]]++;
    deg[y[i]]++;
  }
  set<pair<long long, long long> > s;
  for (long long i = 1; i <= n; i++) {
    s.insert({deg[i], i});
  }
  long long ans = n;
  set<pair<long long, long long> > ae;
  vector<long long> v;
  for (long long i = m; i >= 1; i--) {
    while (s.size() > 0) {
      auto it = *s.begin();
      s.erase(it);
      if (it.first >= k) break;
      removed[it.second] = 1;
      for (auto it1 : vp[it.second]) {
        if (ae.find({it1, it.second}) == ae.end()) {
          ae.insert({it1, it.second});
          ae.insert({it.second, it1});
          if (!removed[it1]) {
            s.erase({deg[it1], it1});
            deg[it1]--;
            s.insert({deg[it1], it1});
          }
        }
      }
      ans--;
    }
    if (ae.find({x[i], y[i]}) == ae.end()) {
      ae.insert({x[i], y[i]});
      ae.insert({y[i], x[i]});
      s.erase({deg[x[i]], x[i]});
      s.erase({deg[y[i]], y[i]});
      if (!removed[x[i]]) {
        deg[x[i]]--;
        s.insert({deg[x[i]], x[i]});
      }
      if (!removed[y[i]]) {
        deg[y[i]]--;
        s.insert({deg[y[i]], y[i]});
      }
    }
    v.push_back(ans);
  }
  reverse(v.begin(), v.end());
  for (auto it : v) {
    cout << it << "\n";
  }
}
