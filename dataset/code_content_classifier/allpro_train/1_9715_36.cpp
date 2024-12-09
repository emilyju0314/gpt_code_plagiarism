#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> last[400010];
int n, S, a[400010], f[400010][21], g[400010], m, k;
void fw(int x) {
  if (x >= 10) fw(x / 10);
  putchar(char(x % 10 + 48));
}
int getsum(int l, int r) {
  int sum = 0;
  for (int i = l; i <= r; i++) sum += a[i];
  return sum;
}
void print(int l, int r) {
  fw(l - n * (l > n) - 1), putchar(' ');
  if (r - l + 1 <= k - 1) {
    for (int i = l; i <= r; i++) fw(a[i] + S), putchar(' ');
    for (int i = r + 1; i <= l + k - 1; i++) fw(a[i - n] + S), putchar(' ');
  } else
    for (int i = l; i <= r; i++) fw(a[i] + S), putchar(' ');
  puts("");
}
void work(int l, int r, int must = 0) {
  if (l == r) return;
  int flag = 1, hh = 0, to = min(r, l + k - 1);
  if (to == r) {
    int sum = getsum(l, r);
    a[l] = sum;
    for (int i = l + 1; i <= r; i++) a[i] = 0;
    print(l, r);
    return;
  }
  if ((hh = getsum(l, to - 1) + must) < 0) work(to, r, hh), flag = 0;
  int sum = getsum(l, to);
  a[l] = -must;
  for (int i = l + 1; i < to; i++) a[i] = 0;
  a[to] = sum + must;
  print(l, to);
  if (flag) work(to, r);
}
int sum[400010];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), S += a[i];
  S /= n;
  for (int i = 1; i <= n; i++) a[i] -= S;
  for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
  m = 2 * n;
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= m; i++) {
    f[i][0] = last[(i - 1) % (k - 1)][sum[i]];
    last[i % (k - 1)][sum[i]] = i;
    if (f[i][0]) g[i] = g[f[i][0]] + (i - f[i][0] - 1) / (k - 1);
    for (int j = 1; j <= 20; j++) f[i][j] = f[f[i][j - 1]][j - 1];
  }
  int ans = 1e9, pos = 0;
  for (int i = n + 1; i <= m; i++) {
    int now = i;
    for (int j = 20; j >= 0; j--)
      if (f[now][j] >= i - n) now = f[now][j];
    int len = now - (i - n), tmp = g[i] - g[now];
    if (!len) {
    } else if (len - 1 <= k - 1) {
      tmp++;
    } else
      tmp += (len - 2) / (k - 1) + 1;
    if (tmp < ans) ans = tmp, pos = i;
  }
  cout << ans << endl;
  for (int i = pos; i > pos - n; i = f[i][0]) {
    work(max(pos - n + 1, f[i][0] + 1), i);
  }
}
