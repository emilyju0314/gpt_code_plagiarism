#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int N = 100005;
vector<int> e[N];
int cnt[202];
int each[N];
int n, l, d;
int ans;
int sum;
vector<int> all;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    l = a[i];
    d = b[i];
    if (!e[l].size()) {
      all.push_back(l);
    }
    e[l].push_back(d);
    sum += d;
    each[l] += d;
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    if (all.size() == 1) {
      cout << 0 << endl;
      return 0;
    }
    cout << min(e[all[0]][0], e[all[1]][0]) << endl;
    return 0;
  }
  ans = n * 200;
  int idx = -1;
  int foo = 0;
  int cur = 0;
  int mx = -1;
  sort(all.begin(), all.end());
  for (int i = 0; i < all.size(); i++) {
    foo = 0;
    idx = all[i];
    cur += e[idx].size();
    sum -= each[idx];
    foo = sum;
    mx = (int)e[idx].size() * 2;
    mx--;
    if (cur > mx) {
      int df = cur - mx;
      for (int j = 0; j < 201; j++) {
        int mn = min(df, cnt[j]);
        foo += mn * j;
        df -= mn;
      }
    }
    ans = min(ans, foo);
    for (int j = 0; j < e[idx].size(); j++) {
      cnt[e[idx][j]]++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
