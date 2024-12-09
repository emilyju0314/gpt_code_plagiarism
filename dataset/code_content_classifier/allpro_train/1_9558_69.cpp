#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, sp = 25, l, k, x, b[18], v[100030 << 1], a[100030 << 1],
                h[100030 << 1], id[100030 << 1], SA[2][100030 << 1],
                rk[2][100030 << 1], ST[100030 << 1][18], cnt[100030], f[100030];
long long ans[100030];
char s[100030];
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    k = strlen(s);
    if (m == 1) printf("%I64d ", (long long)k * (k + 1) / 2);
    for (int j = 0; j < k; j++) {
      a[++l] = s[j] - 'a';
      id[l] = i;
    }
    a[++l] = ++sp;
  }
  if (m == 1) exit(0);
}
void Calc_SA(int sa[100030 << 1], int rk[100030 << 1], int SA[100030 << 1],
             int RK[100030 << 1]) {
  for (int i = 1; i <= l; i++) v[rk[sa[i]]] = i;
  for (int i = l; i; i--)
    if (sa[i] > k) SA[v[rk[sa[i] - k]]--] = sa[i] - k;
  for (int i = l - k + 1; i <= l; i++) SA[v[rk[i]]--] = i;
  for (int i = 1; i <= l; i++)
    RK[SA[i]] = RK[SA[i - 1]] + (rk[SA[i - 1]] != rk[SA[i]] ||
                                 rk[SA[i - 1] + k] != rk[SA[i] + k]);
}
void Create_SA() {
  p = 0, q = 1, a[0] = -1;
  for (int i = 1; i <= l; i++) v[a[i]]++;
  for (int i = 1; i <= sp; i++) v[i] += v[i - 1];
  for (int i = 1; i <= l; i++) SA[0][v[a[i]]--] = i;
  for (int i = 1; i <= l; i++)
    rk[0][SA[0][i]] = rk[0][SA[0][i - 1]] + (a[SA[0][i - 1]] != a[SA[0][i]]);
  k = 1;
  while (rk[p][SA[p][l]] < l) {
    Calc_SA(SA[p], rk[p], SA[q], rk[q]);
    p ^= 1;
    q ^= 1;
    k <<= 1;
  }
}
void Calc_Height() {
  k = 0;
  for (int i = 1; i <= l; i++) {
    if (k) k--;
    int j = SA[p][rk[p][i] - 1];
    while (a[i + k] == a[j + k]) k++;
    h[rk[p][i]] = k;
  }
}
inline int RMQ(int l, int r) {
  int x = v[r - l];
  return min(ST[l][x], ST[r - b[x] + 1][x]);
}
void Sparse_Table() {
  for (int i = 0; i < 18; i++) b[i] = 1 << i;
  k = 0;
  for (int i = 1; i <= l; i++) {
    if (i == b[k + 1]) k++;
    v[i] = k;
    ST[i][0] = h[i];
  }
  for (int x = 1; x <= 17; x++)
    for (int i = 1; i <= l - b[x]; i++)
      ST[i][x] = min(ST[i][x - 1], ST[i + b[x - 1]][x - 1]);
}
void DP() {
  l -= n;
  int j = k = 0;
  for (int i = 1; i <= l; i++) {
    if (!(--cnt[id[SA[p][i - 1]]])) k--;
    while (k < m && j <= l)
      if (!(cnt[id[SA[p][++j]]]++)) k++;
    f[i] = max(min(f[i - 1], h[i]), RMQ(i + 1, j));
    ans[id[SA[p][i]]] += f[i];
  }
}
int main() {
  Init();
  Create_SA();
  Calc_Height();
  Sparse_Table();
  DP();
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
