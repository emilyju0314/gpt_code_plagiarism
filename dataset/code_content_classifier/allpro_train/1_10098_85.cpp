#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  int n;
  string s, res = "";
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if ((n - i) & 1)
      res = res + s[i];
    else
      res = s[i] + res;
  }
  cout << res;
  return 0;
}
