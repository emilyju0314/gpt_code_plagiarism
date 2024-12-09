#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t, n, v;
  vector<long long> a, b;
  cin >> t;
  while (t--) {
    a.clear();
    b.clear();
    cin >> n;
    long long mn = 1000000001;
    for (long long i = (0); i < (n); i++) {
      cin >> v;
      a.push_back(v);
      if (mn > v) mn = v;
    }
    for (long long i = (0); i < (n); i++) {
      if (a[i] % mn == 0)
        continue;
      else
        b.push_back(i);
    }
    if (b.size() == 0) {
      cout << "YES\n";
    } else if (b.size()) {
      vector<pair<long long, long long>> c;
      for (long long i = (0); i < (b.size()); i++)
        c.push_back(make_pair(a[b[i]], b[i]));
      sort(c.begin(), c.end());
      sort(a.begin(), a.end());
      long long flag = 1;
      for (long long i = (0); i < (c.size()); i++) {
        if (a[c[i].second] != c[i].first) {
          flag = 0;
          break;
        }
      }
      if (flag)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
