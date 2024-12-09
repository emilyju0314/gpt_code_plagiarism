#include <bits/stdc++.h>
const int MAXN = 300000;
int n, m, k;
double Ans, Fac[MAXN + 5];
void Init() {
  Fac[0] = 0;
  for (int i = 1; i <= MAXN; i++) Fac[i] = Fac[i - 1] + log(i * 1.0);
}
double C(int n, int m) { return Fac[n] - Fac[m] - Fac[n - m]; }
int main() {
  Init();
  scanf("%d %d %d", &n, &m, &k);
  if (k >= m)
    Ans = 1;
  else if (n + k < m)
    Ans = 0;
  else
    Ans = 1 - exp(C(n + m, n + k + 1) - C(n + m, n));
  printf("%.6lf", Ans);
  return 0;
}
