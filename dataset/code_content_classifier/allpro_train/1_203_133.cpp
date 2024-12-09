#include <bits/stdc++.h>
using namespace std;
long long n, z[1 << 20], p[1000005], ans, a;
int main(void) {
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a);
    z[a]++;
  }
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2LL % 1000000007;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 1 << 20; j++)
      if (!(j >> i & 1)) z[j] += z[j | (1 << i)];
  for (int i = 0; i < 1 << 20; i++) {
    a = 0;
    for (int j = 0; j < 20; j++)
      if (i >> j & 1) a++;
    if (a % 2)
      ans = (ans + 1000000007 - p[z[i]]) % 1000000007;
    else
      ans = (ans + p[z[i]]) % 1000000007;
  }
  printf("%I64d\n", ans);
}
