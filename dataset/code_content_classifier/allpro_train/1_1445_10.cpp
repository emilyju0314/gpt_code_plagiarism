#include <bits/stdc++.h>
using namespace std;
int n, a[2000005], x, y, B[2000005];
long long c[2000005], S[2000005], ans = (1LL << 60), sum;
int main() {
  int i, j, p;
  scanf("%d %d %d", &n, &x, &y);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), c[a[i]]++, S[a[i]] += a[i];
  for (i = 1; i < 2000005; i++) c[i] += c[i - 1], S[i] += S[i - 1];
  for (i = 2; i < 2000005; i++) {
    if (B[i]) continue;
    for (j = i + i; j < 2000005; j += i) B[j] = 1;
    p = min(x / y + 1, i), sum = 0;
    for (j = i; j < 2000005; j += i)
      sum += ((c[j] - c[j - p]) * j - S[j] + S[j - p]) * y +
             (c[j - p] - c[j - i]) * x;
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}
