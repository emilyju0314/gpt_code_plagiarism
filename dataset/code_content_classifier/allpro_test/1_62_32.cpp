#include <bits/stdc++.h>
using namespace std;
long long n, m, qq, w, h, sum, p, q;
bool vis[4105][4105];
pair<long long, long long> te;
set<long long> s[4105];
long long get(long long h, long long w, long long tag) {
  long long sum = 0;
  if (tag == 1) {
    sum += 2050;
  }
  if (h != 1)
    sum += 1020 + h;
  else if (w != 1)
    sum += w;
  return sum;
}
pair<long long, long long> hd(long long h, long long w, long long tag) {
  long long d = min(h - 1, w - 1);
  h -= d;
  w -= d;
  long long cnt = 2 * d;
  if (tag == 1 && h > 1) {
    cnt++;
    h--;
    tag = 2;
  } else if (tag == 2 && w > 1) {
    cnt++;
    w--;
    tag = 1;
  }
  return make_pair(get(h, w, tag), cnt + 1);
}
void ini(long long h, long long w, long long tag) {
  te = hd(h, w, tag);
  s[te.first].insert(te.second + 1);
  s[te.first].insert(0);
  sum += (te.second + 1) * te.second / 2;
}
void add(long long tag) {
  te = hd(h, w, tag);
  s[te.first].erase(te.second);
  p = *(s[te.first].upper_bound(te.second));
  q = *(prev(s[te.first].lower_bound(te.second)));
  sum += (te.second - q) * (p - te.second);
}
void del(long long tag) {
  te = hd(h, w, tag);
  p = *(s[te.first].upper_bound(te.second));
  q = *(prev(s[te.first].lower_bound(te.second)));
  sum -= (te.second - q) * (p - te.second);
  s[te.first].insert(te.second);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &qq);
  for (long long i = 1; i <= n; i++) {
    ini(i, m, 1);
  }
  for (long long j = 1; j <= m; j++) {
    ini(n, j, 2);
  }
  sum -= n * m;
  while (qq--) {
    scanf("%lld%lld", &h, &w);
    if (vis[h][w]) {
      add(1);
      add(2);
      sum--;
      vis[h][w] = 0;
    } else {
      del(1);
      del(2);
      sum++;
      vis[h][w] = 1;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
