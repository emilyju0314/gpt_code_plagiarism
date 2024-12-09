#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
int n;
char s[maxn], t[maxn];
long long ans, a[maxn];
void dfs(int x, int w) {
  if (s[x + 1] + w < '0' || s[x + 1] + w > '9') dfs(x + 1, -w);
  printf("%d %d\n", x, w);
  s[x] += w;
  s[x + 1] += w;
  if (!(--ans)) exit(0);
}
int main() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = -a[i - 1] + t[i] - s[i];
    ans += abs(a[i]);
  }
  if (a[n]) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", ans);
  if (!ans) return 0;
  ans = min(ans, (long long)1e5);
  for (int i = 1; i < n; i++)
    while (s[i] != t[i]) dfs(i, t[i] > s[i] ? 1 : -1);
  return 0;
}
