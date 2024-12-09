#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], l[N], r[N];
int n;
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i(1); i <= (n); ++i) scanf("%d", a + i);
  a[0] = a[n + 1] = -1;
  for (int i(1); i <= (n); ++i) {
    l[i] = i - 1;
    while ((a[i] | a[l[i]]) == a[i]) l[i] = l[l[i]];
  }
  for (int i(n); i >= (1); --i) {
    r[i] = i + 1;
    while ((a[i] | a[r[i]]) == a[i] && a[r[i]] < a[i]) r[i] = r[r[i]];
  }
  ans = 1ll * n * (n + 1) / 2;
  for (int i(1); i <= (n); ++i) ans -= 1ll * (i - l[i]) * (r[i] - i);
  printf("%lld\n", ans);
  return 0;
}
