#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<bool> pref(n), suff(n);
  for (int i = 0; i < n; i++) {
    pref[i] = true;
    if (i) pref[i] = pref[i - 1] & (s[i] == s[i - 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = true;
    if (i + 1 < n) suff[i] = suff[i + 1] & (s[i] == s[i + 1]);
  }
  bool chance_for_quailty = true;
  for (int i = 0; i + k <= n; i++) {
    if ((i == 0 or pref[i - 1]) and (i + k == n or suff[i + k]) and
        (s.front() == s.back() or i == 0 or i + k == n)) {
      return cout << "tokitsukaze", 0;
    }
    if (i == 0 or pref[i - 1] or i < k or pref[i - k]) {
      int cntL = (i > 0 and !pref[i - 1]);
      bool debug = i == 2;
      if (debug)
        cerr << "i = " << i << ", pref[i - 1] = " << pref[i - 1]
             << " -> cntL = " << cntL << "\n";
      if (cntL) {
        if ((s.back() == s.front() or i + k == n) and
            (i + k == n or suff[i + k])) {
        } else
          chance_for_quailty = false;
      } else {
        if (i + k == n or suff[i + k] or i + k + k >= n or
            (suff[i + k + k] and s.back() == s.front())) {
        } else
          chance_for_quailty = false;
      }
    }
  }
  if (chance_for_quailty)
    cout << "quailty";
  else
    cout << "once again";
}
