#include <bits/stdc++.h>
const int N = 1000 + 10;
int n, m;
long long ans;
char s[N][N], t[N][N];
int pos[N];
void writediv(long long a, long long b) {
  int i;
  printf("%lld.", a / b);
  a %= b;
  for (i = 0; i < 12; i++) {
    a *= 10;
    printf("%lld", a / b);
    a %= b;
  }
  putchar('\n');
}
void solve() {
  int i, j;
  int sum0;
  long long sum1;
  sum0 = sum1 = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (s[i][j] == '.') {
        ans += 2 * (1LL * sum0 * i - sum1);
        sum0++;
        sum1 += i;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    pos[i] = 0;
    for (j = 1; j <= m; j++)
      if (s[i][j] == 'X') {
        pos[i] = j;
        break;
      }
  }
  for (i = 1; i <= n; i++) {
    if (pos[i]) {
      ans += 4LL * (pos[i] - 1) * (m - pos[i]);
      for (j = i + 1; j <= n and pos[j] > pos[j - 1]; j++)
        ans += 4LL * (pos[i] - 1) * (m - pos[j]);
      for (j = i + 1; j <= n and pos[j] and pos[j] < pos[j - 1]; j++)
        ans += 4LL * (pos[j] - 1) * (m - pos[i]);
    }
  }
}
int main() {
  int i, j;
  long long cnt = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (j = 1; j <= m; j++) {
      t[j][i] = s[i][j];
      cnt += (s[i][j] == '.');
    }
  }
  cnt = cnt * cnt;
  solve();
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) t[j][i] = s[i][j];
  memcpy(s, t, sizeof(t));
  std::swap(n, m);
  solve();
  writediv(ans, cnt);
  return 0;
}
