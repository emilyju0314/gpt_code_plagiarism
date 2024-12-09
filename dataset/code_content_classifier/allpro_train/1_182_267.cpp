#include <bits/stdc++.h>
using namespace std;
int t;
void abc() {
  int n, m, i, x;
  map<char, int> mp;
  string s;
  cin >> n >> m >> s;
  vector<int> p(m);
  for (i = 0; i < m; i++) cin >> p[i], p[i]--;
  sort(p.begin(), p.end());
  for (i = 0; i < s.size(); i++) {
    x = lower_bound(p.begin(), p.end(), i) - p.begin();
    mp[s[i]] += m - x + 1;
  }
  for (i = 0; i < 26; i++) cout << mp['a' + i] << " ";
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) abc();
  return 0;
}
