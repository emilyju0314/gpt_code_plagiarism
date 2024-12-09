#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 + 10;
int d[maxn][5];
int bad[26][4];
int n, k;
string s, help;
vector<string> v;
int ans = 0;
int main() {
  cin >> s;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> help;
    v.push_back(help);
  }
  n = s.size();
  memset(d, -1, sizeof d);
  int t1 = 0, t2 = 0;
  char cur = 'A';
  char bad = 'B';
  for (int i = 0; i < n; ++i) {
    if (s[i] == cur)
      t1++;
    else if (s[i] == bad)
      t2++;
    else if (cur == 'A') {
      cur = s[i];
      t1++;
    } else if (bad == 'B') {
      cerr << cur << "::" << i << endl;
      bool qw = false;
      for (int j = 0; j < k; ++j)
        if ((cur == v[j][0] && s[i] == v[j][1]) ||
            (cur == v[j][1] && s[i] == v[j][0])) {
          bad = s[i];
          t2 = 1;
          qw = true;
        }
      if (qw == false) {
        t1 = 1;
        cur = s[i];
      }
    } else {
      if (s[i] == cur)
        t1++;
      else if (s[i] == bad)
        t2++;
      else {
        ans += min(t1, t2);
        cur = s[i];
        t1 = 1;
        bad = 'B';
      }
    }
  }
  if (cur != 'A' && bad != 'B') ans += min(t1, t2);
  cout << ans << endl;
}
