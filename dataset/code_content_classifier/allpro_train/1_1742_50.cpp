#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, mid;
int a[100005], sum[100005];
struct node {
  int g, d;
} t[100005];
bool cmp(node a, node b) { return a.d <= b.d; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &t[i].d, &t[i].g);
  }
  sort(t + 1, t + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + t[i].g;
  }
  for (int i = 1; i <= n; i++) {
    l = 1;
    r = m;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (a[i] >= t[mid].d) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    printf("%d ", sum[r]);
  }
  return 0;
}
