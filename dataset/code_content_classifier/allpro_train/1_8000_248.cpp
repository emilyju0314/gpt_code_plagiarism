#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  while (cin >> s) {
    int d = 0;
    int cnt = 0;
    int ans = 0;
    if (s[0] == 'F') ++cnt;
    for (int i = 1; i < (int)s.size(); ++i) {
      if (s[i - 1] == 'F' && i != cnt) ++d;
      if (s[i] == 'F') {
        d = max(0, d);
        ans = max(ans, i - cnt + d);
        d = max(d, 0);
        ++cnt;
      } else
        --d;
    }
    cout << ans << endl;
  }
  return 0;
}
