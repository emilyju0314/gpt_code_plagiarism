#include <bits/stdc++.h>
using namespace std;
int c;
string s[2];
int main() {
  cin >> s[0] >> s[1];
  for (int i = 0; i < (int)s[0].length(); i++) {
    if (s[0][i] == '0' && s[1][i] == '0') {
      if (i != 0) {
        if (s[0][i - 1] == '0') {
          s[0][i] = 'X';
          s[1][i] = 'X';
          s[0][i - 1] = 'X';
          c++;
          continue;
        }
        if (s[1][i - 1] == '0') {
          s[0][i] = 'X';
          s[1][i] = 'X';
          s[1][i - 1] = 'X';
          c++;
          continue;
        }
      }
      if (i != (int)(s[0].length() - 1)) {
        if (s[0][i + 1] == '0') {
          s[0][i] = 'X';
          s[1][i] = 'X';
          s[0][i + 1] = 'X';
          c++;
          continue;
        }
        if (s[1][i + 1] == '0') {
          s[0][i] = 'X';
          s[1][i] = 'X';
          s[1][i + 1] = 'X';
          c++;
          continue;
        }
      }
    }
  }
  printf("%d\n", c);
  return 0;
}
