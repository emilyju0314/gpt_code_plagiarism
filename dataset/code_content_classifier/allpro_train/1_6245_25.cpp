#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 52;
const ll INF = 2e18;
int T, n, a[N], rt[N], rk[N];
ll k, gt[N], dp[N];
bool use[N];
int frt(int i) { return rt[i] == i ? i : rt[i] = frt(rt[i]); }
void join(int i, int j) {
  int x = frt(i), y = frt(j);
  if (rk[x] < rk[y]) swap(x, y);
  if (rk[x] == rk[y]) rk[x]++;
  rt[y] = x;
}
ll mul(ll x, ll y) {
  ll res = 0;
  while (y) {
    if (y & 1) res = min(INF, res + x);
    x = min(INF, x + x);
    y >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  gt[0] = 1;
  for (int i = (1); i <= (19); ++i) gt[i] = gt[i - 1] * i;
  for (int i = (20); i <= (50); ++i) gt[i] = INF;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = (1); i <= (n); ++i)
      rt[i] = i, rk[i] = 0, use[i] = 0, dp[i] = a[i] = 0;
    dp[n + 1] = 1;
    for (int i = (n); i >= (1); --i)
      for (int j = (i); j <= (n); ++j)
        dp[i] = min(INF, dp[i] + mul(dp[j + 1], gt[max(0, j - i - 1)]));
    for (int pos = (1); pos <= (n); ++pos) {
      for (int i = (pos); i <= (n); ++i) {
        int nn = i - pos + 1;
        if (k > mul(gt[max(0, nn - 2)], dp[i + 1]))
          k -= mul(gt[max(0, nn - 2)], dp[i + 1]);
        else {
          a[pos] = i;
          use[i] = 1;
          join(pos, i);
          for (int j = (pos + 1); j <= (i); ++j) {
            for (int l = (pos); l <= (i); ++l)
              if (!use[l] && l != j) {
                if (j == i) {
                  a[j] = l;
                  use[l] = 1;
                  break;
                }
                if (frt(j) != frt(l)) {
                  if (k <= mul(gt[max(0, nn - 2 - (j - pos))], dp[i + 1])) {
                    a[j] = l;
                    use[l] = 1;
                    join(j, l);
                    break;
                  } else
                    k -= mul(gt[max(0, nn - 2 - (j - pos))], dp[i + 1]);
                }
              }
          }
          pos = i;
          break;
        }
      }
    }
    for (int i = (1); i <= (n); ++i)
      if (a[i] == 0) k = 1e9;
    if (k > 1)
      cout << "-1\n";
    else
      for (int i = (1); i <= (n); ++i) cout << a[i] << " \n"[i == n];
  }
  return 0;
}
