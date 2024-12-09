#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[20010];
string s;
int ct, id[20010];
int main() {
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) s[j] -= '0';
    int hh = 10 * s[0] + s[1];
    int mm = 10 * s[3] + s[4];
    int ss = 10 * s[6] + s[7];
    a[i] = 3600 * hh + 60 * mm + ss;
  }
  int cur = 0, mx = 0;
  for (int l = 0, r = 0; r < n; r++) {
    while (a[l] + t <= a[r]) {
      if (id[l] != id[l + 1]) cur--;
      l++;
    }
    if (cur < m) {
      id[r] = ++ct;
      cur++;
    } else {
      id[r] = ct;
    }
    mx = max(mx, cur);
  }
  if (mx != m) {
    cout << "No solution\n";
    return 0;
  }
  cout << ct << '\n';
  for (int i = 0; i < n; i++) cout << id[i] << '\n';
}
