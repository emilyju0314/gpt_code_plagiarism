#include <bits/stdc++.h>
const int mod = 998244353;
const int maxn = 1e6 + 5;
const int inf = 1e7;
const long long onf = 1e18;
using namespace std;
int n, m;
int q[maxn], root[maxn], sum[maxn];
long long ans[maxn];
struct node {
  int u, v, val;
  bool friend operator<(node a, node b) { return a.val < b.val; }
} a[maxn];
int Find(int x) {
  if (x == root[x]) return x;
  return root[x] = Find(root[x]);
}
void init() {
  for (int i = 1; i <= n; i++) {
    sum[i] = 1, root[i] = i;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i < n; i++) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].val);
  sort(a + 1, a + n);
  int End = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &q[i]);
    End = max(End, q[i]);
  }
  for (int i = 1; i < n; i++) {
    int x1 = Find(a[i].u);
    int y1 = Find(a[i].v);
    long long temp = 0;
    if (x1 != y1) {
      temp += (long long)sum[x1] * sum[y1];
      sum[y1] += sum[x1], sum[x1] = 0;
      root[x1] = y1;
    }
    ans[a[i].val] += temp;
  }
  for (int i = 1; i <= End; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= m; i++) printf("%lld ", ans[q[i]]);
  return 0;
}
