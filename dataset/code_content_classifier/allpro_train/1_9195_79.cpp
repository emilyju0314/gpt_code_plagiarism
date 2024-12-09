#include <bits/stdc++.h>
using namespace std;
int t;
string s;
void solve() {
  cin >> s;
  int mx = 0, indx = -1, n = s.size();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      mx = max(mx, i - indx);
      indx = i;
    }
  }
  mx = max(mx, n - indx);
  cout << mx << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
}
