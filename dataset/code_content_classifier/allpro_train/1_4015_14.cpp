#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 17;
struct Segtree {
  int sum[maxn << 1];
  int col[maxn << 1];
  int n, m;
  int num[maxn];
  vector<int> A[maxn], B[maxn];
  int tot;
  void Init() {
    int x, y;
    tot = 0;
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
    sort(num + 1, num + 1 + n);
    memset(col, 0, sizeof(col));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) A[i].clear(), B[i].clear();
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &x, &y);
      if (y < num[1] || x > num[n]) continue;
      x = lower_bound(num + 1, num + 1 + n, x) - num;
      y = upper_bound(num + 1, num + 1 + n, y) - num - 1;
      A[x].push_back(y);
      B[y].push_back(x);
    }
  }
  void Solve() {
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      for (int j = 0, sz = A[i].size(); j < sz; j++)
        Update(i, A[i][j], 1, n, 1);
      int tmp = i - 1 - Query(1, i - 1, 1, n, 1) + Query(i + 1, n, 1, n, 1);
      ans -= (long long)tmp * (tmp - 1) / 2;
      for (int j = 0, sz = B[i].size(); j < sz; j++)
        Update(B[i][j], i, 1, n, 1);
    }
    printf("%I64d\n", ans);
  }
  void Make(int l, int r, int rt) {
    sum[rt] = r - l + 1 - sum[rt];
    col[rt] ^= 1;
  }
  void Down(int l, int r, int rt) {
    int m = l + r >> 1;
    if (col[rt]) {
      Make(l, m, rt << 1);
      Make(m + 1, r, rt << 1 | 1);
      col[rt] ^= 1;
    }
  }
  void Update(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
      Make(l, r, rt);
      return;
    }
    Down(l, r, rt);
    int m = l + r >> 1;
    if (L <= m) Update(L, R, l, m, rt << 1);
    if (R > m) Update(L, R, m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  }
  int Query(int L, int R, int l, int r, int rt) {
    if (L > R) return 0;
    if (L <= l && r <= R) return sum[rt];
    Down(l, r, rt);
    int m = l + r >> 1;
    int ret = 0;
    if (L <= m) ret += Query(L, R, l, m, rt << 1);
    if (R > m) ret += Query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
  }
} Seg;
int main() {
  while (scanf("%d", &Seg.n) != EOF) {
    Seg.Init();
    Seg.Solve();
  }
  return 0;
}
