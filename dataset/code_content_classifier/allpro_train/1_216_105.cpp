#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int main() {
  int n;
  string s;
  cin >> n >> s;
  string ans = "";
  int len = 1, flag = 0;
  if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' ||
      s[0] == 'y')
    flag = 1;
  else
    ans += s[0];
  if (s[0] != s[1] && flag) ans += s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'y')
      flag = 1;
    else
      flag = 0;
    if (flag) {
      if (s[i] == s[i - 1]) len++;
      if (s[i] != s[i + 1]) {
        ans += s[i];
        if (len == 2 && (s[i - 1] == 'o' || s[i - 1] == 'e')) ans += s[i - 1];
        len = 1;
      }
    } else {
      if (len > 1) {
        if (len == 2 && (s[i - 1] == 'o' || s[i - 1] == 'e')) {
          ans += s[i - 1];
          ans += s[i - 1];
        } else
          ans += s[i - 1];
      }
      ans += s[i];
      len = 1;
    }
  }
  cout << ans;
  return 0;
}
