#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 100000000;
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
long long factorial[1010];
const int NCK = 1010;
long long nck[NCK + 1][NCK + 1];
void calc_nck() {
  for (int i = 0; i < (NCK); i++) {
    nck[i][0] = nck[i][i] = 1;
    for (int j = 1; j <= i; j++) {
      nck[i + 1][j] = (nck[i][j - 1] + nck[i][j]) % MOD;
    }
  }
}
long long memo[1000][100];
void init() {
  memset(memo, -1, sizeof(memo));
  factorial[0] = 1;
  for (int i = 1; i < 1010; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }
  calc_nck();
}
long long dfs(int x, int k) {
  if (memo[x][k] != -1) return memo[x][k];
  if (k == 1) return memo[x][k] = 1;
  long long val = 0;
  for (int beta = 0; beta * k <= x; beta++) {
    val += dfs(x - beta * k, k - 1);
  }
  return memo[x][k] = val % MOD;
}
long long g(int x, int k) { return dfs(x, k); }
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int min_n = k + k * (k - 1) / 2;
    if (n < min_n) {
      puts("0");
      continue;
    }
    long long ans = 0;
    for (int x = k * (k - 1) / 2; x + k <= n; x++) {
      int p = n - x;
      long long a = nck[p][k] * factorial[k] % MOD;
      a = a * g(x - k * (k - 1) / 2, k) % MOD;
      ans = (ans + a) % MOD;
    }
    cout << ans % MOD << endl;
  }
  return 0;
}
