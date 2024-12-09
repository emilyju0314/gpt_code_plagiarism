#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int BIT[N];
void add(int idx) {
  ++idx;
  while (idx < N) {
    BIT[idx] += 1;
    idx += idx & -idx;
  }
}
int get(int idx) {
  ++idx;
  int ret = 0;
  while (idx) {
    ret += BIT[idx];
    idx -= idx & -idx;
  }
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  vector<pair<int, int> > vals;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    vals.push_back({-v[i], i});
  }
  int q;
  scanf("%d", &q);
  vector<vector<pair<int, int> > > at(n + 1);
  for (int i = 0; i < q; ++i) {
    int k, pos;
    scanf("%d%d", &k, &pos);
    at[k].push_back({pos, i});
  }
  vector<int> res(q);
  sort(vals.begin(), vals.end());
  for (int k = 1; k <= n; ++k) {
    add(vals[k - 1].second);
    for (auto q : at[k]) {
      int l = 0, r = n - 1, m, At;
      while (l <= r) {
        m = (l + r) / 2;
        int ret = get(m);
        if (ret >= q.first) {
          r = m - 1;
          At = m;
        } else
          l = m + 1;
      }
      res[q.second] = v[At];
    }
  }
  for (int i = 0; i < q; ++i) printf("%d\n", res[i]);
  return 0;
}
