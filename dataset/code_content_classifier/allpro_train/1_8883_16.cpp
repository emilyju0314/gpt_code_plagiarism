#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e3 + 2;
const int mod = 1e9 + 7;
int n, a, b, dfst, colcnt, ans;
int dfn[maxN], low[maxN], col[maxN], minn[maxN], maxx[maxN];
int gcd[maxN], cnt[maxN];
int fac[maxN];
stack<int> stk;
vector<int> G[maxN];
vector<bool> tmp, F[maxN];
string S[maxN];
inline bool Chkmin(int& x, int y) { return x > y ? x = y, true : false; }
inline void Mod(int& x) { x >= mod ? x -= mod : 0; }
inline int GCD(int x, int y) {
  while (y) std::swap(x, y), y %= x;
  return x;
}
inline int Qpow(int a, int n) {
  if (a == 1) return 1;
  if (n == -1) return Qpow(a, mod - 2);
  int res = 1;
  while (n) {
    if (n & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return res;
}
void Tarjan(int u) {
  dfn[u] = low[u] = ++dfst;
  stk.push(u);
  for (int v : G[u]) {
    if (!dfn[v])
      Tarjan(v), Chkmin(low[u], low[v]);
    else if (!col[v])
      Chkmin(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    ++colcnt;
    col[u] = colcnt, gcd[colcnt] = S[u].size();
    while (stk.top() != u) {
      int v = stk.top();
      stk.pop();
      col[v] = colcnt, gcd[colcnt] = GCD(gcd[colcnt], S[v].size());
    }
    stk.pop();
  }
}
inline int C(int n, int m) {
  return (long long)fac[n] * Qpow(fac[m], -1) % mod * Qpow(fac[n - m], -1) %
         mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> S[1];
    for (int j = 1; j <= n; ++j)
      if (S[1][j - 1] == '1') G[i].push_back(j);
  }
  for (int i = 1; i <= n; ++i) {
    int sth;
    cin >> sth >> S[i];
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) Tarjan(i);
  for (int i = 1; i <= colcnt; ++i) F[i].resize(gcd[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < S[i].size(); ++j)
      if (S[i][j] == '1') ++minn[i], F[col[i]][j % gcd[col[i]]] = true;
  for (int i = colcnt; i > 1; --i) {
    int curr = GCD(gcd[i], gcd[i - 1]);
    tmp.clear(), tmp.resize(curr);
    for (int j = 0; j < gcd[i]; ++j)
      if (F[i][j]) tmp[j % curr] = true;
    for (int j = 0; j < gcd[i - 1]; ++j)
      if (tmp[j % curr]) F[i - 1][j] = true;
  }
  for (int i = 1; i <= colcnt; ++i)
    for (int j = 0; j < gcd[i]; ++j) cnt[i] += F[i][j];
  for (int i = 1; i <= n; ++i)
    maxx[i] = S[i].size() / gcd[col[i]] * cnt[col[i]];
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 1; i <= n; ++i) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (minn[j] > maxx[i])
        ++cnt1;
      else if (maxx[j] > maxx[i] or (maxx[j] == maxx[i] and j < i))
        ++cnt2;
    }
    if (cnt1 >= a) continue;
    for (int x = min(b - 1, min(cnt2, a - 1 - cnt1));
         x + cnt1 + 1 >= b and x >= 0; --x)
      Mod(ans += (long long)C(cnt1, b - x - 1) * C(cnt2, x) % mod);
  }
  cout << ans << endl;
  return 0;
}
