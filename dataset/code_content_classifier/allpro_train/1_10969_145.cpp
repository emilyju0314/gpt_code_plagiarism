#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v[200005];
long long wt[200005];
int n;
void djkshtra() {
  set<pair<long long, int> > s;
  for (long long i = 1; i < n + 1; i++) {
    s.insert(make_pair(wt[i], i));
  }
  while (!s.empty()) {
    pair<long long, int> p;
    p = *(s.begin());
    s.erase(s.begin());
    long long xx;
    int yy;
    xx = p.first;
    yy = p.second;
    for (int i = 0; i < v[yy].size(); i++) {
      int zz = v[yy][i].first;
      long long dis = v[yy][i].second;
      if (wt[zz] > dis + wt[yy]) {
        s.erase(s.find(make_pair(wt[zz], zz)));
        wt[zz] = dis + wt[yy];
        s.insert(make_pair(wt[zz], zz));
      }
    }
  }
}
int main() {
  cin >> n;
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    long long w;
    cin >> x >> y >> w;
    v[x].push_back(make_pair(y, 2 * w));
    v[y].push_back(make_pair(x, 2 * w));
  }
  for (long long i = 1; i < n + 1; i++) {
    cin >> wt[i];
  }
  djkshtra();
  for (long long i = 1; i < n + 1; i++) {
    cout << wt[i] << " ";
  }
}
