#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, x, y;
  char c;
  int i;
  while (cin >> a >> b) {
    if (a == "0") {
      cout << (b == "0" ? "OK" : "WRONG_ANSWER") << endl;
      continue;
    }
    sort(a.begin(), a.end());
    for (i = 0; i < a.length(); i++) {
      if (a[i] != '0') {
        c = a[i];
        break;
      }
    }
    x.clear();
    x = a.substr(0, i);
    y = a.substr(i + 1, a.length());
    x = x + y + "s";
    for (i = x.length() - 2; i >= 0; i--) {
      x[i + 1] = x[i];
    }
    x[0] = c;
    if (x == b) {
      cout << "OK\n";
    } else {
      cout << "WRONG_ANSWER\n";
    }
  }
  return 0;
}
