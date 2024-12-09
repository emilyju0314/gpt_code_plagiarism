#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
int main() {
  string s;
  cin >> s;
  set<int> cnt0, cnt1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') cnt0.insert(i);
    if (s[i] == '1') cnt1.insert(i);
  }
  vector<vector<int> > ans;
  while (!cnt0.empty()) {
    vector<int> val;
    val.push_back(*cnt0.begin());
    cnt0.erase(cnt0.begin());
    while (true) {
      auto one = cnt1.upper_bound(val.back());
      if (one == cnt1.end()) break;
      auto nxtz = cnt0.upper_bound(*one);
      if (nxtz == cnt0.end()) break;
      val.push_back(*one);
      val.push_back(*nxtz);
      cnt1.erase(one);
      cnt0.erase(nxtz);
    }
    ans.push_back(val);
  }
  if (cnt0.size() > 0 || cnt1.size() > 0) return cout << -1, 0;
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v.size() << " ";
    for (auto x : v) cout << x + 1 << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
