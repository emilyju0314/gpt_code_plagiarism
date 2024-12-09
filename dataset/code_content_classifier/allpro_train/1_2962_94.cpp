#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 100, OO = 1e12 + 100, M = 1e9 + 7, P = 6151, SQ = 100,
                lg = 21;
long long pr[N];
long long find_pr(long long x) {
  return (x == pr[x] ? x : (pr[x] = find_pr(pr[x])));
}
bool mrg(long long x, long long y) {
  x = find_pr(x);
  y = find_pr(y);
  if (x == y) return false;
  pr[x] = y;
  return true;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) pr[i] = i;
  if (n % 2 == 0) return cout << -1, 0;
  vector<pair<pair<long long, long long>, long long> > vg, vs, vm;
  long long cnt = 0;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'S') {
      cnt += mrg(x, y);
      vs.push_back({{x, y}, i});
    } else
      vm.push_back({{x, y}, i});
  }
  long long cnh = 0;
  for (auto u : vm) {
    if (mrg(u.first.first, u.first.second)) {
      cnh++, cnt++;
      vg.push_back(u);
    }
  }
  if (cnh > (n / 2) || cnt != n - 1) return cout << -1, 0;
  for (long long i = 1; i <= n; i++) pr[i] = i;
  cnt = n / 2;
  for (auto u : vg) cnt -= mrg(u.first.first, u.first.second);
  for (auto u : vm) {
    if (!cnt) break;
    if (mrg(u.first.first, u.first.second)) {
      cnt--;
      vg.push_back(u);
    }
  }
  if (cnt) return cout << -1, 0;
  for (auto u : vs)
    if (mrg(u.first.first, u.first.second)) vg.push_back(u);
  cout << n - 1 << endl;
  for (auto u : vg) cout << u.second + 1 << " ";
  return 0;
}
