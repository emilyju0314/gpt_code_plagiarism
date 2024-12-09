#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int v = 0, h = 0;
  for (auto c : s) {
    if (c == '0') {
      if (v == 0) cout << "1 1" << endl;
      if (v == 1) cout << "1 2" << endl;
      if (v == 2) cout << "1 3" << endl;
      if (v == 3) cout << "1 4" << endl;
      v++;
      v %= 4;
    } else {
      if (h == 0) cout << "3 1" << endl;
      if (h == 1) cout << "3 3" << endl;
      if (h == 2) cout << "4 1" << endl;
      if (h == 3) cout << "4 3" << endl;
      h++;
      h %= 4;
    }
  }
  return 0;
}
