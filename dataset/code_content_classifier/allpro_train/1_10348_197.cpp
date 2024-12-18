#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, l, r, m, ans[4];
bool chk(int d2) {
  ans[0] = a[0] + d2;
  int t = 0;
  ans[1] = ans[2] = 2000000000;
  for (int i = 0; i < n; i++)
    if (t >= 3)
      return false;
    else if (ans[t] < a[i])
      ans[++t] = a[i] + d2;
  return t < 3;
}
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  l = -1, r = a[n - 1] + 1;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (chk(m))
      r = m;
    else
      l = m;
  }
  chk(r);
  printf("%.7f\n%.7f %.7f %.7f", r * 0.5, ans[0] * 1.0 - 0.5 * r,
         ans[1] * 1.0 - 0.5 * r, ans[2] * 1.0 - 0.5 * r);
  return 0;
}
