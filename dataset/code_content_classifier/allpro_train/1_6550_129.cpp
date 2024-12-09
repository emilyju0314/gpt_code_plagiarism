#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n, m;
vector<int> g[N];
void eadd(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
int t = 0;
long long int mx[N];
long long int psum[N];
int dt[N], lw[N];
stack<int> stk;
void dfs(int u, int p = -1) {
  dt[u] = lw[u] = ++t;
  stk.push(u);
  for (int v : g[u])
    if (!dt[v]) {
      dfs(v, u);
      lw[u] = min(lw[u], lw[v]);
    } else if (v != p)
      lw[u] = min(lw[u], dt[v]);
  if (lw[u] == dt[u]) {
    if (u == stk.top()) {
      stk.pop();
      return;
    }
    int cmn = u, cmx = u, i = u;
    do {
      i = stk.top();
      stk.pop();
      cmn = min(cmn, i);
      cmx = max(cmx, i);
    } while (i != u);
    mx[cmn] = cmx - 1;
  }
}
void print(string s, long long int val) {
  cout << '[' << s << ": " << val << ']';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    eadd(u, v);
  }
  fill(mx, mx + n + 1, n);
  for (int i = 1; i <= n; ++i)
    if (!dt[i]) dfs(i);
  for (int i = n - 1; i; --i) mx[i] = min(mx[i], mx[i + 1]);
  for (int i = 1; i <= n; ++i) psum[i] = psum[i - 1] + mx[i];
  int q;
  cin >> q;
  while (q--) {
    long long int l, r;
    cin >> l >> r;
    long long int t1 = (r * (r + 1ll) - (l - 1) * l) >> 1, t2 = r - l + 1ll,
                  t01 = 0, t02 = 0;
    long long int k = upper_bound(mx + l, mx + r + 1, r) - mx;
    --k;
    if (k >= l) t01 = (psum[k] - psum[l - 1]);
    ++k;
    if (k <= r) t02 = (r - k + 1ll) * r;
    cout << t01 + t02 - t1 + t2 << '\n';
  }
  return 0;
}
