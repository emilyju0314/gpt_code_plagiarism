#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 4;
int n, l;
set<long long> v;
map<long long, vector<pair<pair<long long, long long>, long long> > > adj;
map<long long, long long> dp;
map<long long, pair<long long, long long> > par;
set<pair<long long, long long> > s;
long long cnt = 0;
void di() {
  s.insert({0, 0});
  while (s.size()) {
    long long x = s.begin()->second;
    long long ind = s.begin()->first;
    s.erase(s.begin());
    for (int i = 0; i < adj[x].size(); i++) {
      long long a = adj[x][i].first.first;
      long long ww = adj[x][i].first.second;
      long long indd = adj[x][i].second;
      if (dp[a] == 0 || dp[a] > dp[x] + ww) {
        s.erase({dp[a], a});
        dp[a] = dp[x] + ww;
        s.insert({dp[a], a});
        par[a] = {x, indd};
      }
    }
  }
  return;
}
void print(long long pos) {
  if (pos == 0) {
    cout << cnt << endl;
    return;
  }
  if (par[pos].second != -1) cnt++;
  print(par[pos].first);
  if (par[pos].second != -1) {
    cout << 1 + par[pos].second << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l;
  if (n == 0) {
    cout << l << endl;
    cout << 0 << endl;
    return 0;
  }
  v.insert(0);
  adj[0].push_back({{l, l}, -1});
  for (int i = 0; i < n; i++) {
    int x, d, t, p;
    cin >> x >> d >> t >> p;
    if (x - p >= 0) {
      v.insert(x - p);
      v.insert(x + d);
      adj[x - p].push_back({{x + d, p + t}, i});
    }
  }
  v.insert(l);
  while (v.size()) {
    long long u = *v.begin();
    v.erase(u);
    long long x = *v.begin();
    adj[u].push_back({{x, abs(x - u)}, -1});
    adj[x].push_back({{u, abs(x - u)}, -1});
  }
  dp[0] = 0;
  par[0] = {-1, -1};
  di();
  cout << dp[l] << endl;
  print(l);
  return 0;
}
