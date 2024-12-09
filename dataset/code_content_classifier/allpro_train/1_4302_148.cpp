#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  set<char> s;
  long long n = a.length();
  map<char, vector<long long> > mm;
  for (long long i = 0; i < n; ++i) {
    mm[a[i]].push_back(i);
    s.insert(a[i]);
  }
  for (auto i : s) {
    mm[i].push_back(-1);
    mm[i].push_back(n);
    sort(mm[i].begin(), mm[i].end());
  }
  long long mn = 1e9;
  for (auto i : mm) {
    long long mx = 0;
    long long k = i.second.size();
    for (long long j = 0; j < k - 1; j++) {
      mx = max(mx, i.second[j + 1] - i.second[j]);
    }
    mn = min(mx, mn);
  }
  cout << mn;
}
