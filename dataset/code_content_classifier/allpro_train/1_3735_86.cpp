#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] <= 90) {
      s[i] += 32;
    }
    if (s[i] != 'a' && s[i] != 'u' && s[i] != 'y' && s[i] != 'i' &&
        s[i] != 'e' && s[i] != 'o') {
      cout << '.' << s[i];
    }
  }
  return 0;
}
