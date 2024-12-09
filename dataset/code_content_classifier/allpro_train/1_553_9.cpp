#include <bits/stdc++.h>
using namespace std;
long long distance(pair<long long, long long> &p1,
                   pair<long long, long long> &p2) {
  long long xdiff = p1.first - p2.first;
  long long ydiff = p1.second - p2.second;
  return (xdiff * xdiff + ydiff * ydiff);
}
long long check(pair<long long, long long> &p1, pair<long long, long long> &p2,
                pair<long long, long long> &p3,
                pair<long long, long long> &p4) {
  map<long long, long long> m;
  m[distance(p1, p2)]++;
  m[distance(p1, p3)]++;
  m[distance(p1, p4)]++;
  m[distance(p2, p3)]++;
  m[distance(p2, p4)]++;
  m[distance(p3, p4)]++;
  long long len = m.begin()->first;
  if (m[len] == 4 && m[len * 2] == 2) return 1;
  return 0;
}
vector<pair<long long, long long> > get_loc(pair<long long, long long> &p1,
                                            pair<long long, long long> &p2) {
  vector<pair<long long, long long> > store;
  pair<long long, long long> d = {p1.first - p2.first, p1.second - p2.second};
  for (long long i = 1; i <= 4; i++) {
    store.push_back({p2.first + d.first, p2.second + d.second});
    swap(d.first, d.second);
    d.first *= -1;
  }
  return store;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  for (long long z = 1; z <= n; z++) {
    pair<long long, long long> mo[5], re[5];
    for (long long i = 1; i <= 4; i++) {
      cin >> mo[i].first >> mo[i].second >> re[i].first >> re[i].second;
    }
    vector<pair<long long, long long> > pt[5];
    for (long long i = 1; i <= 4; i++) {
      vector<pair<long long, long long> > pts = get_loc(mo[i], re[i]);
      for (auto it : pts) pt[i].push_back(it);
    }
    long long ans = 1000;
    for (long long a = 0; a <= 3; a++) {
      for (long long b = 0; b <= 3; b++) {
        for (long long c = 0; c <= 3; c++) {
          for (long long d = 0; d <= 3; d++) {
            if (check(pt[1][a], pt[2][b], pt[3][c], pt[4][d])) {
              ans = min(ans, a + b + c + d);
            }
          }
        }
      }
    }
    if (ans < 1000)
      cout << ans << "\n";
    else
      cout << "-1"
           << "\n";
  }
  return 0;
}
