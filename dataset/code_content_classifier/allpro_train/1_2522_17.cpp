#include <bits/stdc++.h>
using namespace std;
struct aaa {
  int x, y, id;
} aa[1000001];
int n, m, now, a[1000001], ans[1000001], p[1001], pos[1001];
bool cmp(aaa a, aaa b) { return a.y < b.y; }
void add(int x, int id) {
  int i;
  for (i = 20; i >= 0; i--)
    if (x & (1 << i)) {
      if (!p[i]) {
        p[i] = x;
        pos[i] = id;
        return;
      }
      if (pos[i] < id) swap(p[i], x), swap(pos[i], id);
      x ^= p[i];
    }
}
int query(int id) {
  int i, sum = 0;
  for (i = 20; i >= 0; i--)
    if (pos[i] >= id && (sum ^ p[i]) > sum) sum ^= p[i];
  return sum;
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &aa[i].x, &aa[i].y);
    aa[i].id = i;
  }
  sort(aa + 1, aa + m + 1, cmp);
  now = 1;
  for (i = 1; i <= m; i++) {
    while (now <= aa[i].y && now <= n) add(a[now], now), now++;
    ans[aa[i].id] = query(aa[i].x);
  }
  for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
