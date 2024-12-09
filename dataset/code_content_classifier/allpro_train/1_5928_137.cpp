#include <bits/stdc++.h>
using namespace std;
int gi() {
  int res = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * w;
}
const int MAX_N = 1e3 + 5;
vector<int> G[MAX_N];
int N, M;
int col[MAX_N], bel[MAX_N], cnt;
bool flag = 1;
void dfs(int x, int c) {
  col[x] = c, bel[x] = cnt;
  for (int v : G[x]) {
    if (col[v])
      flag &= col[v] != c;
    else
      dfs(v, 3 - c);
  }
}
int dis[MAX_N];
int bfs(int s) {
  static int Q[MAX_N];
  int head = 1, tail = 1;
  Q[1] = s, dis[s] = 1;
  while (head <= tail) {
    int x = Q[head++];
    for (int v : G[x]) {
      if (dis[v]) continue;
      dis[v] = dis[x] + 1, Q[++tail] = v;
    }
  }
  int res = 0;
  for (int i = 1; i <= tail; i++) res = max(res, dis[Q[i]]), dis[Q[i]] = 0;
  return res - 1;
}
int len[MAX_N];
int main() {
  N = gi(), M = gi();
  for (int i = 1; i <= M; i++) {
    int u = gi(), v = gi();
    G[u].push_back(v), G[v].push_back(u);
  }
  for (int i = 1; i <= N && flag; i++)
    if (!col[i]) ++cnt, dfs(i, 2);
  if (!flag) return puts("-1") & 0;
  for (int i = 1; i <= N; i++) len[bel[i]] = max(len[bel[i]], bfs(i));
  int ans = 0;
  for (int i = 1; i <= cnt; i++) ans += len[i];
  printf("%d\n", ans);
  return 0;
}
