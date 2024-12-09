#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, m, len;
  cin >> n >> m;
  if (n >= 1 && n <= 100 && m >= 1 && m <= 100) {
    cin >> s;
    len = s.size();
    if (len == n) {
      int l, r, z;
      char c1, c2;
      while (m--) {
        cin >> l >> r >> c1 >> c2;
        if (l >= 1 && l <= r && r <= n && c1 >= 'a' && c1 <= 'z' && c2 >= 'a' &&
            c2 <= 'z')
          for (z = l - 1; z <= r - 1; z++) {
            if (s[z] == c1) {
              s[z] = c2;
            }
          }
      }
      cout << s << endl;
    }
  }
}
