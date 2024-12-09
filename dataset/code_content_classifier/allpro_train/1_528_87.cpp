#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, x, y;
  cin >> q >> x;
  set<pair<long long, long long>> s;
  map<long long, long long> mp;
  for (long long i = 0; i < x; i++) {
    s.insert({mp[i], i});
  }
  while (q--) {
    cin >> y;
    y = y % x;
    s.erase({mp[y], y});
    mp[y]++;
    s.insert({mp[y], y});
    cout << s.begin()->first * x + s.begin()->second << endl;
  }
}
