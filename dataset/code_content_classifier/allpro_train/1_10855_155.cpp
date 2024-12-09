#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int l, r, p, a[3000000], f[3000000], tot, cnt, P[1000];
bool b[3000000];
void px(long long s, long long k) {
  if (s > r) return;
  if (k > cnt) {
    a[++tot] = s;
    return;
  }
  px(s * P[k], k);
  px(s, k + 1);
}
int main() {
  scanf("%d%d%d", &l, &r, &p);
  for (int i = 2; i < p; i++) {
    bool sb = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0) {
        sb = 0;
        break;
      }
    if (sb) P[++cnt] = i;
  }
  px(1, 1);
  sort(a + 1, a + tot + 1);
  memset(b, 1, sizeof(b));
  int ans = 0;
  memset(f, 125, sizeof(f));
  for (int i = 2; i < p; i++) {
    f[1] = 0;
    int k = 1;
    for (int j = 2; j <= tot; j++)
      if (!(a[j] % i)) {
        while ((a[k] * i) ^ a[j]) k++;
        if (f[k] + 1 < f[j]) f[j] = f[k] + 1;
        if (i + f[j] <= p) b[j] = 0;
      }
  }
  for (int i = 1; i <= tot; i++)
    if ((!b[i]) && a[i] >= l) ans++;
  printf("%d", ans);
  return 0;
}
