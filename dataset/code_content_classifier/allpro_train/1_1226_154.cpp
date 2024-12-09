#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int M = 998244353;
int n, a[N], l[N], r[N], tt[N], cnt[N], ans;
int qpow(int x, int y) {
  int out = 1;
  while (y) {
    if (y & 1) out = (long long)out * x % M;
    x = (long long)x * x % M;
    y >>= 1;
  }
  return out;
}
void add(int p, int x) {
  for (; p <= n; p += (p & -p)) {
    tt[p] += x;
  }
}
int query(int p) {
  int res = 0;
  for (; p > 0; p -= (p & -p)) {
    res += tt[p];
  }
  return res;
}
int main() {
  int i, inv;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] != -1) ++cnt[a[i]];
    l[i] = l[i - 1] + (a[i] == -1);
  }
  for (i = 1; i <= n; ++i) {
    cnt[i] += cnt[i - 1];
  }
  inv = qpow(4, M - 2);
  ans = (long long)l[n] * (l[n] - 1) % M * inv % M;
  inv = qpow(l[n], M - 2);
  for (i = n; i >= 1; --i) {
    r[i] = r[i + 1] + (a[i] == -1);
    if (a[i] != -1) {
      ans = (ans + query(a[i])) % M;
      add(a[i], 1);
      ans = (ans + (long long)r[i] * (a[i] - cnt[a[i]]) % M * inv % M) % M;
      ans =
          (ans + (long long)l[i] * (l[n] - a[i] + cnt[a[i]]) % M * inv % M) % M;
    }
  }
  printf("%d", ans);
  return 0;
}
