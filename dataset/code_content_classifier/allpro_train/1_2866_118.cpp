#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 100;
long long t, n;
struct node {
  long long m, p;
} sh[N];
bool cmp(node a, node b) { return a.m > b.m; }
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld%lld", &sh[i].m, &sh[i].p);
    sort(sh + 1, sh + 1 + n, cmp);
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    for (long long i = 1; i <= n;) {
      long long j = i;
      while (j <= n && sh[j].m == sh[i].m) {
        q.push(sh[j].p);
        j++;
      }
      while (n - (long long)q.size() < sh[i].m) {
        ans += q.top();
        q.pop();
      }
      i = j;
    }
    printf("%lld\n", ans);
  }
}
