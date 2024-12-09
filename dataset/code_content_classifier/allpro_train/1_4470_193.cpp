#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string s;
  cin >> s >> k;
  set<char> c;
  for (int i = 0; i < s.length(); i++) {
    c.insert(s[i]);
  }
  if (s.length() < k) {
    cout << "impossible";
    return 0;
  }
  int lagbe = k - c.size();
  cout << max(0, lagbe);
}
