#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, k;
  cin >> n;
  map<pair<long long, long long>, long long> freq;
  map<long long, long long> xf, yf;
  long long x, y;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (xf.find(x) == xf.end()) {
      xf.insert(make_pair(x, 1));
    } else
      xf[x]++;
    if (yf.find(y) == yf.end()) {
      yf.insert(make_pair(y, 1));
    } else
      yf[y]++;
    pair<long long, long long> p = make_pair(x, y);
    if (freq.find(p) == freq.end()) {
      freq.insert(make_pair(p, 1));
    } else
      freq[p]++;
  }
  long long ans = 0;
  for (auto xx : xf) {
    if (xx.second > 1) {
      ans += (xx.second * (xx.second - 1)) / 2;
    }
  }
  for (auto xx : yf) {
    if (xx.second > 1) {
      ans += (xx.second * (xx.second - 1)) / 2;
    }
  }
  for (auto xx : freq) {
    if (xx.second > 1) {
      ans -= (xx.second * (xx.second - 1)) / 2;
    }
  }
  cout << ans;
  return 0;
}
