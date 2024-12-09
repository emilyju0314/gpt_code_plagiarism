#include <bits/stdc++.h>
using namespace std;
int ans[200200];
void doit() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int num = n, last = 0;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 || s[i] == '>') {
      for (int j = i; j >= last; j--) ans[j] = num--;
      last = i + 1;
    }
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  num = 1, last = 0;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 || s[i] == '<') {
      for (int j = i; j >= last; j--) ans[j] = num++;
      last = i + 1;
    }
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    doit();
  }
  return 0;
}
