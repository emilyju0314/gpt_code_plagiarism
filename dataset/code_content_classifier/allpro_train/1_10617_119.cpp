#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int OO = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, x;
  cin >> n;
  map<long long, multiset<pair<long long, long long> > > mp;
  long long arr[n], p[n], a[n], b[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[a[i]].insert({arr[i], b[i]});
    mp[b[i]].insert({arr[i], a[i]});
  }
  cin >> m;
  while (m--) {
    cin >> x;
    if (mp[x].empty())
      cout << -1;
    else {
      pair<long long, long long> y = *(mp[x].begin());
      cout << y.first << ' ';
      mp[x].erase(mp[x].find(y));
      mp[y.second].erase(mp[y.second].find({y.first, x}));
    }
    cout << ' ';
  }
  return 0;
}
