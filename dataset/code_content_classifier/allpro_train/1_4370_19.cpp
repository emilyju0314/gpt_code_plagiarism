#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, lb, ans, a[maxn];
inline int input() {
  int ans = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) {
    ans = (ans << 3) + (ans << 1) + (ch - '0');
  }
  return ans;
}
int main() {
  n = input();
  ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = input();
  }
  sort(a + 1, a + n + 1);
  for (int j = n; j >= 1; j--) {
    if (ans > a[j]) {
      break;
    }
    if (a[j] == 1 || a[j] == a[j + 1]) {
      continue;
    }
    lb = 1;
    for (int k = a[j]; k <= a[n] + a[j]; k += a[j]) {
      lb = lower_bound(a + lb, a + n + 1, k + a[j]) - a;
      ans = max(ans, a[lb - 1] % a[j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
