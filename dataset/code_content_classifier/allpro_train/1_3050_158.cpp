#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[n + 4];
  int c1 = 0;
  int c2 = 0;
  for (int i = 0; i < n; i++) {
    a[i] = s[i];
    if (s[i] == '<') {
      c1++;
    }
    if (s[i] == '>') {
      c2++;
    }
  }
  a[n] = s[0];
  bool cyc = false;
  if (c1 == 0 || c2 == 0) {
    cyc = true;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == 45 || a[i] == 45) {
      ans++;
      continue;
    }
    if (a[i - 1] == a[i]) {
      ans += cyc;
    }
  }
  cout << ans << endl;
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
