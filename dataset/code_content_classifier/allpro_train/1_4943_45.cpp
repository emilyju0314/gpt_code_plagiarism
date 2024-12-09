#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, x, i, sum, cur;
  cin >> q;
  while (q--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      mp[x]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) v.push_back(it->second);
    sort(v.rbegin(), v.rend());
    cur = v[0];
    sum = 0;
    for (i = 0; i < v.size(); i++) {
      cur = min(cur, v[i]);
      sum += cur;
      cur--;
      if (cur == 0) break;
    }
    cout << sum << '\n';
    v.clear();
    mp.clear();
  }
}
