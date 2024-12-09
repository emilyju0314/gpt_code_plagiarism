#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
struct {
  int cost;
  int num;
} b[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  memset(b, 0, sizeof(b));
  sort(a, a + n);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    int cnt = 0;
    while (tmp) {
      b[tmp].cost += cnt;
      b[tmp].num++;
      if (b[tmp].num >= k) {
        ans = min(ans, b[tmp].cost);
      }
      tmp /= 2;
      cnt++;
    }
    b[0].cost += cnt;
    b[0].num++;
    if (b[0].num >= k) {
      ans = min(ans, b[tmp].cost);
    }
  }
  printf("%d\n", ans);
}
