#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long ans = n;
  long long res = 0;
  for (auto x : s) res += (x - '0');
  ans = res;
  for (long long i = 0; i < k; i++) {
    long long tmp = res;
    vector<bool> z;
    for (long long j = 0;; j++) {
      long long l = i + j * k;
      if (l >= n) break;
      if (s[l] == '0')
        z.push_back(false);
      else {
        z.push_back(true);
      }
    }
    vector<long long> pref(z.size() + 1, 0);
    for (long long i = 1; i <= z.size(); i++) {
      pref[i] = pref[i - 1] + (z[i - 1] == true);
    }
    long long _i = 0;
    for (long long j = 0; j < z.size(); j++) {
      if (2 * pref[j] - j < 2 * pref[_i] - _i) _i = j;
      ans = min(ans, tmp + (j - _i + 1) - (pref[j + 1] - pref[_i]) -
                         (pref[j + 1] - pref[_i]));
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
