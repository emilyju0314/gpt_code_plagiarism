#include <bits/stdc++.h>
using namespace std;
int ans[5];
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  ;
  string s = "0000";
  int a = 0, b = 0, mx = 0;
  for (int i = 0; i < 4; i++) {
    mx = 0;
    for (int j = 0; j < 10; j++) {
      s[i] = char(j + '0');
      cout << s << endl;
      cin >> a >> b;
      if (a > mx) {
        mx = a;
        ans[i] = j;
      }
    }
    s[i] = '0';
  }
  for (int i = 0; i < 4; i++) {
    cout << char('0' + ans[i]);
  }
  cout << endl;
}
