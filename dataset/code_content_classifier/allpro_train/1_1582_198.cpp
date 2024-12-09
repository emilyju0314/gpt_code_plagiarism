#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      m -= x;
    }
    if (m == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
