#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
const int N = 50000;
const long long M = 1ll * N * (N - 1) / 2;
const int W = 30;
const int VERTEX = N * W + 1;
const long long mod = 1000000007;
int n;
long long k;
unsigned a[N + 10];
int ch[VERTEX + 10][2], val[VERTEX + 10], cnt = 1;
int sum[VERTEX + 10][W];
void ins(unsigned x) {
  int cur = 1;
  ++val[cur];
  for (int j = W - 1; ~j; --j) sum[cur][j] += x >> j & 1;
  for (int i = W - 1; ~i; --i) {
    int chk = x >> i & 1;
    if (!ch[cur][chk]) ch[cur][chk] = ++cnt;
    cur = ch[cur][chk];
    ++val[cur];
    for (int j = W - 1; ~j; --j) sum[cur][j] += x >> j & 1;
  }
  return;
}
int tmp[N + 10];
long long query(long long p) {
  int ans = 0;
  long long summ = 0ll;
  for (int i = 0; i <= n; ++i) tmp[i] = 1;
  for (int i = W - 1; ~i; --i) {
    long long cnt = 0;
    long long tmpsum = 0ll;
    for (int j = 1; j <= n; ++j) {
      int chk = a[j] >> i & 1 ^ 1;
      cnt += val[ch[tmp[j]][chk]];
      for (int k = W - 1; ~k; --k)
        tmpsum += ((long long)((a[j] >> k & 1 ^ 1) ? sum[ch[tmp[j]][chk]][k]
                                                   : (val[ch[tmp[j]][chk]] -
                                                      sum[ch[tmp[j]][chk]][k])))
                  << k;
    }
    if (p <= cnt) {
      ans |= (1 << i);
      for (int j = 1; j <= n; ++j) {
        int chk = a[j] >> i & 1 ^ 1;
        tmp[j] = ch[tmp[j]][chk];
      }
    } else {
      p -= cnt;
      summ += tmpsum;
      for (int j = 1; j <= n; ++j) {
        int chk = a[j] >> i & 1;
        tmp[j] = ch[tmp[j]][chk];
      }
    }
  }
  summ += p * ans;
  return summ;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%u", &a[i]), ins(a[i]);
  printf("%lld\n", query(2 * k) / 2 % mod);
  return 0;
}
