#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() == 2) {
      cout << s << endl;
    } else {
      cout << s[0];
      for (i = 1; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
          cout << s[i];
          i++;
        } else {
          cout << s[i];
        }
      }
      cout << s[s.length() - 1] << endl;
    }
  }
}
