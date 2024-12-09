#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x, k = 0, ans = 0;
  cin >> n;
  string m[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  while (n > 5) n = n / 2 - 2;
  cout << m[n - 1];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    solve();
    cout << '\n';
  }
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
