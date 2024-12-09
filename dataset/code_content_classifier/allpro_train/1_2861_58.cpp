#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long check(long long x) {
  if (__builtin_popcountll(x + 1) == 1) return 1;
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long x;
  cin >> x;
  vector<long long> v;
  long long reqd = 0;
  while (!check(x)) {
    for (long long i = 20; i >= 0; i--) {
      if (((x >> i) & 1)) {
        reqd++;
        v.push_back(i + 1);
        x ^= ((1LL << (i + 1)) - 1);
        break;
      }
    }
    if (!check(x)) {
      reqd++;
      x++;
    }
  }
  cout << reqd << "\n";
  for (auto &it : v) cout << it << " ";
  return 0;
}
