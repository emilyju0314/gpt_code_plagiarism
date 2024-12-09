#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int n, m, i, j;
  cin >> n >> m;
  string s[n];
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<bool> b(n, false);
  string only = "";
  vector<pair<string, string> > ans;
  for (i = 0; i < n; i++) {
    if (b[i] == false) {
      b[i] = true;
      string x = s[i];
      reverse(x.begin(), x.end());
      for (j = i + 1; j < n; j++) {
        if (b[j] == 0 && s[j] == x) {
          ans.push_back(make_pair(s[i], x));
          b[j] = true;
          break;
        }
      }
      if (j == n) {
        if (x == s[i]) {
          only = x;
        }
      }
    }
  }
  string ans1 = "", ans2;
  for (auto x : ans) {
    ans1 += x.first;
  }
  ans2 = ans1;
  reverse(ans2.begin(), ans2.end());
  if (only != "") {
    ans1 += only;
  }
  ans1 = ans1 + ans2;
  cout << ans1.size() << '\n' << ans1;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
