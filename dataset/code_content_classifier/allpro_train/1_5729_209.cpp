#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
void solve() {
  cin >> n >> m;
  if (n % m == 0)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
