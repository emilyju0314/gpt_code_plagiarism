#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
vector<int> e[maxn];
pair<int, int> opt[maxn][2];
int f[maxn], s[maxn], nxt[maxn];
int n;
bool flag[maxn];
int flag2[maxn];
int que[maxn];
pair<int, int> res;
vector<pair<int, int> > info, _, __;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
void dp(int u) {
  nxt[u] = 0;
  opt[u][0] = opt[u][1] = make_pair(0, 0);
  pair<int, int> tmp = make_pair(0, 0);
  for (int v = 0; v < e[u].size(); v++) {
    dp(e[u][v]);
    tmp = tmp + opt[e[u][v]][0];
  }
  opt[u][1] = tmp;
  for (int v = 0; v < e[u].size(); v++) {
    pair<int, int> _tmp = tmp - opt[e[u][v]][0];
    _tmp = _tmp + opt[e[u][v]][1];
    _tmp = _tmp + make_pair(1, s[u] != s[e[u][v]]);
    if (_tmp > opt[u][0]) {
      opt[u][0] = _tmp;
      nxt[u] = e[u][v];
    }
  }
  if (opt[u][1] > opt[u][0]) {
    opt[u][0] = opt[u][1];
    nxt[u] = -1;
  }
}
void getinfo(int u, int v) {
  if (v == 0 && nxt[u] > 0) _.push_back(make_pair(u, nxt[u]));
  for (int w = 0; w < e[u].size(); w++)
    if (v == 1 || nxt[u] != e[u][w])
      getinfo(e[u][w], 0);
    else
      getinfo(e[u][w], 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &f[i], &s[i]);
  for (int i = 1; i <= n; i++)
    if (!flag2[i]) {
      flag2[i] = i;
      que[0] = i;
      for (int l = 0, r = 0; l <= r; l++) {
        if (!flag2[f[que[l]]]) {
          que[++r] = f[que[l]];
          flag2[que[r]] = i;
        } else if (flag2[f[que[l]]] != i)
          break;
        else {
          for (int k = r;; k--) {
            flag[que[k]] = 1;
            if (que[k] == f[que[l]]) break;
          }
          break;
        }
      }
    }
  for (int i = 1; i <= n; i++)
    if (!flag[i]) e[f[i]].push_back(i);
  for (int i = 1; i <= n; i++) flag2[i] = 0;
  for (int i = 1; i <= n; i++)
    if (flag[i] && !flag2[i]) {
      int cnt = 1;
      que[1] = i;
      que[2] = f[i];
      while (que[cnt + 1] != i) {
        cnt++;
        que[cnt + 1] = f[que[cnt]];
      }
      for (int j = 1; j <= cnt; j++) flag2[que[j]] = 1;
      pair<int, int> A, B;
      A = B = make_pair(0, 0);
      _.clear();
      for (int j = 4; j <= cnt; j++) e[que[j - 1]].push_back(que[j]);
      if (cnt > 2) {
        dp(que[3]);
        A = opt[que[3]][0];
        getinfo(que[3], 0);
      }
      for (int k = 1; k <= 2; k++)
        for (int j = 0; j < e[que[k]].size(); j++) {
          dp(e[que[k]][j]);
          A = A + opt[e[que[k]][j]][0];
          getinfo(e[que[k]][j], 0);
        }
      A = A + make_pair(1, s[que[1]] != s[que[2]]);
      _.push_back(make_pair(que[1], que[2]));
      B = A;
      __ = _;
      A = make_pair(0, 0);
      _.clear();
      if (cnt > 2) e[que[2]].push_back(que[3]);
      e[que[cnt]].push_back(que[1]);
      dp(que[2]);
      A = opt[que[2]][0];
      getinfo(que[2], 0);
      if (A < B) {
        swap(A, B);
        swap(_, __);
      }
      res = res + A;
      for (int j = 0; j < _.size(); j++) info.push_back(_[j]);
    }
  printf("%d %d\n", res.first, res.second);
  for (int i = 0; i < info.size(); i++)
    printf("%d %d\n", info[i].first, info[i].second);
}
