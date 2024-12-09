#include <bits/stdc++.h>
using namespace std;
int p[2000100], sum[2000100];
int fac[2000100], rev[2000100];
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int main() {
  int N, M, a, P, Q;
  scanf("%d%d%d%d", &N, &M, &a, &Q);
  p[0] = 1;
  P = -1;
  for (int i = 1; i < 2000100; i++) {
    p[i] = 1LL * p[i - 1] * a % Q;
    if (p[i] == 1 && P < 0 && i > 1) P = i;
  }
  fac[0] = rev[0] = 1;
  while (P <= 1)
    ;
  for (int i = 1; i < 2000100; i++) {
    fac[i] = (long long)fac[i - 1] * i % P;
    rev[i] = power(fac[i], P - 2, P);
  }
  sum[0] = 1;
  for (int i = 1; i <= M; i++) {
    int c = (long long)fac[M] * rev[i] % P;
    c = (long long)c * rev[M - i] % P;
    sum[i] = ((long long)sum[i - 1] + c) % P;
  }
  for (int i = N - 1; i >= 0; i--) {
    int k = min(i, M);
    printf("%d ", p[sum[k]]);
  }
  return 0;
}
