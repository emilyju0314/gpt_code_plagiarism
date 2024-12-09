#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 100;
const int maxn = 1e6;
const int MAXL = sqrt(1e9);
int T, n;
int a[1100], x;
void solve() {
  scanf("%d", &n);
  int last = 0;
  for (int i = 1; i <= n - 1; i++) {
    printf("? %d %d\n", i, n);
    fflush(stdout);
    scanf("%d", &x);
    if (i != 1) a[i - 1] = last - x;
    last = x;
  }
  int res = 0;
  for (int i = 1; i <= n - 2; i++) res += a[i];
  printf("? %d %d\n", 1, n - 1);
  fflush(stdout);
  scanf("%d", &x);
  a[n - 1] = x - res;
  a[n] = last - a[n - 1];
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  fflush(stdout);
}
int main() {
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
