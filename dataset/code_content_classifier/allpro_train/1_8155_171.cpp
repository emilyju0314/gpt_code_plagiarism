#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1123456;
const int MAXINT = 2147483098;
const long long MAXLL = 9223372036854775258LL;
string s;
string answer;
string pref, suf, cur;
void solve() {
  int n;
  cin >> n >> s;
  int shift = 1;
  answer = s;
  int bad = (n % 2 == 0);
  for (int k = 2; k <= n; ++k) {
    pref = s.substr(k - 1, n - k + 1);
    suf = s.substr(0, k - 1);
    if (bad) {
      reverse(suf.begin(), suf.end());
    }
    cur = pref + suf;
    if (cur < answer) {
      answer = cur;
      shift = k;
    }
    bad = 1 - bad;
  }
  cout << answer << '\n';
  cout << shift << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
