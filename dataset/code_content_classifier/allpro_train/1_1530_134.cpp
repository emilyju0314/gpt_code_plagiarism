#include <bits/stdc++.h>
using namespace std;
const long long N = 303, NUM = 10, BIG = 1e9, MOD = 1e9 + 7, R = 4;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  set<char> a;
  int ans = 0;
  for (int i = 0; i < s.size(); ++i)
    if ('A' <= s[i] && s[i] <= 'Z')
      a.clear();
    else {
      a.insert(s[i]);
      ans = max(ans, (int)a.size());
    }
  cout << ans;
  return 0;
}
