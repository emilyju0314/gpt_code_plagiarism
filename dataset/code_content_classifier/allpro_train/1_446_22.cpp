#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    int count = 1;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (i != 0) {
        if (s[i] != s[i - 1]) {
          s.erase((i - 1), 2);
          count++;
          i = 0;
        }
      }
    }
    if (count % 2 == 0) {
      cout << "DA" << endl;
    } else {
      cout << "NET" << endl;
    }
  }
}
