#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s, t;
  cin >> s;
  int l, r;
  for (int i = 0; i < (int)(q); i++) {
    cin >> l >> r;
    l--, r--;
    t = s.substr(l, r - l + 1);
    int idx = 0, direction = 1, previdx = -1;
    int ans[10] = {0};
    while (true) {
      if (t[idx] == '>') {
        if (previdx != -1 && (t[previdx] == '>' || t[previdx] == '<'))
          t[previdx] = 0;
        direction = 1;
      } else if (t[idx] == '<') {
        if (previdx != -1 && (t[previdx] == '>' || t[previdx] == '<'))
          t[previdx] = 0;
        direction = 0;
      } else {
        ans[t[idx] - '0']++;
        t[idx]--;
        if (t[idx] < '0') t[idx] = 0;
      }
      previdx = idx;
      if (direction == 1) {
        for (idx++; idx < ((int)t.size()) && t[idx] == 0; idx++)
          ;
        if (idx == ((int)t.size())) break;
      } else {
        for (idx--; idx >= 0 && t[idx] == 0; idx--)
          ;
        if (idx < 0) break;
      }
    }
    for (int i = 0; i < (int)(10); i++)
      if (i == 0)
        cout << ans[i];
      else
        cout << " " << ans[i];
    cout << endl;
  }
  return 0;
}
