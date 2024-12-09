#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int mxn = 400001;
int n, m;
int a[mxn], b[mxn], first[mxn], d[mxn], ff[mxn], dp[mxn], bt[mxn];
multiset<int, greater<int>> second;
void add(int x, int y) {
  for (; x <= 2 * n; x += x & -x) (bt[x] += y) %= mod;
}
int qry(int x) {
  int ret = 0;
  for (; x; x -= x & -x) (ret += bt[x]) %= mod;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i], first[i] = i;
  sort(first, first + n, [&](int x, int y) { return a[x] < a[y]; });
  cin >> m;
  for (int i = 0, x; i < m; i++) cin >> x, d[--x] = 1, second.insert(b[x]);
  for (int i = 0; i < n; i++) {
    int x = first[i];
    ff[x] = !second.empty() && b[x] <= *second.begin();
    if (d[x]) second.erase(second.find(b[x]));
  }
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    int x = first[i];
    add(b[x], dp[x] = (mod + ff[x] + qry(2 * n) - qry(b[x])) % mod);
    (ret += dp[x]) %= mod;
  }
  cout << ret << '\n';
  return 0;
}
