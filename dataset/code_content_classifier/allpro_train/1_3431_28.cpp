#include <bits/stdc++.h>
int p, n, l;
long long ansr;
int val1[1000005], val2[1000005], val3[1000005];
struct GET {
  long long a[101][101];
  int n, m;
  void init(int l, int r) {
    n = l, m = r;
    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++) a[i][j] = (i == j);
  }
} ct, ans, null, tmp;
GET operator*(const GET &a, const GET &b) {
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < b.m; j++) {
      tmp.a[i][j] = 0;
      for (int k = 0; k < a.m; k++)
        tmp.a[i][j] = (tmp.a[i][j] + a.a[i][k] * b.a[k][j]) % 1000000007;
    }
  tmp.n = a.n, tmp.m = b.m;
  return tmp;
}
void calc() {
  GET t = ct, anss;
  anss.init(p, p);
  for (int k = l - 2; k; k >>= 1, t = t * t)
    if (k & 1) anss = anss * t;
  ans = ans * anss;
}
int main() {
  scanf("%d%d%d", &n, &l, &p);
  ans.n = 1, ans.m = ct.n = ct.m = p;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val1[i]);
    ans.a[0][val1[i] % p]++;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val2[i]);
    for (int j = 0; j < p; j++) ct.a[(p - val2[i] % p + j) % p][j]++;
  }
  for (int i = 1; i <= n; i++)
    scanf("%d", &val3[i]), val3[i] = (val3[i] + val2[i]) % p;
  calc();
  for (int i = 1; i <= n; i++)
    ansr = (ansr + ans.a[0][(p - val3[i]) % p]) % 1000000007;
  printf("%I64d", ansr);
}
