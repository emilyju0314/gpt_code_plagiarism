#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  multiset<pair<long long, long long>> se;
  long long tim[n];
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    se.insert({a, i});
  }
  for (long long i = 0; i < n; i++) cin >> tim[i];
  long long ans = 0;
  auto itr = se.begin();
  multiset<long long, greater<long long>> cur_t;
  long long k = (*itr).first;
  long long cost = tim[(*itr).second];
  cur_t.insert(tim[(*itr).second]);
  itr++;
  while (itr != se.end()) {
    if (k == (*itr).first) {
      cur_t.insert(tim[(*itr).second]);
      cost += tim[(*itr).second];
    } else {
      while (k < (*itr).first && !(cur_t.empty())) {
        auto ptr = cur_t.begin();
        cost -= *(ptr);
        cur_t.erase(ptr);
        k++;
        ans += cost;
      }
      k = (*itr).first;
      if (cur_t.empty()) cost = 0;
      cur_t.insert(tim[(*itr).second]);
      cost += tim[(*itr).second];
    }
    itr++;
    if (cost < 0) cost = 0;
  }
  while (!cur_t.empty()) {
    auto ptr = cur_t.begin();
    cost -= *(ptr);
    cur_t.erase(ptr);
    ans += cost;
  }
  cout << ans << "\n";
  return 0;
}
