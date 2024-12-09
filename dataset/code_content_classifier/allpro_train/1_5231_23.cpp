#include <bits/stdc++.h>
using namespace std;
int n, i, j, a, ans, min1 = 1000000;
int k[101];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> k[i];
  for (i = 1; i <= n; i++) {
    ans = k[i] * 15;
    for (j = 1; j <= k[i]; j++) cin >> a, ans += a * 5;
    if (ans < min1) min1 = ans;
  }
  cout << min1 << endl;
  return 0;
}
