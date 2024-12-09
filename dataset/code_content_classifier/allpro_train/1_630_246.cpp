#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int N = 1000010;
long long deg[N];
int main() {
  int n, m, x;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 2 * m; ++i) scanf("%d", &x), deg[x]++;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += (deg[i] * (n - deg[i] - 1));
  long long xomp =
      ((long long)(n) * (long long)(n - 1) * (long long)(n - 2)) / 6LL;
  printf("%lld\n", xomp - ans / 2);
  return 0;
}
