#include <bits/stdc++.h>
using namespace std;
int n, a[30];
bool f[24][(1 << 23) + 10];
int bits[(1 << 23) + 10];
int main() {
  bits[0] = 0;
  for (int i = 1; i < (1 << 23); i++) bits[i] = bits[i >> 1] + (i & 1);
  while (scanf("%d", &n) != EOF) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    f[0][1] = 1;
    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < (1 << (i + 1)); j++)
        if (f[i][j]) {
          for (int p = 0; p <= i; p++)
            if (j & (1 << p)) {
              for (int q = p; q <= i; q++)
                if ((j & (1 << q)) && (a[p] + a[q] == a[i + 1])) {
                  for (int k = 0; k <= i; k++)
                    if (j & (1 << k))
                      f[i + 1][(1 << (i + 1)) | (j ^ (1 << k))] = 1;
                  f[i + 1][j | (1 << (i + 1))] = 1;
                }
            }
        }
    int ans = 0x7fffffff;
    for (int j = 0; j < (1 << n); j++)
      if (f[n - 1][j]) ans = min(ans, bits[j]);
    if (ans == 0x7fffffff)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
