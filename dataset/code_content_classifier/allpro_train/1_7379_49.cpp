#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 2e5 + 1;
void Solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a + b, c + d) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    Solve();
  }
}
