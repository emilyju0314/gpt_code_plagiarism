#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
char s[N], t[N], S[N];
int n, ch[N][26], fa[N];
int len[N], anc[N], dif[N], nd, la;
int ans[N], _ans[N], from[N];
void extend(int n) {
  int c = S[n], p = la;
  for (; S[n - len[p] - 1] != c; p = fa[p])
    ;
  if (!ch[p][c - 'a']) {
    len[++nd] = len[p] + 2;
    int q = fa[p];
    for (; S[n - len[q] - 1] != c; q = fa[q])
      ;
    fa[nd] = ch[q][c - 'a'];
    ch[p][c - 'a'] = nd;
    dif[nd] = len[nd] - len[fa[nd]];
    anc[nd] = (dif[nd] == dif[fa[nd]] ? anc[fa[nd]] : fa[nd]);
  }
  la = ch[p][c - 'a'];
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  for (int i = (int)(1); i <= (int)(n); i++)
    S[i * 2 - 1] = s[i], S[i * 2] = t[i];
  fa[0] = nd = 1;
  len[1] = -1;
  n *= 2;
  for (int i = (int)(1); i <= (int)(n); i++) ans[i] = 1 << 30;
  _ans[0] = 1;
  for (int i = (int)(1); i <= (int)(n); i++) {
    extend(i);
    for (int p = la; p; p = anc[p]) {
      _ans[p] = i - (len[anc[p]] + dif[p]);
      if (dif[fa[p]] == dif[p])
        if (ans[_ans[p]] > ans[_ans[fa[p]]]) _ans[p] = _ans[fa[p]];
      if (!(i & 1) && ans[i] > ans[_ans[p]] + 1)
        ans[i] = ans[_ans[p]] + 1, from[i] = _ans[p];
    }
    if (!(i & 1) && S[i - 1] == S[i] && ans[i] > ans[i - 2])
      ans[i] = ans[i - 2], from[i] = i - 2;
  }
  if (ans[n] > 1e9) return puts("-1"), 0;
  printf("%d\n", ans[n]);
  for (int i = n; i; i = from[i])
    if (i - from[i] > 2) printf("%d %d\n", from[i] / 2 + 1, i / 2);
}
