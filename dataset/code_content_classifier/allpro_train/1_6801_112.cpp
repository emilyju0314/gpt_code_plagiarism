#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.size() < 26) {
    cout << -1;
    return 0;
  }
  int a[26], i, j, flag;
  char aa[27];
  memset(a, 0, sizeof(a));
  memset(aa, '?', sizeof(aa));
  for (i = 0; i < (s.size() - 25); i++) {
    flag = 0;
    for (j = i; j < i + 26; j++) {
      if (s[j] != '?') {
        if (a[s[j] - 'A'] == 1) {
          memset(aa, '?', sizeof(aa));
          memset(a, 0, sizeof(a));
          flag = 1;
          break;
        } else {
          a[s[j] - 'A'] = 1;
          aa[j - i] = s[j];
        }
      }
    }
    if (flag == 0) {
      for (int k = 0; k < i; k++) {
        if (s[k] != '?')
          cout << s[k];
        else
          cout << 'A';
      }
      for (int k = 0; k < 26; k++) {
        if (aa[k] != '?')
          cout << aa[k];
        else {
          for (int h = 0; h < 26; h++) {
            if (a[h] == 0) {
              char cc = 'A' + h;
              cout << cc;
              a[h] = 1;
              break;
            }
          }
        }
      }
      for (int k = i + 26; k < s.size(); k++) {
        if (s[k] != '?')
          cout << s[k];
        else
          cout << 'A';
      }
      return 0;
    }
  }
  cout << -1;
}
