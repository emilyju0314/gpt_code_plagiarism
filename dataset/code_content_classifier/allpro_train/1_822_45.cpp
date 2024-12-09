#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
struct node {
  int mi, si;
  bool operator<(const node &b) const { return mi < b.mi; }
} a[100005];
int main() {
  int n, d;
  while (~scanf("%d%d", &n, &d)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].mi, &a[i].si);
    }
    sort(a + 1, a + n + 1);
    long long sum = 0;
    long long ans = 0;
    int t = 1;
    for (int i = 1; i <= n; i++) {
      sum += a[i].si;
      while (a[i].mi - a[t].mi >= d) {
        sum -= a[t++].si;
      }
      ans = max(ans, sum);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
