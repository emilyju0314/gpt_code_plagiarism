#include <bits/stdc++.h>
using namespace std;
int ans[100];
char tp[300];
string ch;
int cal(string a, int base) {
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    if (tp[a[i]] >= base)
      return -1;
    else {
      ans *= base;
      ans += tp[a[i]];
    }
  }
  return ans;
}
int main() {
  for (int i = 0; i < 10; i++) tp['0' + i] = i;
  for (int i = 0; i < 26; i++) tp['A' + i] = 10 + i;
  while (cin >> ch) {
    int flag;
    for (int i = 0; i < ch.size(); i++)
      if (ch[i] == ':') {
        flag = i;
        break;
      }
    string a = ch.substr(0, flag), b = ch.substr(flag + 1);
    int n = 0;
    for (int i = 1; i <= 101; i++) {
      int H = cal(a, i), M = cal(b, i);
      if (H < 0 || M < 0 || H > 23 || M > 59)
        continue;
      else {
        ans[n++] = i;
        if (i == 101) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
    if (n == 0)
      cout << 0 << endl;
    else {
      for (int i = 0; i < n; i++) cout << ans[i] << " ";
      cout << endl;
    }
  }
}
