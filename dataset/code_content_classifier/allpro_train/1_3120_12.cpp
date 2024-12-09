#include <bits/stdc++.h>
using namespace std;
int n, x, y, mid, l, r = 1e9, lol;
string s;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << 1 << " " << mid << "\n";
    cin >> s;
    if (i == 1) lol = s[0];
    if (s[0] == lol)
      l = mid;
    else
      r = mid;
    mid = (l + r) / 2;
  }
  cout << 0 << " " << l << " " << 2 << " " << r;
  return 0;
}
