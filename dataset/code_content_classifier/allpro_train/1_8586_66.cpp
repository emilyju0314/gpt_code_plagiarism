#include <bits/stdc++.h>
using namespace std;
const int N = 63;
const long long MAX = (1ll << 60), MOD = 998244353, INV_2 = 499122177;
int n, m;
vector<pair<long long, long long> > tot[2][N], sub[2][N], ans;
void dfs(long long l, long long r, long long L, long long R, int depth,
         int typ) {
  tot[typ][depth].push_back(pair<long long, long long>(l, r));
  if (L <= l && r <= R) {
    sub[typ][depth].push_back(pair<long long, long long>(l, r));
    return;
  }
  long long mid = (l + r) >> 1ll;
  if (L <= mid) dfs(l, mid, L, R, depth + 1, typ);
  if (R > mid) dfs(mid + 1, r, L, R, depth + 1, typ);
}
void modify(long long &sum, long long l, long long r) {
  long long t_sum = (l + r) % MOD * ((r - l + 1) % MOD) % MOD * INV_2 % MOD;
  sum += t_sum;
  if (sum >= MOD) sum -= MOD;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    dfs(0, MAX - 1, l, r, 1, 0);
  }
  scanf("%d", &m);
  for (int i = (1); i <= (m); ++i) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    dfs(0, MAX - 1, l, r, 1, 1);
  }
  ans.clear();
  for (int typ = (0); typ <= (1); ++typ)
    for (int i = (1); i <= (61); ++i)
      for (auto x : tot[typ][i])
        for (auto y : sub[!typ][i])
          ans.push_back(pair<long long, long long>(
              x.first ^ y.first, (x.first ^ y.first) + (x.second - x.first)));
  sort(ans.begin(), ans.end());
  long long sum = 0, cur = 0;
  for (auto x : ans) {
    cur = max(cur, x.first - 1);
    if (x.second > cur) modify(sum, cur + 1, x.second), cur = x.second;
  }
  printf("%lld\n", sum);
  return 0;
}
