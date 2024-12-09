#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
void solve() {
  string s;
  cin >> s;
  long long ans = 0;
  char r = 'a';
  for (int i = 0; i < s.size(); ++i) {
    ans += min(abs(s[i] - r), 26 - (abs(s[i] - r)));
    r = s[i];
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  bool IS_ONE_TEST = 1;
  if (IS_ONE_TEST)
    t = 1;
  else
    cin >> t;
  while (t-- > 0) {
    solve();
  }
}
