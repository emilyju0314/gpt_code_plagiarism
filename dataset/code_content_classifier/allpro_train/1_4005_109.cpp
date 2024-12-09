#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T& x, T y) {
  x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
  x = (y < x ? y : x);
}
const int MAXN = 80;
const int INF = 0x3f3f3f3f;
int n, a[MAXN + 5], cnt[2], pos[MAXN + 5], cnt_pos,
    ans[MAXN * (MAXN - 1) / 2 + 5];
int total, max_op;
int dp[MAXN + 5][MAXN * (MAXN - 1) / 2 + 5][MAXN + 5];
int calc(int len) { return len * (len - 1) / 2; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
    if (a[i] == 1) {
      pos[++cnt_pos] = i;
    }
  }
  total = calc(cnt[0]);
  max_op = calc(n);
  if (!cnt[1]) {
    for (int i = 0; i <= max_op; ++i) {
      cout << 0 << " ";
    }
    cout << endl;
    return 0;
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i < n; ++i) {
    dp[i][abs(pos[1] - i)][1] = calc(i - 1);
    for (int j = 0; j <= max_op; ++j) {
      for (int k = 0; k <= i && k < cnt[1]; ++k)
        if (dp[i][j][k] != INF) {
          int rest = cnt[1] - k;
          for (int l = i + 1; l <= n - rest + 1; ++l) {
            int newj = j + abs(pos[k + 1] - l);
            if (newj <= max_op)
              ckmin(dp[l][newj][k + 1], dp[i][j][k] + calc(l - i - 1));
          }
        }
    }
  }
  for (int i = 0; i <= max_op; ++i) ans[i] = total;
  for (int i = cnt[1]; i <= n; ++i) {
    for (int j = 0; j <= max_op; ++j) {
      ckmin(ans[j], dp[i][j][cnt[1]] + calc(n - i));
    }
  }
  for (int i = 0; i <= max_op; ++i) {
    if (i) ckmin(ans[i], ans[i - 1]);
    cout << total - ans[i] << " ";
  }
  cout << endl;
  return 0;
}
