#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int g[2] = {23, 37};
char s[maxn][maxn];
long long pw[maxn];
int n;
int cas;
bool equal(long long a, long long b) {
  for (int i = 0; i < n; i++, a /= 10, b /= 10)
    if (s[i][a % 10] != s[i][b % 10]) return 0;
  return 1;
}
long long calc(int bit, long long a, long long b) {
  if (a > b) swap(a, b);
  long long ans = pw[n] - b;
  if (!equal(a, b)) return 0;
  for (int i = bit; i < n; i++) {
    long long cur = b / (pw[i]) * pw[i];
    long long jump = pw[i];
    for (int j = 1; j < 10; j++) {
      cur += jump;
      long long step = cur - b;
      if (step >= ans) break;
      long long ano = a + step;
      if (!equal(ano, cur)) {
        ans = min(ans, step);
        break;
      }
    }
  }
  return ans;
}
void work() {
  ++cas;
  static char st[maxn];
  scanf("%d", &n);
  scanf("%s", st);
  reverse(st, st + n);
  long long v = 0, up = 1;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 10;
  for (int i = 0; i < n; i++) v = v + (st[i] - 48) * pw[i];
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      if (j != st[i] - 48)
        ans = max(ans, calc(i, v, v - (st[i] - 48) * pw[i] + j * pw[i]));
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  for (; t; t--) work();
  return 0;
}
