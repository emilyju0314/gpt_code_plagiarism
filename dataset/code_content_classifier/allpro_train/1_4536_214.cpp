#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int const N = 1e6 + 16;
int const M = 1e9 + 7;
int const M2 = 999999983;
int n, m;
int g[5000][5000];
char w[5120];
int chk(int c) {
  int area = 0;
  for (int i = 0; i < n; ++i) area = max(area, (i + 1) * g[i][c]);
  return area;
}
int const msk = (1 << 13) - 1;
int arr[5120];
void radix(int c) {
  int cnt[msk + 1] = {};
  int x;
  for (int i = 0; i < n; ++i) x = arr[i] = g[i][c], ++cnt[x & msk];
  partial_sum(cnt, cnt + msk + 1, cnt);
  for (int i = n - 1; i >= 0; --i) {
    int x = arr[i];
    g[n - 1 - --cnt[(x)&msk]][c] = x;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", w);
    g[i][0] = w[0] - '0';
    for (int j = 0; j < m; ++j) g[i][j] = w[j] - '0';
    for (int j = m - 2; j >= 0; --j) g[i][j] += (g[i][j] ? g[i][j + 1] : 0);
  }
  for (int column = 0; column < m; ++column) radix(column);
  int ans = 0;
  for (int column = 0; column < m; ++column) ans = max(ans, chk(column));
  printf("%d\n", ans);
}
