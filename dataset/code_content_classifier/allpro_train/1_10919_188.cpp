#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  cin >> s >> p;
  for (int i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
  }
  for (int i = 0; i < p.size(); i++) {
    p[i] = tolower(p[i]);
  }
  if (s < p) {
    cout << -1 << endl;
  }
  if (s > p) {
    cout << 1 << endl;
  }
  if (s == p) {
    cout << 0 << endl;
  }
  return 0;
}
