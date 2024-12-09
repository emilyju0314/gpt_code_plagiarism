#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (int)(n); i++) cin >> v[i];
  int ans = 0, ans_i = 0;
  auto go = [&](int m, int i) {
    if (m) {
      int cnt = 0, prev = v[i++];
      for (; i < n; i++, cnt++) {
        if (v[i] <= prev)
          prev = v[i];
        else
          break;
      }
      return cnt;
    } else {
      int cnt = 0, prev = v[i--];
      for (; i >= 0; i--, cnt++) {
        if (v[i] <= prev)
          prev = v[i];
        else
          break;
      }
      return cnt;
    }
  };
  for (int i = 0; i < (int)(n); i++) {
    int r = go(1, i) + go(0, i) + 1;
    if (r > ans) ans_i = i, ans = r;
  }
  cout << ans << '\n';
}
