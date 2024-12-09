#include <bits/stdc++.h>
using namespace std;
const long long N = 400010;
long long n, m, Q;
long long a[N], b[N], c[N];
struct query {
  long long k, id;
} q[N];
bool cmp(query x, query y) { return x.k < y.k; }
long long fa[N];
long long find(long long x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
long long sum[N], cnt[N], ans[N];
set<pair<long long, pair<long long, long long> > > s;
signed main() {
  cin >> n >> m >> Q;
  for (long long i = (1), _b = (n); i <= _b; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = (1), _b = (m); i <= _b; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  long long p1 = 1, p2 = 1;
  for (long long i = (1), _b = (n + m); i <= _b; i++) {
    if (p2 > m)
      c[i] = a[p1++], cnt[i] = 1;
    else if (p1 > n)
      c[i] = b[p2++];
    else if (a[p1] < b[p2])
      c[i] = a[p1++], cnt[i] = 1;
    else
      c[i] = b[p2++];
  }
  for (long long i = (1), _b = (n + m); i <= _b; i++) fa[i] = i;
  sum[0] = 0;
  for (long long i = (1), _b = (n + m); i <= _b; i++)
    sum[i] = sum[i - 1] + c[i];
  for (long long i = (1), _b = (n + m - 1); i <= _b; i++) {
    s.insert(make_pair(c[i + 1] - c[i], make_pair(i, i + 1)));
  }
  for (long long i = (1), _b = (Q); i <= _b; i++) {
    cin >> q[i].k;
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1, cmp);
  long long res = 0;
  for (long long i = (1), _b = (n); i <= _b; i++) res += a[i];
  for (long long i = (1), _b = (Q); i <= _b; i++) {
    long long add = q[i].k;
    while (1) {
      if (s.empty()) break;
      pair<long long, pair<long long, long long> > p = *s.begin();
      if (p.first <= add) {
        long long fx = p.second.first, fy = p.second.second;
        fx = find(fx);
        fy = find(fy);
        fa[fx] = fy;
        if (cnt[fx]) {
          res -= sum[fx] - sum[fx - cnt[fx]];
          res -= sum[fy] - sum[fy - cnt[fy]];
          cnt[fy] += cnt[fx];
          cnt[fx] = 0;
          res += sum[fy] - sum[fy - cnt[fy]];
        }
        if (!s.empty()) s.erase(s.begin());
      } else
        break;
    }
    ans[q[i].id] = res;
  }
  for (long long i = (1), _b = (Q); i <= _b; i++) cout << ans[i] << "\n";
  return 0;
}
