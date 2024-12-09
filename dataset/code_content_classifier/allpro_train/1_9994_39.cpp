#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
int n;
int a[111111];
int main() {
  long long s = 0;
  long long mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), mx = max(mx, 1ll * a[i]), s += a[i];
  s = (s / (n - 1)) + (s % (n - 1) != 0);
  printf("%I64d\n", max(s, mx));
  return 0;
}
