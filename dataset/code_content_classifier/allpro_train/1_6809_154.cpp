#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x7f7f7f7f;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int a[N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i < (n + 1); i++) scanf("%d", &a[i]);
  if (~n & 1) return !printf("0\n");
  int t = m / (n / 2 + 1);
  int ans = inf;
  for (int i = (1); i < (n + 1); i++) {
    if (i & 1)
      ans = min((long long)ans, min((long long)k * t, (long long)a[i]));
  }
  printf("%d\n", ans);
  return 0;
}
