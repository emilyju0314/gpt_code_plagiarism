#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool k = false;
  cin >> s;
  for (int i = 0; s[i] != 0; i++) {
    if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
      k = true;
      break;
    }
  }
  if (k)
    cout << "YES";
  else
    cout << "NO";
}
