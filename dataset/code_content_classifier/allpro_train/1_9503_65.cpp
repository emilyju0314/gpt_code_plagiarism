#include <bits/stdc++.h>
using namespace std;
bool ispalin(char s[51]) {
  int i, l;
  l = strlen(s);
  for (i = 0; i < strlen(s) / 2; i++) {
    if (s[i] != s[l - i - 1]) break;
  }
  if (i != l / 2) return false;
  return true;
}
int main() {
  char s[51];
  cin >> s;
  if (strlen(s) == 1) {
    cout << 0 << endl;
    return 0;
  }
  while (ispalin(s)) {
    s[strlen(s) - 1] = '\0';
    if (strlen(s) == 1) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << strlen(s) << endl;
  return 0;
}
