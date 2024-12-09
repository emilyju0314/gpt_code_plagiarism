#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 1;
  for (int i = 1; i <= n + m; i++) ans = (ans << 1) % 998244353;
  printf("%d\n", ans);
  return 0;
}
