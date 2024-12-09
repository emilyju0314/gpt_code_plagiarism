#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
const int K = 20;
const int inf = 0x3f3f3f3f;
int a[N], dp[N];
pair<int, int> rmq[N][K];
inline void build(int n) {
  for (int j = 1; j < K; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      rmq[i][j].first =
          max(rmq[i][j - 1].first, rmq[i + (1 << (j - 1))][j - 1].first);
      rmq[i][j].second =
          min(rmq[i][j - 1].second, rmq[i + (1 << (j - 1))][j - 1].second);
    }
  }
}
inline int query(int l, int r) {
  int j = (int)log2(r - l + 1);
  int maxx = max(rmq[l][j].first, rmq[r - (1 << j) + 1][j].first);
  int minn = min(rmq[l][j].second, rmq[r - (1 << j) + 1][j].second);
  return maxx - minn;
}
int main() {
  int n, s, l;
  while (~scanf("%d%d%d", &n, &s, &l)) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      rmq[i][0].first = rmq[i][0].second = a[i];
    }
    build(n);
    int pre = 0;
    for (int i = 1; i <= n; i++) {
      while (pre < i - l && (query(pre + 1, i) > s || dp[pre] >= inf)) {
        pre++;
      }
      dp[i] = (pre <= i - l && query(pre + 1, i) <= s ? dp[pre] + 1 : inf);
    }
    printf("%d\n", dp[n] >= inf ? -1 : dp[n]);
  }
}
