#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e5 + 5;
unsigned long long pw[67];
void pre() {
  pw[0] = 1;
  for (int i = 1; i < 64; i++) pw[i] = 2 * pw[i - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  pre();
  vector<pair<int, pair<int, long long> > > v, f;
  int n, i;
  int a;
  long long t, tot;
  cin >> n >> tot;
  for (i = 0; i < n; i++) {
    cin >> a >> t;
    v.push_back(make_pair(a, make_pair(i, t)));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long cur = 0;
  int ans = -1;
  multiset<pair<long long, int> > mt, fu;
  for (i = 0; i < n; i++) {
    int mx = v[i].first;
    long long ti = v[i].second.second;
    cur += ti;
    mt.insert(make_pair(-ti, v[i].second.first));
    while (mt.size() > mx) {
      long long foo = (*mt.begin()).first;
      foo = -foo;
      mt.erase(mt.begin());
      cur -= foo;
    }
    while (cur > tot) {
      long long foo = (*mt.begin()).first;
      foo = -foo;
      mt.erase(mt.begin());
      cur -= foo;
    }
    int tu = mt.size();
    if (tu > ans) {
      ans = tu;
    }
  }
  cur = 0;
  for (i = 0; i < n; i++) {
    int mx = v[i].first;
    int ti = v[i].second.second;
    cur += ti;
    fu.insert(make_pair(-ti, v[i].second.first));
    while (fu.size() > mx) {
      long long foo = (*fu.begin()).first;
      foo = -foo;
      fu.erase(fu.begin());
      cur -= foo;
    }
    while (cur > tot) {
      long long foo = (*fu.begin()).first;
      foo = -foo;
      fu.erase(fu.begin());
      cur -= foo;
    }
    int tu = fu.size();
    if (tu == ans) {
      break;
    }
  }
  cout << ans << endl;
  cout << ans << endl;
  while (!fu.empty()) {
    int id = (*fu.begin()).second;
    cout << id + 1 << " ";
    fu.erase(fu.begin());
  }
  cout << endl;
  return 0;
}
