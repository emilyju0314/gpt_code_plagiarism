#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 100000;
int n, k;
int h[MAXN + 10], f1[MAXN + 10][20], f2[MAXN + 10][20], ans[MAXN + 10];
void ST_pre() {
  for (int i = 1; i <= n; i++) f1[i][0] = f2[i][0] = h[i];
  int t = log(n) / log(2) + 1;
  for (int j = 1; j < t; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++) {
      f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
      f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
    }
}
int ST_query(int l, int r) {
  int k = log(r - l + 1) / log(2);
  return max(f1[l][k], f1[r - (1 << k) + 1][k]) -
         min(f2[l][k], f2[r - (1 << k) + 1][k]);
}
int main() {
  cin >> n >> k;
  int beg = 1, l = 0, cnt = 0;
  for (int i = 1; i <= n; i++) cin >> h[i];
  ST_pre();
  for (int i = 1; i <= n; i++) {
    while (ST_query(beg, i) > k) beg++;
    if (i - beg + 1 == l)
      ans[cnt++] = beg;
    else if (i - beg + 1 > l) {
      l = i - beg + 1;
      cnt = 0;
      ans[cnt++] = beg;
    }
  }
  cout << l << " " << cnt << endl;
  for (int i = 0; i < cnt; i++) cout << ans[i] << " " << ans[i] + l - 1 << endl;
  return 0;
}
