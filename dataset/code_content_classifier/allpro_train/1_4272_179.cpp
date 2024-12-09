#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  string k, g;
  int p = s1.length();
  int ans = 0;
  for (int i = 0; i <= (p / 2); i++) {
    k += s1.at(i);
    g = k;
    if (i == p / 2) {
      g = s1;
    }
    p = s1.length();
    int q, r;
    q = g.length();
    r = s2.length();
    if (r % q == 0 && p % q == 0) {
      bool f = 0;
      int t = 0;
      for (int i = 0; i < (p / q); i++) {
        for (int j = 0; j < q; j++) {
          if (s1.at(j + t) != g.at(j)) {
            f = 1;
          }
        }
        t += q;
        if (f) break;
      }
      t = 0;
      if (!f) {
        for (int i = 0; i < (r / q); i++) {
          for (int j = 0; j < q; j++) {
            if (s2.at(j + t) != g.at(j)) {
              f = 1;
            }
          }
          t += q;
          if (f) break;
        }
      }
      if (!f) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
