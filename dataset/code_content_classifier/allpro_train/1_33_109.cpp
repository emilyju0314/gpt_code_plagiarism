#include <bits/stdc++.h>
using namespace std;
const long long ccn = 1e5 + 1;
vector<long long> byx[ccn];
vector<long long> byy[ccn];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long y, x;
    cin >> y >> x;
    byy[y].push_back(x);
    byx[x].push_back(y);
  }
  for (long long i = 0; i < ccn; i++) {
    sort(byx[i].begin(), byx[i].end());
    sort(byy[i].begin(), byy[i].end());
  }
  auto check = [&](long long y, long long x, long long s) {
    if (y + s >= ccn) return false;
    return binary_search(byy[y].begin(), byy[y].end(), x + s) &&
           binary_search(byy[y + s].begin(), byy[y + s].end(), x) &&
           binary_search(byy[y + s].begin(), byy[y + s].end(), x + s);
  };
  long long res = 0;
  for (long long y = 0; y < ccn; y++) {
    for (auto x : byy[y]) {
      long long ly =
          byy[y].end() - upper_bound(byy[y].begin(), byy[y].end(), x);
      long long lx =
          byx[x].end() - upper_bound(byx[x].begin(), byx[x].end(), y);
      if (ly < lx) {
        for (auto j = upper_bound(byy[y].begin(), byy[y].end(), x);
             j != byy[y].end(); j++) {
          if (check(y, x, *j - x)) res++;
        }
      } else {
        for (auto j = upper_bound(byx[x].begin(), byx[x].end(), y);
             j != byx[x].end(); j++) {
          if (check(y, x, *j - y)) res++;
        }
      }
    }
  }
  cout << res << "\n";
}
