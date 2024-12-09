#include <bits/stdc++.h>
using namespace std;
const long double PI = acos((long double)-1);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int cnt = 0;
  while (s != "1") {
    if (s.back() == '1') {
      int p = ((int)(s).size()) - 1;
      while (p > -1) {
        if (s[p] != '1') break;
        s[p--] = '0';
      }
      if (p == -1) {
        s = '1' + s;
      } else {
        s[p] = '1';
      }
    } else {
      s.pop_back();
    }
    ++cnt;
  }
  cout << cnt;
  return 0;
}
