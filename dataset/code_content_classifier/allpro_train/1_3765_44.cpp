#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &a, const vector<long long> &b) {
  for (auto k : b) cout << k << " ";
  return a;
}
const long long INF = 1e18;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  long long cnt = 0;
  long long bal = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '(')
      bal++;
    else if (s[i] == ')')
      bal--;
    else
      cnt++;
    if (cnt > bal || bal < 0) {
      cout << -1;
      return 0;
    }
  }
  vector<long long> ans(cnt);
  for (long long i = 0; i < cnt - 1; i++) ans[i] = 1;
  ans[cnt - 1] = bal - cnt + 1;
  bal = 0;
  long long ind = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '(')
      bal++;
    else if (s[i] == ')')
      bal--;
    else
      bal -= ans[ind++];
    if (bal < 0) {
      cout << -1;
      return 0;
    }
  }
  if (bal != 0) {
    cout << -1;
    return 0;
  }
  for (auto k : ans) cout << k << "\n";
}
