#include <bits/stdc++.h>
using namespace std;
const int maxn = 500, big = 1e8;
int n, K, ans = big, anss;
int es = 1, he[maxn], to[maxn * 2], ne[maxn * 2];
int f[maxn][maxn];
bool c[maxn] = {0};
vector<pair<int, int> > fr[maxn][maxn];
void ins(int first, int second) {
  to[++es] = second, ne[es] = he[first], he[first] = es;
}
void dfs(int first, int fa) {
  int i, j, k;
  f[first][1] = 0;
  for (i = 2; i <= K; i++) f[first][i] = big;
  for (i = he[first]; i; i = ne[i])
    if (to[i] != fa) {
      dfs(to[i], first);
      for (j = K; j; j--) {
        if (f[first][j] != big) f[first][j]++;
        for (k = 1; k < j; k++)
          if (f[first][j - k] + f[to[i]][k] < f[first][j]) {
            int t;
            f[first][j] = f[first][j - k] + f[to[i]][k];
            fr[first][j].clear();
            for (t = 0; t < fr[first][j - k].size(); t++)
              fr[first][j].push_back(fr[first][j - k][t]);
            fr[first][j].push_back(make_pair(to[i], k));
          }
      }
    }
  if (f[first][K] + (first != 1) < ans)
    ans = f[first][K] + (first != 1), anss = first;
}
void print(int first, int k) {
  int i;
  c[first] = 1;
  for (i = 0; i < fr[first][k].size(); i++)
    print(fr[first][k][i].first, fr[first][k][i].second);
  for (i = he[first]; i; i = ne[i])
    if (!c[to[i]]) printf("%d ", i / 2);
}
int main() {
  int i, j, first, second;
  scanf("%d%d", &n, &K);
  for (i = 1; i < n; i++)
    scanf("%d%d", &first, &second), ins(first, second), ins(second, first);
  dfs(1, 0);
  printf("%d\n", ans);
  print(anss, K);
  return 0;
}
