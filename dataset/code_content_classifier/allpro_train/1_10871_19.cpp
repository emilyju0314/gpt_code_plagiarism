#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
int d, n, m;
int mi[M * 4];
struct node {
  int x, cost;
  bool operator<(const node &tmp) const { return x < tmp.x; }
} A[M];
void build(int L, int R, int p) {
  if (L == R) {
    mi[p] = A[L].cost;
    return;
  }
  int mid = L + R >> 1;
  build(L, mid, p << 1);
  build(mid + 1, R, p << 1 | 1);
  mi[p] = min(mi[p << 1], mi[p << 1 | 1]);
}
int query(int L, int R, int l, int r, int p) {
  if (L == l && R == r) return mi[p];
  int mid = l + r >> 1;
  if (R <= mid)
    return query(L, R, l, mid, p << 1);
  else if (mid < L)
    return query(L, R, mid + 1, r, p << 1 | 1);
  else
    return min(query(L, mid, l, mid, p << 1),
               query(mid + 1, R, mid + 1, r, p << 1 | 1));
}
int main() {
  scanf("%d %d %d", &d, &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &A[i].x, &A[i].cost);
  }
  if (A[m].x < d) {
    A[++m].x = d;
    A[m].cost = 1e9;
  }
  sort(A + 1, A + 1 + m);
  build(1, m, 1);
  int oil = n;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    oil -= A[i].x - A[i - 1].x;
    if (oil < 0 || i == m) break;
    int pos = m, L = i + 1, R = m;
    while (L <= R) {
      int mid = L + R >> 1;
      if (query(i + 1, mid, 1, m, 1) <= A[i].cost) {
        R = mid - 1;
        pos = mid;
      } else
        L = mid + 1;
    }
    if (A[pos].x - A[i].x > oil) {
      if (A[pos].x - A[i].x <= n) {
        ans += 1ll * A[i].cost * (A[pos].x - A[i].x - oil);
        oil = A[pos].x - A[i].x;
      } else {
        ans += 1ll * A[i].cost * (n - oil);
        oil = n;
      }
    }
  }
  if (oil < 0)
    printf("-1\n");
  else
    printf("%lld\n", ans);
  return 0;
}
