#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
long long power(long long n, long long p) {
  long long base = n, res = 1;
  while (p) {
    if (p & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    p >>= 1;
  }
  return res;
}
const int MAXN = 2000006;
long long FAT[MAXN];
long long MPOWER[MAXN];
long long NPOWER[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  FAT[0] = MPOWER[0] = NPOWER[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    FAT[i] = (i * FAT[i - 1]) % MOD;
    NPOWER[i] = (NPOWER[i - 1] * n) % MOD;
    MPOWER[i] = (MPOWER[i - 1] * m) % MOD;
  }
  long long ans = 0LL;
  for (int k = 2; k < n + 1; k++) {
    if (k > m + 1) break;
    long long tmp = (FAT[n - 2]) % MOD;
    tmp = (tmp * power(FAT[n - k], MOD - 2)) % MOD;
    tmp = (tmp * FAT[m - 1]) % MOD;
    tmp = (tmp * power(FAT[k - 2], MOD - 2)) % MOD;
    tmp = (tmp * power(FAT[m - k + 1], MOD - 2)) % MOD;
    if (k < n) {
      tmp = (tmp * k) % MOD;
      tmp = (tmp * power(n, n - k - 1)) % MOD;
      tmp = (tmp * MPOWER[n - k]) % MOD;
    }
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}
