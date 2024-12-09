#include <bits/stdc++.h>
using namespace std;
const long long M = 1e6 + 9, MOD = 1e9 + 2;
string s, p;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n >> s;
  if (n == 0) {
    cout << s << endl;
    return 0;
  }
  if (m == 1) {
    cout << "0" << endl;
    return 0;
  }
  int i = 0;
  while (n > 0 && i < m) {
    if (i == 0) {
      if (s[i] != '1') {
        s[i] = '1';
        n--;
      }
    } else if (s[i] != '0') {
      s[i] = '0';
      n--;
    }
    i++;
  }
  cout << s << endl;
  return 0;
}
