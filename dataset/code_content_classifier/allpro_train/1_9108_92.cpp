#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, u, v, root = 0, leaf = 0, order1 = 0, flag = 1;
vector<vector<int>> t;
int dfs(int v, int p) {
  bool is_order1 = 0, odd = 0, even = 0;
  int val = 1, mval = 1;
  for (auto b : t[v]) {
    if (b == p) continue;
    if ((int)(t[b]).size() == 1) {
      leaf++;
      is_order1 = 1;
      val = 1;
      odd = 1;
      continue;
    }
    val = dfs(b, v);
    if ((val & 1))
      odd = 1;
    else
      even = 1;
    mval = max(val, mval);
  }
  if (is_order1) order1++;
  if ((odd) && (even)) flag = 0;
  return mval + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  t.resize(n);
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    --u;
    --v;
    t[u].push_back(v);
    t[v].push_back(u);
    if ((int)(t[u]).size() > (int)(t[root]).size()) root = u;
    if ((int)(t[v]).size() > (int)(t[root]).size()) root = v;
  }
  dfs(root, -1);
  int fmx = n - 1 - leaf + order1;
  int fmn = flag ? 1 : 3;
  cout << fmn << ' ' << fmx << '\n';
  return 0;
}
