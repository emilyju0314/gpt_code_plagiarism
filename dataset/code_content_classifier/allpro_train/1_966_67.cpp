#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  int n, k;
  while (cin >> n >> k) {
    cin >> str;
    str.insert(0, "1");
    str.insert(n + 1, "1");
    int f = 1;
    while (k) {
      for (; f < str.size() - 1; ++f) {
        if (str[f] == '4' && str[f + 1] == '7') break;
      }
      if (f == str.size() - 1) break;
      if (str[f - 1] == '4' && f % 2 == 0) {
        if (k % 2) str[f] = '7';
        break;
      } else if (str[f + 2] == '7' && f % 2) {
        if (k % 2) str[f + 1] = '4';
        break;
      } else {
        if (f % 2) {
          str[f + 1] = '4';
          f++;
        } else {
          str[f] = '7';
          f--;
        }
      }
      k--;
    }
    for (int i = 1; i <= n; ++i) cout << str[i];
    cout << endl;
  }
  return 0;
}
