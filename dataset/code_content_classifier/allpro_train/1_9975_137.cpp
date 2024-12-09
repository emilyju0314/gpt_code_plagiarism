#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, c;
  string exp, ans;
  char p;
  cin >> t;
  while (t--) {
    cin >> exp;
    long long int l = exp.length();
    p = '1';
    c = 1;
    for (int i = 0; i < l; i++) {
      bool arr[3] = {0};
      if (exp[i] == '?') {
        if (i > 0) {
          arr[exp[i - 1] - 'a'] = true;
        }
        if (i < l) {
          arr[exp[i + 1] - 'a'] = true;
        }
        for (int j = 0; j < 3; j++) {
          if (arr[j] == false) {
            exp[i] = 'a' + j;
          }
        }
      }
      if (exp[i] == p) {
        c = 0;
        break;
      }
      p = exp[i];
    }
    if (c) {
      cout << exp << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
