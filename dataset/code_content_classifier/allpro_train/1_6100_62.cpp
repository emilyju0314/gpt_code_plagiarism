#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l;
  string s, t;
  vector<string> v;
  cin >> k >> s;
  s += " ";
  l = s.size();
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.find(s[i]) == i) {
      if (t.size()) v.push_back(t);
      t = "";
      t += s[i];
    } else {
      t += s[i];
    }
  }
  if (v.size() >= k) {
    cout << "YES\n";
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
      if (i < k - 1) cout << '\n';
    }
  } else {
    cout << "NO";
  }
}
