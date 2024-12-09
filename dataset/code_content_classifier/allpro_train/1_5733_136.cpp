#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int p = 1000000007;
int lowbit(int x) { return x & (-x); }
int fast_power(int a, int b) {
  int x;
  for (x = 1; b; b >>= 1) {
    if (b & 1) x = 1ll * x * a % p;
    a = 1ll * a * a % p;
  }
  return x % p;
}
char st[105];
int a[105];
bool cmp(int a, int b) { return a > b; }
int main() {
  int t;
  scanf("%d", &t);
  for (int times = 1; times <= t; times++) {
    scanf("%s", st);
    int len = strlen(st), m = 0;
    for (int i = 0; i <= len - 1; i++) {
      if (st[i] == '0') continue;
      if (!i || st[i] != st[i - 1])
        a[++m] = 1;
      else
        a[m]++;
    }
    sort(a + 1, a + m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i += 2) ans += a[i];
    printf("%d\n", ans);
  }
  return 0;
}
