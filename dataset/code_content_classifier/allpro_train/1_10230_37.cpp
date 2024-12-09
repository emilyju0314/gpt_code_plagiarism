#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  vector<long long> v(n, -1);
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < n; j++) {
      if ((i + 2 * j) >= n)
        break;
      else {
        if ((s[i] == s[i + j]) && (s[i + j] == s[i + j + j])) {
          v[i] = i + 2 * j;
          break;
        }
      }
    }
  }
  long long mi = -1;
  for (long long i = n - 2; i >= 0; i--) {
    if (v[i] == -1)
      v[i] = mi;
    else {
      if (mi == -1)
        mi = v[i];
      else {
        mi = min(mi, v[i]);
        v[i] = mi;
      }
    }
  }
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i] == -1) continue;
    res += (n - v[i]);
  }
  cout << res;
}
