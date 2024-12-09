#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
const int mod = (int)1e9 + 7;
using namespace std;
void solve() {
  string b;
  cin >> b;
  string check = "CODEFORCES";
  if ((int)b.size() < (int)check.size()) {
    cout << "NO" << '\n';
    return;
  }
  if (b.substr(0, 10) == check || b.substr((int)b.size() - 10, 10) == check) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = (1); i < (10); i++) {
    if (b.substr(0, i) == check.substr(0, i) &&
        b.substr((int)b.size() - (10 - i), 10 - i) == check.substr(i, 10 - i)) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
