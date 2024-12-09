#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const I = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int kol = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] > a[i]) kol++;
  }
  if (kol % 2 == 0) {
    cout << "YES\n";
    return;
  }
  if (kol % 2 != 0 && a.size() == kol) {
    cout << "NO\n";
    return;
  }
  if (kol % 2 != 0 && a.size() > kol) {
    cout << "YES\n";
    return;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
