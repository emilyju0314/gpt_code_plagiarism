#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n, k, ans = -1e9, r = 1e9;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int e = k - 1;
    r = min(r, a[i]);
    int q = i, w = n - 1 - i;
    e -= (bool)q;
    e -= (bool)w;
    e = e;
    if (w + q >= e && e >= 0) ans = max(ans, a[i]);
  }
  if (ans != -1e9)
    cout << ans;
  else
    cout << r;
}
