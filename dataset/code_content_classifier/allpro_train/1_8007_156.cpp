#include <bits/stdc++.h>
using namespace std;
int main() {
  int tL[26] = {0}, tU[26] = {0}, sL[26] = {0}, sU[26] = {0};
  int YAY = 0, WHOOPS = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (islower(s[i]))
      ++sL[s[i] - 'a'];
    else
      ++sU[s[i] - 'A'];
  }
  for (int i = 0; i < (int)t.size(); ++i) {
    if (islower(t[i]))
      ++tL[t[i] - 'a'];
    else
      ++tU[t[i] - 'A'];
  }
  for (int i = 0; i < 26; ++i) {
    if (sL[i]) {
      int m = min(sL[i], tL[i]);
      YAY += m, sL[i] -= m, tL[i] -= m;
    }
    if (sU[i]) {
      int m = min(sU[i], tU[i]);
      YAY += m, sU[i] -= m, tU[i] -= m;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (sL[i]) {
      int m = min(sL[i], tU[i]);
      WHOOPS += m, sL[i] -= m, tU[i] -= m;
    }
    if (sU[i]) {
      int m = min(sU[i], tL[i]);
      WHOOPS += m, sU[i] -= m, tL[i] -= m;
    }
  }
  cout << YAY << ' ' << WHOOPS;
  return 0;
}
