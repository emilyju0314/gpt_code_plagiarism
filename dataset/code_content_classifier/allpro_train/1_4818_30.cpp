#include <bits/stdc++.h>
using namespace std;
long long n, m, pe, wbbb, t, j, k, ans;
long long a[11000000];
pair<long long, long long> p[1100000];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  a[0] = 1e9 + 7;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld", &p[i].first);
  for (long long i = 1; i <= m; i++) scanf("%lld", &p[i].second);
  sort(p + 1, p + m + 1);
  pe = 1;
  for (long long i = n; i >= 1; i = j) {
    t = 0;
    for (j = i; a[j] <= a[i]; j--) t += a[j];
    for (k = pe; k <= m && p[k].first <= a[i]; k++) q.push(p[k].second);
    pe = k;
    while (!q.empty()) {
      if (t >= q.top())
        ans++, t -= q.top(), q.pop();
      else {
        t = q.top() - t;
        q.pop();
        q.push(t);
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
