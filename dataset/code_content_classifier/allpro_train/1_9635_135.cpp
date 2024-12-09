#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(n);
    vector<int> r(n);
    int cur = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        cur = i;
      }
      l[i] = cur;
    }
    cur = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') cur = i;
      r[i] = cur;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        i += k;
        continue;
      }
      if (r[i] > (i + k) || r[i] == -1) {
        s[i] = '1';
        i += k;
        ans++;
      }
      if (i >= n) break;
    }
    cout << ans << endl;
  }
  return 0;
}
