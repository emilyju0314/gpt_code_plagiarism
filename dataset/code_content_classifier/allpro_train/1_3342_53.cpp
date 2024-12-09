#include <bits/stdc++.h>
using namespace std;
struct node {
  long long k, l, ans;
  friend bool operator<(node a, node b) { return a.ans > b.ans; }
} p[100010];
int main() {
  int n, f;
  while (~scanf("%d%d", &n, &f)) {
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      long long l, k;
      scanf("%I64d%I64d", &k, &l);
      long long sell = min(l, k);
      sum += sell;
      if (l > k) {
        p[cnt].k = k;
        p[cnt].l = l;
        p[cnt].ans = 2 * k;
        if (p[cnt].ans > l) p[cnt].ans = l;
        p[cnt++].ans -= sell;
      }
    }
    sort(p, p + cnt);
    for (int i = 0; i < f; i++) sum += p[i].ans;
    printf("%I64d\n", sum);
  }
}
