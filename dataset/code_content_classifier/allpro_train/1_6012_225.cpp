#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N];
int c[N], d[N], k[N];
int idx[N];
int idx2[N];
map<pair<int, int>, int> mp;
int ans[N];
int cmp(int x, int y) { return make_pair(a[x], b[x]) < make_pair(a[y], b[y]); }
int cmp2(int x, int y) { return make_pair(c[x], d[x]) < make_pair(c[y], d[y]); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
  }
  for (int i = 0; i < n; ++i) {
    idx[i] = i;
  }
  sort(idx, idx + n, cmp);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", c + i, d + i, k + i);
  }
  for (int i = 0; i < m; ++i) {
    idx2[i] = i;
  }
  sort(idx2, idx2 + m, cmp2);
  int jj = 0;
  int ff = 1;
  for (int ii = 0; ii < n; ++ii) {
    int i = idx[ii];
    for (; jj < m; ++jj) {
      int j = idx2[jj];
      if (c[j] <= a[i]) {
        mp[make_pair(d[j], j)] = k[j];
      } else
        break;
    }
    auto it = mp.lower_bound(make_pair(b[i], 0));
    if (it == mp.end()) {
      ff = 0;
      break;
    }
    it->second--;
    ans[i] = (it->first).second;
    if (it->second == 0) {
      mp.erase(it);
    }
  }
  if (!ff) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
    }
  }
  return 0;
}
