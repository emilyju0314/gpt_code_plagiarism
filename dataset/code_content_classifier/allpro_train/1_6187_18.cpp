#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N][N];
char s[N << 1];
int t[N], t2[N], sa[N];
int cnt[N], rank[N], c[300];
void build_sa(int n, int m) {
  int *x = t, *y = t2;
  for (int i = 0; i < m; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
  for (int i = 1; i < m; i++) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int p = 0;
    for (int i = n - k; i < n; i++) y[p++] = i;
    for (int i = 0; i < n; i++)
      if (sa[i] >= k) y[p++] = sa[i] - k;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1;
    x[sa[0]] = 0;
    for (int i = 1; i < n; i++)
      x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]
                     ? p - 1
                     : p++;
    if (p >= n) break;
    m = p;
  }
}
int sum[N], flag;
char get(int i, int p) { return s[sa[i] + p]; }
void solve(int l, int r, int p, int &k) {
  if (l > r || k <= 0) return;
  for (int i = l; i <= r; i++) {
    if (flag) return;
    int j = i;
    while (k && j <= r && get(j, p) == get(i, p)) {
      if (dp[sa[j] + 1][sa[j] + p + 1]) k--;
      j++;
    }
    if (k == 0) {
      for (int l = sa[j - 1]; l <= sa[j - 1] + p; l++) printf("%c", s[l]);
      printf("\n");
      flag = 1;
      return;
    }
    int tl = i;
    while (tl <= j - 1 && get(tl, p + 1) == '\0') tl++;
    solve(tl, j - 1, p + 1, k);
    i = j - 1;
  }
}
int main() {
  int k, n;
  flag = 0;
  memset(s, '\0', sizeof(s));
  scanf("%s%d", s, &k);
  n = strlen(s);
  for (int l = 1; l <= n; l++)
    for (int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      dp[i][j] = s[i - 1] == s[j - 1] && ((i + 2 > j - 2) || dp[i + 2][j - 2]);
    }
  s[n] = 0;
  build_sa(n + 1, 128);
  solve(1, n, 0, k);
  return 0;
}
