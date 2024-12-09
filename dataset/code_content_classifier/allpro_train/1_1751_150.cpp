#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, zer = -1, one;
    cin >> n;
    string s;
    string ans = "";
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') break;
      zer = i;
    }
    one = n;
    for (i = n - 1; i >= 0; i--) {
      if (s[i] == '0') break;
      one = i;
    }
    for (i = 0; i <= zer; i++) ans = ans + '0';
    if (zer + 1 != one) ans = ans + '0';
    for (i = n - 1; i >= one; i--) ans = ans + '1';
    cout << ans << endl;
  }
}
