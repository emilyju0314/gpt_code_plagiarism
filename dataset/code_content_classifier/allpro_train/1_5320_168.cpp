#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10, skc = (1e9 + 7);
int len[N], tot, ls, tr[N][30], fail[N], sz[N][3], cnt[N];
string s[3];
vector<int> v[N];
void upd(int &x, int y) { x = (x + y) % skc; }
void ret(int &x) { x = (x % skc + skc) % skc; }
void ins(int x, int w) {
  int u = ++tot, p = ls;
  len[u] = len[ls] + 1;
  ls = u;
  for (; p && !tr[p][x]; p = fail[p]) tr[p][x] = u;
  if (!p)
    fail[u] = 1;
  else {
    int q = tr[p][x];
    if (len[q] == len[p] + 1)
      fail[u] = q;
    else {
      int cq = ++tot;
      len[cq] = len[p] + 1;
      fail[cq] = fail[q];
      fail[q] = fail[u] = cq;
      memcpy(tr[cq], tr[q], sizeof(tr[q]));
      for (; p && tr[p][x] == q; p = fail[p]) tr[p][x] = cq;
    }
  }
  sz[u][w]++;
}
void dfs(int x) {
  int l = v[x].size(), y;
  for (register int i = (0); i <= (l - 1); ++i) {
    y = v[x][i];
    dfs(y);
    upd(sz[x][0], sz[y][0]);
    upd(sz[x][1], sz[y][1]);
    upd(sz[x][2], sz[y][2]);
  }
  upd(cnt[len[fail[x]] + 1], 1ll * sz[x][0] * sz[x][1] % skc * sz[x][2] % skc);
  upd(cnt[len[x] + 1], -1ll * sz[x][0] * sz[x][1] % skc * sz[x][2] % skc);
  ret(cnt[len[x] + 1]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nw, _l = 1e9;
  tot = 1;
  for (register int i = (0); i <= (2); ++i) {
    cin >> s[i];
    int l = s[i].length();
    ls = 1;
    for (register int j = (1); j <= (l); ++j) ins(s[i][j - 1] - 'a', i);
    _l = min(_l, l);
  }
  for (register int i = (1); i <= (tot); ++i) v[fail[i]].push_back(i);
  dfs(1);
  for (register int i = (1); i <= (_l); ++i)
    upd(cnt[i], cnt[i - 1]), cout << cnt[i] << ' ';
  cout << '\n';
  return 0;
}
