#include <bits/stdc++.h>
using namespace std;
int findp(string s, string p) {
  int i, j = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == p[j]) j++;
    if (j == p.length()) break;
  }
  return i;
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int l = findp(s, "[:") + 1;
  reverse(s.begin(), s.end());
  int r = s.length() - 1 - findp(s, "]:");
  reverse(s.begin(), s.end());
  int ans;
  if (l <= r) {
    ans = 4;
    for (int k = l; k < r; k++)
      if (s[k] == '|') {
        ans++;
      }
  } else {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
