#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
const int MOD = 998244353;
int mul(int a, int b) {
  long long c = (long long)a * b;
  return c % MOD;
}
int add(int a, int b) {
  long long c = (long long)a + b;
  while (c < 0) c += MOD;
  return c % MOD;
}
int pow(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int c = pow(a, b / 2);
  c = mul(c, c);
  if (b & 1) c = mul(c, a);
  return c;
}
int n;
void load() { scanf("%d", &n); }
int pow3[MAXN];
int fact[MAXN];
void solve() {
  pow3[0] = fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow3[i] = mul(pow3[i - 1], 3);
    fact[i] = mul(fact[i - 1], i);
  }
  int ans = pow(pow3[n], n);
  ans = add(ans, -pow(add(pow3[n], -3), n));
  for (int i = 1; i <= n; i++) {
    int sign = (i & 1) ? 1 : -1;
    int left = mul(3, pow(add(pow3[n - i], -1), n));
    int right = mul(add(pow3[i], -3), pow(pow3[n], n - i));
    int binom = mul(fact[n], pow(mul(fact[i], fact[n - i]), MOD - 2));
    ans = add(ans, sign * mul(binom, add(left, right)));
  }
  printf("%d\n", ans);
}
int main() {
  load();
  solve();
  return 0;
}
