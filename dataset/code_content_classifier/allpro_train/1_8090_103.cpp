#include <bits/stdc++.h>
using namespace std;
int hang[1005], hnum[1005];
int p;
int power(int x, int y) {
  if (y == 0) return 1;
  int t = power(x, y / 2);
  t = (long long)t * t % p;
  if (y % 2 == 1) t = (long long)t * x % p;
  return t;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n % 2 != m % 2) {
    printf("0\n");
    return 0;
  }
  int i;
  int k;
  for (i = 0; i <= 1000; i++) {
    hang[i] = min(n, m);
    hnum[i] = 1;
  }
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (n < m) swap(x, y);
    hnum[x] *= z;
    hang[x]--;
  }
  scanf("%d", &p);
  if (n < m) swap(n, m);
  int ans = 1;
  int f = 0;
  for (i = 1; i <= n; i++) {
    if ((f == 0) && (hang[i] == m)) {
      f = 1;
      continue;
    }
    if ((hang[i] == 0) && (hnum[i] == 1))
      ans = 0;
    else if (hang[i] != 0)
      ans = (long long)ans * power(2, hang[i] - 1) % p;
  }
  printf("%d\n", ans);
  return 0;
}
