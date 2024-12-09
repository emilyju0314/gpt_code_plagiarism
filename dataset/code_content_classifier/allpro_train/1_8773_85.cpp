#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, len, ans = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    for (j = i + 1; j < s.size(); j++) {
      if (s[i] == s[j]) {
        len = 1;
        while (j + len < s.size() && s[i + len] == s[j + len]) len++;
        if (len > ans) ans = len;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
