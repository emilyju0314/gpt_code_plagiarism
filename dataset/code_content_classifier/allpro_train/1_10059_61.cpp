#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long a[MAXN], b[MAXN];
priority_queue<long long, vector<long long>, greater<long long> > q;
int main() {
  long long k, n;
  long long maxn = -1, id;
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (maxn < a[i]) maxn = a[i], id = i;
  }
  long long v;
  long long ans = 0;
  int flag = 0, g = 0;
  scanf("%lld", &v);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= id; i++) {
    q.push(b[i]);
    if (a[i] > k) {
      while ((!q.empty()) && k < a[i]) {
        k += v;
        ans += q.top();
        q.pop();
      }
    }
    if (a[i] > k) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    printf("-1\n");
  else
    printf("%lld\n", ans);
  return 0;
}
