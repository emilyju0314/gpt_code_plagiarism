#include <bits/stdc++.h>
long long pre[555][555];
int n;
void init() {
  memset(pre, 0, sizeof(pre));
  pre[1][0] = 1;
  pre[1][1] = 1;
  pre[2][0] = 2;
  pre[2][1] = 2;
  pre[2][2] = 2;
  pre[3][0] = 4;
  pre[3][1] = 6;
  pre[3][2] = 6;
  pre[3][3] = 6;
}
int main() {
  int i, two, a, j;
  scanf("%d", &n);
  for (i = two = 0; i < n; i++) scanf("%d", &a), two += a == 2;
  init();
  for (i = 4; i <= n; i++)
    pre[i][0] = (pre[i - 1][0] + (i - 1LL) * pre[i - 2][0]) % 1000000007;
  for (i = 4; i <= n; i++)
    for (j = 1; j <= i; j++) pre[i][j] = (pre[i - 1][j - 1] * i) % 1000000007;
  printf("%I64d\n", pre[n][two]);
  return 0;
}
