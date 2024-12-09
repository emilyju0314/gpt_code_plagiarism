#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int i, p = 0;
  for (i = 0; i < s.size(); i++) {
    if (s[i] != '1' && s[i] != '4' || s[0] == '4') p++;
    if (s[i] == '4') {
      if (s[i + 1] == '4' && s[i + 2] == '4') p++;
    }
  }
  if (p == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
