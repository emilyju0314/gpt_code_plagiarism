#include <bits/stdc++.h>
using namespace std;
int n, d, a[100010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> d;
  int s1 = 0, s2 = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (!a[i]) {
      s1 = max(s1, 0);
      if (s2 < 0) s2 = d, ++ans;
    } else {
      s1 += a[i];
      if (s1 > d) return cout << "-1\n", 0;
      s2 = min(s2 + a[i], d);
    }
  }
  cout << ans << "\n";
  return 0;
}
