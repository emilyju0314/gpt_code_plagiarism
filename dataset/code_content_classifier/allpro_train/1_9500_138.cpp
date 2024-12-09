#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int mx = 1e3 + 6;
const int mm = (1 << 16) - 1;
const int INF = 0x3f3f3f3f;
int n, a[4], st[mx];
char s[4][mx];
int d[mx][mm + 6];
vector<int> mark[4];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 4; i++) scanf("%s", s[i]);
  for (int j = 0; j < n; j++)
    for (int i = 0; i < 4; i++) st[j] |= (s[i][j] == '*') << i;
  memset(d, 0x3f, sizeof(d));
  int S = 0;
  for (int i = 0; i < 4; i++) S |= st[i] << (i * 4);
  d[0][S] = 0;
  for (int i = 1; i <= 4; i++) {
    for (int j = 0; j <= 4 - i; j++) {
      mark[i - 1].push_back(mm);
      int& SS = mark[i - 1].back();
      for (int k = j; k < j + i; k++)
        for (int g = 0; g < i; g++) SS ^= 1 << (g * 4 + k);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = mm; j >= 0; j--) {
      if (d[i][j] == INF) continue;
      if (!(j & 15)) {
        int SS = j >> 4 | (st[i + 4] << 12);
        d[i + 1][SS] = min(d[i][j], d[i + 1][SS]);
      }
      for (int k = 1; k <= 4 && k + i <= n; k++)
        for (auto p : mark[k - 1])
          d[i][j & p] = min(d[i][j & p], d[i][j] + a[k - 1]);
    }
  }
  printf("%d\n", d[n][0]);
}
