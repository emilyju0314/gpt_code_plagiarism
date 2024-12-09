#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long s[maxn];
int vis[maxn];
int main() {
  int n, d, b;
  scanf("%d%d%d", &n, &d, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &s[i]);
    s[i] += s[i - 1];
  }
  int x1 = 0, x2 = 0;
  int cntl = 0, cntr = 0;
  int tmp = 0;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    tmp += (d + 1);
    if (tmp > n) tmp = n;
    if (s[tmp] >= 1LL * (cntl + 1) * 1LL * b)
      cntl++;
    else
      x1++;
    if (s[n] - s[n - tmp] >= 1LL * (cntr + 1) * 1LL * b)
      cntr++;
    else
      x2++;
  }
  printf("%d\n", max(x1, x2));
  return 0;
}
