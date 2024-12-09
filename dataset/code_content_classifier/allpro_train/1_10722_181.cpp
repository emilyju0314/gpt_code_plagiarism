#include <bits/stdc++.h>

const int N = 200000 + 10;

int n, a[N];
int b[N];

int check(int m) {
  for (int i = 1; i < 2 * n; ++i) b[i] = (a[i] >= m);
  for (int i = 0; i < n - 1; ++i) {
    if (b[n - i - 1] == b[n - i]) return b[n - i];
    if (b[n + i] == b[n + i + 1]) return b[n + i];
  }
  return b[n] ^ (n & 1) ^ 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < 2 * n; ++i) scanf("%d", &a[i]);
  int l = 1, r = 2 * n - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
