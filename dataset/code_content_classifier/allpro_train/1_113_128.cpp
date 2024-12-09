#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int c1 = 0, c2 = 0, c3 = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      c1++;
    else if (s[i] == '2')
      c2++;
    else
      c3++;
    i++;
  }
  string s2;
  while (c1 > 0) {
    s2 += "1+";
    c1--;
  }
  while (c2 > 0) {
    s2 += "2+";
    c2--;
  }
  while (c3 > 0) {
    s2 += "3+";
    c3--;
  }
  s2.resize(s2.size() - 1);
  cout << s2;
  return 0;
}
