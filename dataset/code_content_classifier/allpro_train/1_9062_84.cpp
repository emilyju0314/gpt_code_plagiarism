#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0, u = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L')
      l++;
    else if (s[i] == 'R')
      r++;
    else if (s[i] == 'U')
      u++;
    else
      d++;
  }
  int x = min(l, r);
  int y = min(u, d);
  int ans = x + y;
  cout << (ans * 2) << endl;
  return 0;
}
