#include <bits/stdc++.h>
using namespace std;
int n, p, m;
int d[200005], t[200005];
int ans;
int main() {
  scanf("%d%d%d", &n, &p, &m);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d%d", &d[i], &t[i]);
  }
  d[0] = 1;
  d[n + 1] = m + 1;
  long long prv = 0;
  for (int i = 1; i < n + 2; i++) {
    long long cur = prv - (d[i] - d[i - 1]) * (long long)p;
    int neg = min((long long)d[i] - d[i - 1], (-cur - 1) / p + 1);
    if (cur >= 0) neg = 0;
    ans += neg;
    cur += t[i];
    prv = cur;
  }
  printf("%d\n", ans);
  return 0;
}
