#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, x;
int z[maxn];
bool check(int xx) {
  for (int i = 0; i < xx; ++i)
    if (z[n - xx + i] - z[i] < x) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; ++i) scanf("%d", z + i);
  sort(z, z + n);
  int l = 0, r = n / 2;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}
