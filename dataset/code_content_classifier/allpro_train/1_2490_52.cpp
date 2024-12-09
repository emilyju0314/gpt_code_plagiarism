#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, ans = 1e9;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = (0), sz = (int)(n); i < sz; i += (1)) cin >> a[i];
  for (int i = (0), sz = (int)(n); i < sz; i += (1)) cin >> b[i];
  for (int j = (1), sz = (int)(n); j < sz; j += (1)) {
    int mni = 1e9, mnk = 1e9;
    for (int i = (0), sz = (int)(j); i < sz; i += (1))
      if (a[i] < a[j]) mni = min(mni, b[i]);
    for (int k = (j + 1), sz = (int)(n); k < sz; k += (1))
      if (a[k] > a[j]) mnk = min(mnk, b[k]);
    if (mni != 1e9 && mnk != 1e9) ans = min(ans, b[j] + mni + mnk);
  }
  printf("%d\n", ans == 1e9 ? -1 : ans);
  return 0;
}
