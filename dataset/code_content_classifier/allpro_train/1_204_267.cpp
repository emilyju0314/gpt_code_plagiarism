#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  long long cnt = 0;
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else
      cnt--;
    if (cnt < 0) {
      cout << -1;
      return 0;
    }
  }
  if (cnt < 0) {
    cout << -1;
    return 0;
  }
  long long val = cnt;
  long long cnt2 = cnt;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '#') {
      long long k = min(cnt2, val);
      ans.push_back(k + 1);
      val -= k;
    } else if (s[i] == ')')
      cnt2++;
  }
  long long x = 0;
  string res = "";
  reverse(ans.begin(), ans.end());
  for (long long i = 0; i < n; i++) {
    if (s[i] == '#') {
      res = res + string(ans[x], ')');
      x++;
    } else
      res += s[i];
  }
  cnt = 0;
  for (long long i = 0; i < res.size(); i++) {
    if (res[i] == ')')
      cnt--;
    else
      cnt++;
    if (cnt < 0) {
      cout << -1 << "\n";
      return 0;
    }
  }
  if (cnt != 0) {
    cout << -1;
    return 0;
  }
  for (auto i : ans) cout << i << "\n";
}
