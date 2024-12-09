#include <bits/stdc++.h>
using namespace std;
string ans, ab = "ab";
string rest = " cdefghijklmnopqrstuvwxyz";
int n, k, i, lim;
int main() {
  cin >> n >> k;
  if (k > n || (n > 1 && k == 1))
    ans = "-1";
  else {
    if (n > 2)
      lim = n - k + 2;
    else
      lim = n;
    for (i = 1; i <= lim; i++) ans += ab[i % 2 == 0 ? 1 : 0];
    if (n > 2)
      for (i = 1; i <= k - 2; i++) ans += rest[i];
  }
  cout << ans << endl;
}
