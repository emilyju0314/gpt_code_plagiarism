#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m, ans;
string s;
int main() {
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i <= n - 2; ++i)
    if (s[i] == '.' && s[i + 1] == '.') ans++;
  for (int i = 1; i <= m; ++i) {
    int p;
    string t;
    cin >> p >> t;
    p--;
    if (s[p] == '.') {
      if (t[0] != '.') {
        if (p > 0) {
          if (s[p - 1] == '.') ans--;
        }
        if (p < n - 1) {
          if (s[p + 1] == '.') ans--;
        }
      }
    } else {
      if (t[0] == '.') {
        if (p > 0) {
          if (s[p - 1] == '.') ans++;
        }
        if (p < n - 1) {
          if (s[p + 1] == '.') ans++;
        }
      }
    }
    s[p] = t[0];
    cout << ans << endl;
  }
  return 0;
}
