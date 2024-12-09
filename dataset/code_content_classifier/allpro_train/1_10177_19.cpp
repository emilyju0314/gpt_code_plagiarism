#include <bits/stdc++.h>
using namespace std;
inline bool left(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
  return (b.first - a.first) * 1LL * (c.second - a.second) -
             (c.first - a.first) * 1LL * (b.second - a.second) <=
         0;
}
inline void add_point(vector<pair<int, int> >& hull, pair<int, int> pt,
                      int limit) {
  while (hull.size() > limit &&
         left(hull[hull.size() - 2], hull[hull.size() - 1], pt))
    hull.pop_back();
  hull.push_back(pt);
}
long long int cpr(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
  return (b.first - a.first) * 1LL * (c.second - a.second) -
         (c.first - a.first) * 1LL * (b.second - a.second);
}
int main() {
  int(n), (m);
  scanf("%d%d", &(n), &(m));
  ;
  int(x), (y);
  scanf("%d%d", &(x), &(y));
  ;
  vector<pair<int, int> > v1, v2;
  for (int i = (0); i < (n); ++i) {
    int(a), (b);
    scanf("%d%d", &(a), &(b));
    ;
    v1.push_back(make_pair(a, b));
  }
  int m1 = 0, m2 = 0;
  for (int j = (0); j < (m); ++j) {
    int(c), (d);
    scanf("%d%d", &(c), &(d));
    ;
    v2.push_back(make_pair(c, d));
    m1 = max(c, m1);
    m2 = max(d, m2);
  }
  v2.push_back(make_pair(m1, 0));
  v2.push_back(make_pair(0, m2));
  v2.push_back(make_pair(0, 0));
  sort((v2).begin(), (v2).end());
  v2.resize(unique((v2).begin(), (v2).end()) - v2.begin());
  vector<pair<int, int> > hull;
  if (v2.size() > 1) {
    for (int i = (0); i < (v2.size()); ++i) add_point(hull, v2[i], 1);
    int cursize = hull.size();
    for (int i = (v2.size() - 1); i >= (0); --i)
      add_point(hull, v2[i], cursize);
    hull.pop_back();
  } else
    hull = v2;
  sort((hull).begin(), (hull).end());
  sort((v1).begin(), (v1).end());
  int j = 0;
  bool ans = true;
  swap(hull[hull.size() - 1], hull[hull.size() - 2]);
  for (int i = (0); i < (v1.size()); ++i) {
    if (v1[i] >= hull.back()) {
      printf("Max\n");
      return 0;
    }
    while (v1[i] > hull[j + 1]) j++;
    if (cpr(hull[j], hull[j + 1], v1[i]) >= 0) {
      {
        cerr << "cpr(hull[j], hull[j + 1], v1[i])"
             << " = " << cpr(hull[j], hull[j + 1], v1[i]) << endl;
      };
      printf("Max\n");
      return 0;
    }
  }
  printf("Min\n");
}
