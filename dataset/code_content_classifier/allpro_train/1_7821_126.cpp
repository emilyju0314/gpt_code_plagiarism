#include <bits/stdc++.h>
using namespace std;
void func1(string s) {
  int r = 0, c = 0;
  int i = 1;
  for (;; i++) {
    if (s[i] == 'C')
      break;
    else
      r = r * 10 + ((int)s[i] - 48);
  }
  i++;
  for (; i < s.size(); i++) {
    c = c * 10 + ((int)s[i] - 48);
  }
  string ans;
  while (c > 0) {
    if (c % 26 == 0) {
      ans = 'Z' + ans;
      c = c / 26 - 1;
    } else {
      ans = (char)(c % 26 + 64) + ans;
      c = c / 26;
    }
  }
  cout << ans << r << endl;
}
void func2(string s) {
  int c = 0, i = 0;
  for (i = 0;; i++) {
    if (s[i] >= '0' && s[i] <= '9') break;
    c = c * 26 + ((int)(s[i]) - 64);
  }
  cout << "R";
  for (; i < s.size(); i++) cout << s[i];
  cout << "C" << c << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int flag = 0;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i] >= 'A' && s[i] <= 'Z') {
        func1(s);
        flag = 1;
      }
    }
    if (!flag) func2(s);
  }
  return 0;
}
