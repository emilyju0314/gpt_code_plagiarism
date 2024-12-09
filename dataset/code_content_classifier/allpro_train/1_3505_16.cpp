#include <bits/stdc++.h>
using namespace std;
char g[1001000];
int r[1001000];
int sa[1001000];
int scnt[1001000];
int wa[1001000], wb[1001000], wv[1001000];
int mrank[1001000];
int h[1001000], th[1001000];
int dp[1001000][22];
int save[1001000];
int cmp(int gg[], int a, int b, int k) {
  return gg[a] == gg[b] && gg[a + k] == gg[b + k];
}
void getsa(int str[], int sa[], int n, int m) {
  int i, j, *x, *y, *t;
  x = wa;
  y = wb;
  memset(scnt, 0, sizeof(scnt));
  for (i = 0; i < n; i++) scnt[x[i] = str[i]]++;
  for (i = 1; i < m; i++) scnt[i] += scnt[i - 1];
  for (i = 0; i < n; i++) sa[--scnt[str[i]]] = i;
  for (int p = 1, j = 1; p < n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    memset(scnt, 0, sizeof(scnt));
    for (i = 0; i < n; i++) scnt[wv[i]]++;
    for (i = 1; i < m; i++) scnt[i] += scnt[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--scnt[wv[i]]] = y[i];
    for (p = 1, t = x, x = y, y = t, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
  }
}
void geth(int str[], int n) {
  h[n - 1] = 0;
  int p = 0;
  for (int i = 0; i < n - 1; i++) {
    int tmp = mrank[i];
    while (str[i + p] == str[sa[tmp - 1] + p]) p++;
    h[i] = p;
    p--;
    p = max(0, p);
  }
}
void buildst(int n) {
  for (int i = 1; i <= n; i++) dp[i][0] = th[i];
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j + (1 << (i - 1)) > n)
        dp[j][i] = dp[j][i - 1];
      else
        dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
    }
  }
}
int cal(int x, int y) {
  if (x > y) swap(x, y);
  x++;
  int k = 0;
  while ((1 << k) <= (y - x + 1)) k++;
  k--;
  return min(dp[x][k], dp[y - (1 << k) + 1][k]);
}
int save1[1001000];
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  scanf("%s", g);
  int len = strlen(g);
  for (int i = 0; i < len; i++) r[i] = g[i];
  r[len++] = 0;
  getsa(r, sa, len, 300);
  for (int i = 0; i < len; i++) mrank[sa[i]] = i;
  geth(r, len);
  for (int i = 0; i < len - 1; i++) th[mrank[i]] = h[i];
  buildst(len - 1);
  memset(save, 0, sizeof(save));
  int flag = 0;
  int cnt;
  int pre;
  if (n != 0) scanf("%d", &pre);
  save1[0] = pre;
  for (int i = 1; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    save1[i] = tmp;
    int key = tmp - pre;
    if (key >= len - 1) {
      pre = tmp;
      continue;
    }
    cnt = cal(mrank[0], mrank[key]);
    if (cnt != len - 1 - key) flag = 1;
    pre = tmp;
  }
  if (flag == 1)
    printf("0\n");
  else {
    int ansum = 0;
    int big = 1;
    for (int i = 0; i < n; i++) {
      if (save1[i] > big) {
        ansum += save1[i] - big;
      }
      big = save1[i] + len - 1;
    }
    ansum += m - big + 1;
    long long ans = 1;
    for (int i = 0; i < ansum; i++) {
      ans = ans * 26;
      ans %= 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
