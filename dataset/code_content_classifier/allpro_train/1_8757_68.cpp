#include <bits/stdc++.h>
using namespace std;
const string MOVES = "LRUD";
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c : MOVES) cnt[c] = 0;
    for (auto c : s) ++cnt[c];
    int y = min(cnt['U'], cnt['D']);
    int x = min(cnt['L'], cnt['R']);
    if (min(y, x) == 0) {
      if (y == 0) {
        x = min(x, 1);
        cout << 2 * x << endl << string(x, 'L') + string(x, 'R') << endl;
      } else {
        y = min(y, 1);
        cout << 2 * y << endl << string(y, 'U') + string(y, 'D') << endl;
      }
    } else {
      string res;
      res += string(x, 'L');
      res += string(y, 'U');
      res += string(x, 'R');
      res += string(y, 'D');
      cout << res.size() << endl << res << endl;
    }
  }
  return 0;
}
