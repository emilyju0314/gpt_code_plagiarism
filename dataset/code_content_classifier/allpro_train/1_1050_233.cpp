#include <bits/stdc++.h>
using namespace std;
int r, l, pri[20000005], cnt, tot;
bitset<300000005> flag;
inline void make_prime_list(register int n) {
  for (register int i = 2; i <= n; ++i) {
    if (!flag[i]) pri[++cnt] = i;
    for (register int j = 1; j <= cnt && i * pri[j] <= n; ++j) {
      flag[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
int main() {
  scanf("%d%d", &l, &r);
  if (l <= 2 && r >= 2) ++tot;
  make_prime_list(r);
  for (register int i = 1; i <= cnt; ++i) {
    if (pri[i] < l) continue;
    if (pri[i] % 4 == 1) ++tot;
  }
  printf("%d", tot);
}
