#include <bits/stdc++.h>
using namespace std;
string s[100];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  int res = 0x3f3f3f;
  int flag = 0;
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = 1; j <= n; ++j) {
      string str = s[j] + s[j];
      if (str.find(s[i]) == string::npos)
        flag = 1;
      else
        sum += str.find(s[i]);
    }
    res = min(res, sum);
  }
  if (flag)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
