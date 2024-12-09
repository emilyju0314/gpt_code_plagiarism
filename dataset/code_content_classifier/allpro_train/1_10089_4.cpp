#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const long long mod = 1000000007;
char s[N];
int nxt[N], pos[N], ext[N];
void pre_KMP(char x[], int m, int nxt[]) {
  nxt[0] = m;
  int j = 0;
  while (j + 1 < m && x[j] == x[j + 1]) ++j;
  nxt[1] = j;
  int k = 1;
  for (int i = 2; i < m; ++i) {
    int p = nxt[k] + k - 1;
    int L = nxt[i - k];
    if (i + L < p + 1)
      nxt[i] = L;
    else {
      j = max(0, p - i + 1);
      while (i + j < m && x[i + j] == x[j]) ++j;
      nxt[i] = j;
      k = i;
    }
  }
}
void EKMP(char x[], int m, char y[], int n, int nxt[], int ext[]) {
  pre_KMP(x, m, nxt);
  int j = 0;
  while (j < n & j < m && x[j] == y[j]) ++j;
  ext[0] = j;
  int k = 0;
  for (int i = 1; i < n; ++i) {
    int p = ext[k] + k - 1;
    int L = nxt[i - k];
    if (i + L < p + 1)
      ext[i] = L;
    else {
      j = max(0, p - i + 1);
      while (i + j < n && j < m && y[i + j] == x[j]) ++j;
      ext[i] = j;
      k = i;
    }
  }
}
long long kpow(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int m, n;
  scanf("%d%d%s", &m, &n, &s);
  if (!n) return 0 * printf("%I64d\n", kpow(26ll, m) % mod);
  long long ans = 1ll;
  int slen = strlen(s), len = 0;
  EKMP(s, slen, s, slen, nxt, ext);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", &pos[i]);
  ans = (ans * kpow(26ll, pos[1] - 1)) % mod;
  pos[n + 1] = m + 1;
  for (int i = (1); i < (n + 1); ++i) {
    if (pos[i + 1] - pos[i] >= slen) {
      ans = (ans * kpow(26ll, pos[i + 1] - pos[i] - slen)) % mod;
    } else {
      int tmp = pos[i] + slen - pos[i + 1];
      if (ext[slen - tmp] != tmp) return 0 * puts("0");
    }
  }
  printf("%I64d\n", ans % mod);
  return 0;
}
