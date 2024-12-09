#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2005, Maxm = 200010, Mo = 1000000007, oo = INT_MAX;
struct Edge {
  int u, v;
};
typedef int IArr[Maxn];
IArr use, ans, cnt, rge, x, y, mp[Maxn];
int T, i, j, k, n, l, r;
vector<pair<pair<int, int>, int> > G;
bool check(int k) {
  memset((use), 0, sizeof((use)));
  for (i = 1; i <= n; i++) rge[i] = n;
  y[0] = oo;
  int lim = n;
  for (i = 1; i <= n; i++) {
    int now = 0;
    for (j = 1; j <= n; j++)
      if (!use[j] && rge[j] <= lim && y[j] < y[now]) now = j;
    ans[i] = now;
    use[now] = 1;
    for (j = 1; j <= n; j++)
      if (!use[j] && mp[now][j]) rge[j] = min(rge[j], i + k);
    memset((cnt), 0, sizeof((cnt)));
    for (j = 1; j <= n; j++)
      if (!use[j]) cnt[rge[j]]++;
    lim = n;
    for (j = i + 1; j <= n; j++) cnt[j] += cnt[j - 1];
    for (j = n; j >= i + 1; j--) {
      if (cnt[j] > j - i) return 0;
      if (cnt[j] == j - i) lim = j;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i != j) mp[i][j] = (x[j] <= y[i] && y[j] >= x[i]);
  l = 0;
  r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  check(l);
  for (i = 1; i <= n; i++) cout << ans[i] << ' ';
}
