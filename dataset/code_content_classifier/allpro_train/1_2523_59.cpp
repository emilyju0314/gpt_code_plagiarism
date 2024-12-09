#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 * 1500 + 1, mod = 1e9 + 7;
int d[maxn], ans, sum[maxn];
int a[3005], ch[maxn][2], f[maxn], cur[3005], sz, flag;
void add(int& x, int y) { x = (1ll * x + y) % mod; }
int check(int k) {
  int x = 0;
  for (int i = 0; i < 4; i++) x = x * 2 + a[i + k];
  if (x == 3 || x == 5 || x == 14 || x == 15) return 0;
  return 1;
}
void up(int o, int j, int x) {
  if (ch[o][x]) {
    cur[j] = ch[o][x];
    return;
  }
  ch[o][x] = ++sz;
  f[sz] = o;
  for (int i = 1; i <= 4; i++) {
    if (i == 4 && !flag) break;
    add(d[sz], d[o]);
    o = f[o];
    if (o == -1) break;
  }
  add(ans, d[sz]);
  cur[j] = sz;
}
int main() {
  int n, x;
  cin >> n;
  d[0] = 1;
  f[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    flag = 1;
    if (i >= 4 && !check(i - 3)) flag = 0;
    for (int j = 0; j < i; j++) up(cur[j], j, a[i]);
    sum[i] = ans;
  }
  for (int i = 1; i <= n; i++) printf("%d\n", sum[i]);
}
