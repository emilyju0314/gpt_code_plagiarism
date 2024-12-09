#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long bit[maxn];
void update(long long idx, long long v) {
  while (idx <= maxn) {
    bit[idx] += v;
    idx += idx & -idx;
  }
}
long long query(long long idx) {
  long long ans = 0;
  while (idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}
long long inter(long long l, long long r) { return query(r) - query(l - 1); }
void solve() {
  long long n, m;
  cin >> n >> m;
  memset(bit, 0, sizeof bit);
  vector<pair<long long, pair<long long, long long> > > hor(n), vert(m);
  vector<pair<long long, pair<long long, long long> > > ord;
  vector<long long> xcomp, ycomp;
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    cin >> hor[i].first >> hor[i].second.first >> hor[i].second.second;
    if ((hor[i].second.first + hor[i].second.second) == 1e6) ans++;
    xcomp.push_back(hor[i].second.first);
    xcomp.push_back(hor[i].second.second);
    ycomp.push_back(hor[i].first);
  }
  for (long long i = 0; i < m; i++) {
    cin >> vert[i].first >> vert[i].second.first >> vert[i].second.second;
    if ((vert[i].second.first + vert[i].second.second) == 1e6) ans++;
    ycomp.push_back(vert[i].second.first);
    ycomp.push_back(vert[i].second.second);
    xcomp.push_back(vert[i].first);
  }
  sort(xcomp.begin(), xcomp.end());
  sort(ycomp.begin(), ycomp.end());
  for (long long i = 0; i < m; i++) {
    vert[i].first = lower_bound(xcomp.begin(), xcomp.end(), vert[i].first) -
                    xcomp.begin() + 1;
    vert[i].second.first =
        lower_bound(ycomp.begin(), ycomp.end(), vert[i].second.first) -
        ycomp.begin() + 1;
    vert[i].second.second =
        lower_bound(ycomp.begin(), ycomp.end(), vert[i].second.second) -
        ycomp.begin() + 1;
  }
  for (long long i = 0; i < n; i++) {
    hor[i].first = lower_bound(ycomp.begin(), ycomp.end(), hor[i].first) -
                   ycomp.begin() + 1;
    hor[i].second.first =
        lower_bound(xcomp.begin(), xcomp.end(), hor[i].second.first) -
        xcomp.begin() + 1;
    hor[i].second.second =
        lower_bound(xcomp.begin(), xcomp.end(), hor[i].second.second) -
        xcomp.begin() + 1;
  }
  for (long long i = 0; i < (long long)vert.size(); i++) {
    ord.push_back({vert[i].first, {1, i}});
  }
  for (long long i = 0; i < (long long)hor.size(); i++) {
    ord.push_back({hor[i].second.first, {0, i}});
    ord.push_back({hor[i].second.second, {2, i}});
  }
  sort(ord.begin(), ord.end());
  for (long long i = 0; i < (long long)ord.size(); i++) {
    long long x = ord[i].first;
    long long tipo = ord[i].second.first;
    long long ind = ord[i].second.second;
    if (tipo == 1) {
      long long y1 = vert[ind].second.first;
      long long y2 = vert[ind].second.second;
      ans += inter(y1, y2);
    } else {
      long long y = hor[ind].first;
      if (tipo == 2)
        update(y, -1);
      else
        update(y, 1);
    }
  }
  cout << ans << endl;
}
int32_t main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long tc = 1;
  while (tc--) solve();
}
