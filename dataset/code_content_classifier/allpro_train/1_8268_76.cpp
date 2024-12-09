#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], to[N];
vector<int> idx[N];
int is[N];
bool ok() {
  for (int i = 0; i < n; ++i) is[a[i]] ^= 1;
  bool prv = 0;
  for (int i = 1; i <= n; ++i) {
    if (!is[i]) continue;
    if (prv) return 0;
    prv = 1;
  }
  return 1;
}
bool plind() {
  for (int i = 0; i * 2 + 1 < n; ++i)
    if (a[i] != a[n - i - 1]) return 0;
  return 1;
}
bool vis[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    idx[a[i]].push_back(i);
  }
  if (!ok()) return cout << 0, 0;
  if (plind()) return cout << 1ll * n * (n + 1) / 2, 0;
  int indx = n / 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j * 2 + 1 < idx[i].size(); ++j) {
      to[idx[i][j]] = idx[i][idx[i].size() - j - 1];
      to[idx[i][idx[i].size() - j - 1]] = idx[i][j];
    }
    if (idx[i].size() % 2 == 0) continue;
    indx = idx[i][idx[i].size() / 2];
    to[idx[i][idx[i].size() / 2]] = n / 2;
  }
  for (int i = 0; i < n; ++i)
    if (to[i] == n - i - 1) vis[i] = 1;
  int prel = 0;
  while (a[prel] == a[n - prel - 1]) ++prel;
  int prer = prel;
  if (n % 2 && indx != n / 2) prer = max(prer, indx);
  if (n % 2 && indx == n / 2) vis[n / 2] = 1;
  for (int i = n - 1; i >= 0; --i)
    if (to[i] >= 0 && !vis[i]) {
      prer = max(prer, to[i]);
      vis[to[i]] = 1;
    }
  long long ans = 1ll * (prel + 1) * (n - prer);
  int sufr = n - 1;
  while (a[sufr] == a[n - sufr - 1]) --sufr;
  int sufl = sufr;
  if (n % 2 && indx != n / 2) sufl = min(sufl, indx);
  memset(vis, 0, sizeof vis);
  if (n % 2 && indx == n / 2) vis[n / 2] = 1;
  for (int i = 0; i < n; ++i)
    if (to[i] == n - i - 1) vis[i] = 1;
  for (int i = 0; i < n; ++i)
    if (to[i] >= 0 && !vis[i]) {
      sufl = min(sufl, to[i]);
      vis[to[i]] = 1;
    }
  if (sufl <= prel) return cout << ans, 0;
  ans += 1ll * (n - sufr) * (sufl - prel);
  cout << ans;
  return 0;
}
