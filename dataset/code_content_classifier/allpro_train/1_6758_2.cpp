#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
int add = 0;
signed main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  priority_queue<int, vector<int>, greater<int> > v;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int aa;
    cin >> aa;
    if (aa != 0) {
      v.push(aa);
    }
  }
  int tt = 0;
  while (k > 0 && !v.empty()) {
    k--;
    while (tt - add == 0) {
      if (v.size() == 0) break;
      tt = v.top();
      v.pop();
      if (tt - add > 0) break;
    }
    cout << tt - add << '\n';
    add += tt - add;
    if (v.size() == 0) break;
  }
  for (int i = 0; i < k; ++i) cout << 0 << '\n';
  return 0;
}
