#include <bits/stdc++.h>
int n, m, dx, dy, i, d, max, ans;
int x[100000], y[100000];
int memo[1000000];
int main(void) {
  scanf("%d %d %d %d", &n, &m, &dx, &dy);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  if (n > 1) {
    i = 1;
    while ((long long)dx * i % n != 1) {
      i++;
    }
    d = (int)(((long long)dy * i) % n);
  } else {
    d = 0;
  }
  for (i = 0; i < n; i++) {
    memo[i] = 0;
  }
  for (i = 0; i < m; i++) {
    memo[(int)(((y[i] - (long long)d * x[i]) % n + n) % n)]++;
  }
  max = 0;
  for (i = 0; i < n; i++) {
    if (max < memo[i]) {
      max = memo[i];
      ans = i;
    }
  }
  printf("0 %d\n", ans);
}
