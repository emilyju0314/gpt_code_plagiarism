#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int K = 1e6 + 5;
int a[K] = {};
void add(int i, int v) {
  for (; i < K; i += i & -i) a[i] += v;
}
int qry(int i) {
  int ret = 0;
  while (i) {
    ret += a[i];
    i -= i & -i;
  }
  return ret;
}
int n, m;
int ans[N];
vector<int> ranges[K];
vector<pair<int, int> > q[K];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    ranges[r].push_back(l);
  }
  for (int i = 0; i < m; i++) {
    int sz;
    cin >> sz;
    int lft = 1;
    while (sz--) {
      int rt;
      cin >> rt;
      if (lft < rt) q[rt].push_back(make_pair(lft, i));
      lft = rt + 1;
    }
    q[K - 1].push_back(make_pair(lft, i));
  }
  for (int i = 1; i < K; i++) {
    for (auto p : q[i]) {
      int lft = p.first, idx = p.second;
      ans[idx] += qry(i) - qry(lft - 1);
    }
    for (auto x : ranges[i]) add(x, 1);
  }
  for (int i = 0; i < m; i++) cout << n - ans[i] << '\n';
}
