#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 1, n, m, k;
  cin >> n >> m >> k;
  if (n == k) {
    for (int i = 1; i <= (k + 1) / 2; i++) ans = (ans * m) % 1000000007;
    cout << ans << endl;
  } else if (k == 1 || k > n) {
    for (int i = 1; i <= n; i++) ans = (ans * m) % 1000000007;
    cout << ans << endl;
  } else if (k % 2 == 0)
    cout << m << endl;
  else
    cout << m * m % 1000000007 << endl;
  return 0;
}
