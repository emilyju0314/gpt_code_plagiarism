#include <bits/stdc++.h>
using namespace std;
const int A = 26;
const int maxn = 5e3 + 5;
const long long mod = 1e9 + 7;
char s[maxn];
int n;
int nxt[maxn][A];
long long fat[maxn], inv[maxn];
long long dp[maxn][maxn];
string t;
void fillNxtTable() {
  t = s;
  t = "$" + t;
  int last[A];
  fill(last, last + A, n + 1);
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < A; j++) nxt[i][j] = last[j];
    if (i) last[t[i] - 'a'] = i;
  }
}
long long exp(long long a, long long b) {
  long long result = 1;
  while (b) {
    if (b & 1) result = (result * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return result;
}
void preComputeBinomial() {
  fat[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fat[i] = (fat[i - 1] * i) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}
long long C(int n, int k) {
  if (k < 0) return 0;
  return (((fat[n] * inv[n - k]) % mod) * inv[k]) % mod;
}
long long solve(int pos, int k) {
  if (pos > n) return 0;
  long long &ans = dp[pos][k];
  if (ans != -1) return ans;
  ans = C(n - 1, k - 1);
  for (int i = 0; i < A; i++) {
    if ((t[pos] - 'a') != i) {
      ans = (ans + solve(nxt[pos][i], k + 1));
    }
  }
  ans %= mod;
  return ans;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  fillNxtTable();
  preComputeBinomial();
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(0, 0));
  return 0;
}
