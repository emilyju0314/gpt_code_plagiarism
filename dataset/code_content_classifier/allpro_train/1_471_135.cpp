#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n;
int ans[maxn];
int tree[maxn];
struct node {
  int x, h, id, to;
} d[maxn];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int i, j, k;
  while (cin >> n) {
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &d[i].x, &d[i].h);
      d[i].id = i;
      d[i].to = d[i].x - 1 + d[i].h;
    }
    sort(d + 1, d + n + 1, cmp);
    ans[d[n].id] = 1;
    for (i = n - 1; i > 0; i--) {
      int last = d[i].to;
      int q = i + 1;
      ans[d[i].id] = 1;
      while (1) {
        if (q > n) break;
        if (d[q].x <= last)
          ans[d[i].id] += ans[d[q].id];
        else
          break;
        q = q + ans[d[q].id];
      }
    }
    for (i = 1; i < n; i++) cout << ans[i] << " ";
    cout << ans[i] << endl;
  }
  return 0;
}
