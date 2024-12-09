#include <bits/stdc++.h>
int MOD = int(1e9) + 7;
inline int add(int a, int b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}
inline void inc(int &a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return (a - b < 0) ? (a - b + MOD) : (a - b); }
inline void dec(int &a, int b) { a = sub(a, b); }
inline int mul(int a, int b) { return (a * 1ll * b) % MOD; }
using namespace std;
const int N = 200000;
const int MAX = 2e5 + 9;
set<int> s[MAX];
int ar[MAX * 2], ans[MAX], mark[MAX], n, m, k, x;
multiset<pair<int, int> > qu;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) cin >> x, ar[m + x] = i, s[i].insert(x);
    qu.insert({s[i].size(), i});
  }
  while (qu.size()) {
    int k = (*qu.begin()).second;
    qu.erase(qu.begin());
    if (mark[k]) continue;
    mark[k] = 1;
    if (!s[k].size()) return cout << "NO", 0;
    int x = *s[k].begin();
    if (x > 0)
      ans[x] = 1;
    else
      ans[-x] = 0;
    int i = ar[m - x];
    if (i) s[i].erase(-x), qu.insert({s[i].size(), i});
  }
  cout << "YES\n";
  for (int i = 1; i <= m; i++) cout << ans[i];
  return 0;
}
