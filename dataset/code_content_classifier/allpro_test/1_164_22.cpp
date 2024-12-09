#include <bits/stdc++.h>
using namespace std;
const long long N = 200010;
long long lt[N], rt[N], copyy[N], copyy1[N];
long long n, k;
char a[N];
string ans;
vector<long long> s1;
void dfs1(long long u) {
  if (lt[u]) dfs1(lt[u]);
  s1.push_back(u);
  if (rt[u]) dfs1(rt[u]);
}
void dfs2(long long u) {
  vector<long long> s2;
  if (!u) return;
  long long p = u;
  while (p && !copyy[p]) {
    s2.push_back(p);
    p = lt[p];
  }
  if (copyy[p] && s2.size() < k) {
    k -= s2.size() + 1;
    copyy1[p] = 1;
    dfs2(lt[p]), dfs2(rt[p]);
    while (s2.size()) {
      copyy1[s2.back()] = 1;
      dfs2(rt[s2.back()]);
      s2.pop_back();
    }
  }
}
void dfs3(long long u) {
  if (lt[u]) dfs3(lt[u]);
  ans += a[u];
  if (copyy1[u]) ans += a[u];
  if (rt[u]) dfs3(rt[u]);
}
void solve() {
  cin >> n >> k >> a + 1;
  for (long long i = 1; i <= n; i++) cin >> lt[i] >> rt[i];
  dfs1(1);
  for (long long i = n - 2; i >= 0; i--) {
    if (a[s1[i]] < a[s1[i + 1]])
      copyy[s1[i]] = 1;
    else if (a[s1[i]] > a[s1[i + 1]])
      continue;
    else if (copyy[s1[i + 1]])
      copyy[s1[i]] = 1;
  }
  dfs2(1);
  dfs3(1);
  cout << ans << endl;
}
signed main() {
  solve();
  return 0;
}
