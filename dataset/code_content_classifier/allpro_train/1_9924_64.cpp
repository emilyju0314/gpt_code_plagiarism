#include <bits/stdc++.h>
using namespace std;
const string NAME = "vd";
int td[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, tc[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int n, m, k, t[2005], c[2005];
vector<vector<pair<pair<int, int>, long long> > > a;
long long fwt[2005][2005];
void upd(int x, int y, long long v) {
  int y1 = y;
  for (; x <= n; x += x & -x) {
    y = y1;
    for (; y <= m; y += y & -y) {
      fwt[x][y] += v;
    }
  }
}
long long get(int x, int y) {
  long long s = 0;
  int y1 = y;
  for (; x > 0; x -= x & -x) {
    y = y1;
    for (; y > 0; y -= y & -y) {
      s += fwt[x][y];
    }
  }
  return s;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  a.resize(k + 1);
  int l;
  for (int j = 1; j <= k; ++j) {
    t[j] = 1;
    scanf("%d", &l);
    for (int i = 1; i <= l; ++i) {
      int x, y;
      long long v;
      scanf("%d %d %lld", &x, &y, &v);
      a[j].push_back(make_pair(make_pair(x, y), v));
    }
  }
  scanf("%d", &l);
  for (int i = 1; i <= l; ++i) {
    char s[5];
    int x1, y1, x2, y2;
    scanf("%s", &s);
    if (s[0] == 'A') {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      for (int j = 1; j <= k; ++j) {
        if (t[j]) {
          for (auto z : a[j])
            upd(z.first.first, z.first.second, z.second * ((!c[j]) ? 1 : -1));
          t[j] = 1 - t[j];
          c[j] = 1 - c[j];
        }
      }
      printf("%lld\n", get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) +
                           get(x1 - 1, y1 - 1));
    } else {
      scanf("%d", &x1);
      t[x1] = 1 - t[x1];
    }
  }
  return 0;
}
