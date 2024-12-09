#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans, tem;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ans = m * (n / m);
    ans += m / 2;
    cout << min(ans, n) << '\n';
  }
  return 0;
}
