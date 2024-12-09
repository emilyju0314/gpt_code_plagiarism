#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T& x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T& x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 5e2 + 17;
int dp[maxn][maxn], h[maxn], t[maxn], n, m, r, a[maxn][maxn], cur,
    pre[maxn][maxn], suf[maxn][maxn], nmsuf[maxn][maxn], nmpre[maxn][maxn];
int dis(int x1, int y1, int x2, int y2) {
  return (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
}
bool save[maxn][maxn];
bool inter(int x1, int y1, int x2, int y2) {
  return save[abs(x1 - x2)][abs(y1 - y2)];
}
int cn;
int get(int x, int y) {
  cn = 0;
  int ans = -1;
  int le = y - 1, ri = y;
  for (int i = r; i < n - r; i++) {
    while (inter(i, le, x, y)) le--;
    while (inter(i, ri, x, y)) ri++;
    while (le < y - 1 && !inter(i, le + 1, x, y)) le++;
    while (ri > y && !inter(i, ri - 1, x, y)) ri--;
    if (le >= r) {
      if (smax(ans, pre[i][le])) cn = 0;
      if (pre[i][le] == ans) cn += nmpre[i][le];
    }
    if (ri < m - r) {
      if (smax(ans, suf[i][ri])) cn = 0;
      if (suf[i][ri] == ans) cn += nmsuf[i][ri];
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> r;
  int r2 = r * r;
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++) {
      int Vx = i >> 1, Vy = j >> 1;
      for (int vx = Vx - 3; vx <= Vx + 3; vx++)
        for (int vy = Vy - 3; vy <= Vy + 3; vy++)
          if (dis(0, 0, vx, vy) <= r2 && dis(i, j, vx, vy) <= r2)
            save[i][j] = 1;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = r; i < n - r; i++) {
    cur = 0;
    memset(h, 0, sizeof h);
    memset(t, 0, sizeof h);
    for (int j = r; j < m - r; j++) {
      for (int k = i - r; k <= i + r; k++) {
        while (dis(k, h[k], i, j) > r * r) cur -= a[k][h[k]++];
        while (t[k] < h[k] || dis(k, t[k], i, j) <= r * r) cur += a[k][t[k]++];
      }
      dp[i][j] = cur;
    }
  }
  for (int i = r; i < n - r; i++) {
    for (int j = r; j < m - r; j++) {
      if (j) pre[i][j] = pre[i][j - 1], nmpre[i][j] = nmpre[i][j - 1];
      if (smax(pre[i][j], dp[i][j])) nmpre[i][j] = 0;
      if (pre[i][j] == dp[i][j]) nmpre[i][j]++;
    }
    for (int j = m - 1 - r; j >= r; j--) {
      suf[i][j] = suf[i][j + 1], nmsuf[i][j] = nmsuf[i][j + 1];
      if (smax(suf[i][j], dp[i][j])) nmsuf[i][j] = 0;
      if (suf[i][j] == dp[i][j]) nmsuf[i][j]++;
    }
  }
  long long mx = 0, num = 0;
  for (int i = r; i < n - r; i++)
    for (int j = r; j < m - r; j++) {
      int ok = get(i, j);
      if (~ok) ok += dp[i][j];
      if (smax(mx, ok)) num = 0;
      if (mx == ok) num += cn;
    }
  assert(num % 2 == 0);
  cout << mx << ' ' << num / 2 << '\n';
  return 0;
}
