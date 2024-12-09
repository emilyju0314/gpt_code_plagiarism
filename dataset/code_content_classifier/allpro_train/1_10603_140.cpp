#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' &&
        s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'W' &&
        s[i] != 'V' && s[i] != 'Y' && s[i] != 'X') {
      cout << "NO" << endl;
      return 0;
    }
    if (s[i] != s[s.size() - i - 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
