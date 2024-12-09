#include <bits/stdc++.h>
using namespace std;
int n, m, c[26][200005], a[26];
int l, r, mid;
bool f;
string s, ts;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      c[j][i] += (i ? c[j][i - 1] : 0);
      if (s[i] == 'a' + j) ++c[j][i];
    }
  }
  while (m--) {
    memset(a, 0, sizeof(a));
    cin >> ts;
    for (int i = 0; i < ts.length(); ++i) ++a[ts[i] - 'a'];
    l = 0, r = n - 1;
    while (l != r) {
      mid = (l + r) / 2;
      f = true;
      for (int i = 0; i < 26; ++i)
        if (a[i] > c[i][mid]) {
          f = false;
          break;
        }
      if (!f)
        l = mid + 1;
      else
        r = mid;
    }
    cout << l + 1 << "\n";
  }
}
