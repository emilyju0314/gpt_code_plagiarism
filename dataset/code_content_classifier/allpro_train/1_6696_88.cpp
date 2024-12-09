#include <bits/stdc++.h>
using namespace std;
const long long _ = 1e5 + 7;
struct node {
  long long A, B, C, id;
} now[_];
long long N, A, B, C, D, dp[_];
long long arr[_];
void add(long long x, long long v) {
  while (x <= N) {
    arr[x] = max(arr[x], v);
    x += x & -x;
  }
}
long long qry(long long x) {
  long long sum = 0;
  while (x) {
    sum = max(sum, arr[x]);
    x -= x & -x;
  }
  return sum;
}
void clr(long long x) {
  while (x <= N) {
    arr[x] = 0;
    x += x & -x;
  }
}
void work(long long l, long long r, long long xl, long long xr) {
  if (l >= r || xl == xr) return;
  long long xmid = (xl + xr) >> 1, mid = l;
  while (mid <= r && now[mid].A <= xmid) ++mid;
  work((--mid) + 1, r, xmid + 1, xr);
  vector<node> pl;
  for (long long i = l; i <= mid; ++i) pl.push_back(now[i]);
  sort(pl.begin(), pl.end(), [&](node p, node q) { return p.B > q.B; });
  sort(now + mid + 1, now + r + 1, [&](node p, node q) { return p.B > q.B; });
  long long pr = mid + 1;
  for (auto t : pl) {
    while (pr <= r && now[pr].B > t.B) {
      add(now[pr].C, dp[now[pr].id] + 1);
      ++pr;
    }
    dp[t.id] = max(dp[t.id], qry(t.C - 1));
  }
  while (--pr > mid) clr(now[pr].C);
  work(l, mid, xl, xmid);
}
signed main() {
  scanf("%lld", &N);
  scanf("%lld/%lld %lld/%lld", &A, &B, &C, &D);
  vector<long long> lb, lc;
  for (long long i = 1, x, y; i <= N; ++i) {
    scanf("%lld %lld", &x, &y);
    long long p = x, q = y * B - x * A, r = y * D - x * C;
    now[i] = (node){p, q, r, i};
    lb.push_back(q);
    lc.push_back(r);
  }
  ++N;
  now[N].id = N;
  lb.push_back(0);
  lc.push_back(0);
  sort(lb.begin(), lb.end());
  lb.resize(unique(lb.begin(), lb.end()) - lb.begin());
  sort(lc.begin(), lc.end());
  lc.resize(unique(lc.begin(), lc.end()) - lc.begin());
  for (long long i = 1; i <= N; ++i) {
    now[i].B = lower_bound(lb.begin(), lb.end(), now[i].B) - lb.begin() + 1;
    now[i].C = lower_bound(lc.begin(), lc.end(), now[i].C) - lc.begin() + 1;
  }
  for (long long i = 1; i <= N; ++i) dp[i] = 1;
  sort(now + 1, now + N + 1, [&](node p, node q) { return p.A < q.A; });
  work(1, N, 0, 1e5);
  cout << dp[N] - 1;
  return 0;
}
