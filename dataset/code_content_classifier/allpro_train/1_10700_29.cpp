#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  bool f = false;
  for (int i = 0; i < n; i++) {
    if (s[i].at(0) == s[i].at(1) && s[i].at(0) == 'O') {
      cout << "YES" << endl;
      f = true;
      s[i].at(0) = '+';
      s[i].at(1) = '+';
      break;
    }
    if (s[i].at(3) == s[i].at(4) && s[i].at(3) == 'O') {
      cout << "YES" << endl;
      f = true;
      s[i].at(3) = '+';
      s[i].at(4) = '+';
      break;
    }
  }
  if (f) {
    for (int i = 0; i < n; i++) cout << s[i] << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
