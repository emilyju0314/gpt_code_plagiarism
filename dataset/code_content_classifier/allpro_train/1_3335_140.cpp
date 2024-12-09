#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m, ans = 0;
  cin >> n >> m;
  while (n && m) {
    if (n == 1 && m == 1) break;
    ans++;
    if (n > m)
      n -= 2, m++;
    else
      n++, m -= 2;
  }
  cout << ans << endl;
}
