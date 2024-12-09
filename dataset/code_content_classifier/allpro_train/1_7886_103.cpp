#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
const int N = 105;
long long inv[N], n, ans[N][N], nex[N];
long long p[N], pc[N][N], sum;
int cnt, K;
int c[N], cc[N];
void dfs(int x) {
  if (x > cnt) {
    long long now = 1;
    for (int i = 1; i <= cnt; i++) {
      now = pc[i][cc[i]] % mo * ans[i][cc[i]] % mo * now % mo;
    }
    sum = (sum + now) % mo;
    return;
  }
  for (int i = 0; i <= c[x]; i++) cc[x] = i, dfs(x + 1);
}
int main() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i < N; i++) inv[i] = (mo - inv[mo % i] * (mo / i) % mo) % mo;
  scanf("%lld%lld", &n, &K);
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      p[++cnt] = i;
      pc[cnt][0] = 1;
      while (n % i == 0)
        c[cnt]++, pc[cnt][c[cnt]] = pc[cnt][c[cnt] - 1] * i, n /= i;
    }
  if (n > 1) p[++cnt] = n, c[cnt] = 1, pc[cnt][0] = 1, pc[cnt][1] = n;
  for (int i = 1; i <= cnt; i++) {
    ans[i][c[i]] = 1;
    for (int j = 1; j <= K; j++) {
      for (int k = 0; k <= c[i]; k++) ans[i][k] = ans[i][k] * inv[k + 1] % mo;
      for (int k = c[i]; k; k--)
        ans[i][k - 1] = (ans[i][k - 1] + ans[i][k]) % mo;
    }
  }
  dfs(1);
  printf("%lld\n", sum);
}
