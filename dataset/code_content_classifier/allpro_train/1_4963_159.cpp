#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    m = s.length();
    string ans = "", b = "";
    int i, j, k, h = 0;
    for (k = 1; k < m; k++)
      if (s[k] == s[k - 1] && s[k] == ':') break;
    for (i = 0; i < k; i = j + 1) {
      for (j = i; j < k && s[j] != ':'; j++)
        ;
      h++;
      ans += string(4 - j + i, '0') + s.substr(i, j - i + 1);
    }
    if (k == m - 1) {
      h++;
      b = "0000";
    } else
      for (i = k + 1; i < m; i = j + 1) {
        for (j = i; j < m && s[j] != ':'; j++)
          ;
        h++;
        b += string(4 - j + i, '0') + s.substr(i, j - i + 1);
      }
    h = 8 - h;
    while (h--) ans += "0000:";
    ans += b;
    cout << ans << endl;
  }
}