#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int a[N + 5], ans;
double fac[20005];
double POI(int P) {
  double ans = 0;
  double v = log(P);
  for (int i = (int)(1); i <= (int)(N); i++)
    if (a[i] < 0)
      return -1e300;
    else
      ans += v * a[i] - P - fac[a[i]];
  return ans;
}
double UNI(int P) {
  double ans = 0;
  double v = log(2 * P + 1);
  for (int i = (int)(1); i <= (int)(N); i++)
    if (a[i] < 0 || a[i] > 2 * P)
      return -1e300;
    else
      ans -= v;
  return ans;
}
void solve() {
  double pos = -1e300;
  for (int i = (int)(1); i <= (int)(N); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(1000); i++) {
    for (int j = (int)(1); j <= (int)(N); j++) ++a[j];
    double v1 = POI(i), v2 = UNI(i);
    if (v1 > pos) pos = v1, ans = 0;
    if (v2 > pos) pos = v2, ans = 1;
  }
  puts(ans ? "uniform" : "poisson");
}
int main() {
  for (int i = (int)(1); i <= (int)(10000); i++) fac[i] = fac[i - 1] + log(i);
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
