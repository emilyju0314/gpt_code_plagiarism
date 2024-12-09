#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x, y, t1, t2, t, flag = 0;
  cin >> n >> m;
  long long int a[n + 1], group[n + 1], cnt = n, w, mn = 1000000000001;
  long long int cost = 0;
  vector<pair<long long int, vector<long long int> > > grp(n + 1);
  vector<pair<long long int, pair<long long int, long long int> > > v(m + 1);
  vector<long long int> temp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    group[i] = i;
    mn = min(mn, a[i]);
    temp.push_back(i);
    grp[i] = make_pair(a[i], temp);
    temp.clear();
  }
  t = mn;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> w;
    v[i] = (make_pair(w, make_pair(x, y)));
    flag = 1;
  }
  if (flag) sort(v.begin(), v.end());
  for (int i = 1; i <= m; i++) {
    x = v[i].second.first, y = v[i].second.second, w = v[i].first;
    if (t + grp[group[x]].first + grp[group[y]].first >
        w + min(grp[group[x]].first, grp[group[y]].first)) {
      if (group[x] != group[y]) {
        cost += w;
        t1 = group[x], t2 = group[y];
        if (grp[t2].first > grp[t1].first) {
          mn = grp[t1].first;
          for (int j = 0; j < grp[t2].second.size(); j++) {
            grp[t1].second.push_back(grp[t2].second[j]);
            group[grp[t2].second[j]] = t1;
            mn = min(mn, a[grp[t2].second[j]]);
          }
          grp[t1].first = mn;
          grp[t2].first = 0;
          cnt--;
          grp[t2].second.clear();
        } else {
          mn = grp[t2].first;
          for (int j = 0; j < grp[t1].second.size(); j++) {
            grp[t2].second.push_back(grp[t1].second[j]);
            group[grp[t1].second[j]] = t2;
            mn = min(mn, a[grp[t1].second[j]]);
          }
          grp[t2].first = mn;
          grp[t1].first = 0;
          cnt--;
          grp[t1].second.clear();
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cost += grp[i].first;
  }
  cost += (cnt - 2) * t;
  cout << cost;
}
