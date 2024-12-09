#include <bits/stdc++.h>
using namespace std;
const long long N = 2010;
const long long INF = 1e15;
const pair<long long, long long> DEF = make_pair(INF, INF);
void umin(pair<long long, long long> &a, pair<long long, long long> b) {
  a = min(a, b);
};
void umax(pair<long long, long long> &a, pair<long long, long long> b) {
  a = max(a, b);
};
char ar[N][N];
pair<long long, long long> mn, mx;
bool check(const vector<pair<long long, long long> > &crd) {
  mn = crd[0];
  mx = crd[0];
  if (crd.size() == 1) return true;
  if (crd[0].second != crd[1].second && crd[0].first != crd[1].first)
    return false;
  bool XX = (crd[0].second == crd[1].second);
  for (auto &i : crd) {
    umin(mn, i);
    umax(mx, i);
    if (crd[0].second != i.second && XX) return false;
    if (crd[0].first != i.first && XX == false) return false;
  }
  pair<long long, long long> cur = mn;
  char need = ar[cur.first][cur.second];
  while (cur != mx) {
    if (ar[cur.first][cur.second] == '.' || ar[cur.first][cur.second] < need)
      return false;
    if (cur.second == mx.second)
      cur.first++;
    else
      cur.second++;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long> > > crd(26);
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) {
        cin >> ar[i][j];
        if (ar[i][j] != '.') crd[ar[i][j] - 'a'].push_back(make_pair(i, j));
      }
    vector<pair<pair<long long, long long>, pair<long long, long long> > > ans(
        26, make_pair(DEF, DEF));
    long long len = 25;
    for (long long i = 0; i < 26; i++) {
      if (crd[i].empty()) continue;
      if (check(crd[i]) == false) {
        cout << "NO\n";
        goto TTT;
      } else
        ans[i] = make_pair(mn, mx);
    }
    for (long long i = 25; i > 0; i--)
      if (ans[i - 1].first == DEF) ans[i - 1] = ans[i];
    for (; len >= 0 && ans[len].first == DEF; len--)
      ;
    cout << "YES\n" << len + 1 << '\n';
    for (long long i = 0; i < len + 1; i++)
      cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' '
           << ans[i].second.first + 1 << ' ' << ans[i].second.second + 1
           << '\n';
  TTT:;
  }
  return 0;
}
