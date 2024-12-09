#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  long long mx = 0, mn = INT_MAX, sm = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    sm += a[i];
    mx = max(sm, mx);
    mn = min(mn, sm);
    if (sm > 0 && sm > m) {
      cout << 0;
      return 0;
    }
  }
  if (mn < 0)
    mn = -mn;
  else
    mn = 0;
  if (mx <= 0)
    mx = m;
  else
    mx = m - mx;
  if (mn > mx)
    cout << 0;
  else
    cout << mx - mn + 1;
  return 0;
}
