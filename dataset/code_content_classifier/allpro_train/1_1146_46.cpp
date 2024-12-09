#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin.ignore();
    string s;
    cin >> s;
    int i = s.length() - 1;
    if (i - 1 >= 0 && s[i] == 'o' && s[i - 1] == 'p')
      cout << "FILIPINO" << endl;
    else if (i - 3 >= 0 && (s[i - 3] == 'd' || s[i - 3] == 'm') &&
             (s[i - 2] == 'e' || s[i - 2] == 'a') && s[i - 1] == 's' &&
             s[i] == 'u')
      cout << "JAPANESE" << endl;
    else
      cout << "KOREAN" << endl;
  }
  return 0;
}
