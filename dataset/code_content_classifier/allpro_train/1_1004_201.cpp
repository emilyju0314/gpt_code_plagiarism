#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d = 0, u = 0, r = 0, l = 0, i;
  string s, t;
  cin >> s;
  a = s.length();
  for (i = 0; i < a; i++) {
    if (s[i] == 'U') {
      u++;
    } else if (s[i] == 'D') {
      d++;
    } else if (s[i] == 'R') {
      r++;
    } else if (s[i] == 'L') {
      l++;
    }
  }
  b = abs(u - d);
  c = abs(r - l);
  if (a % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << (b + c) / 2 << endl;
  return 0;
}
