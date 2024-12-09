#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  vector<int> v;
  int l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l] == '(') {
      if (s[r] == ')') {
        v.push_back(l);
        v.push_back(r);
        ++l;
        --r;
      } else
        --r;
    } else
      ++l;
  }
  if (v.empty())
    cout << 0;
  else {
    cout << 1 << "\n" << v.size() << "\n";
    sort(v.begin(), v.end());
    for (auto x : v) cout << x + 1 << ' ';
  }
  return 0;
}
