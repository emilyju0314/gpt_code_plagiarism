#include <bits/stdc++.h>
using namespace std;
const int N = 1000004, P = 1000000007;
int n, m, k, num = 0, base[N];
bool e[N];
void error() {
  printf("0\n");
  exit(0);
}
int main() {
  int i;
  scanf("%d%d%d", &n, &m, &k);
  for (base[0] = 1, i = 1; i <= n; i++) base[i] = base[i - 1] * 2 % P, e[i] = 0;
  for (i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if ((v != u + 1) && (v != u + k + 1)) error();
    if (v == u + k + 1) e[u] = 1, num++;
  }
  int now = 0, j = 1, ans = 0;
  if (!num) ans++;
  for (i = 1; i <= n - k - 1; i++) {
    while ((j <= i + k) && (j <= n - k - 1)) now += e[j++];
    if (i > 1) now -= e[i - 1];
    if (now == num) ans = (ans + base[j - i - now - 1 + e[i]]) % P;
  }
  printf("%d\n", ans);
  return 0;
}
