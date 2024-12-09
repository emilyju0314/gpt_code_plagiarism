#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  register int data = 0, w = 1;
  register char ch = 0;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar();
  return w * data;
}
const int Mod = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 2e5 + 5;
struct Graph {
  int to, cost, next;
} e[MAX_N << 2];
int fir[MAX_N], deg[MAX_N], e_cnt;
void clearGraph() {
  memset(fir, -1, sizeof(fir));
  e_cnt = 0;
}
void Add_Edge(int u, int v, int w) {
  e[e_cnt] = (Graph){v, w, fir[u]}, fir[u] = e_cnt++, deg[v]++;
}
int N;
pair<int, int> p[MAX_N];
int dis[MAX_N], cnt[MAX_N];
void TopSort() {
  static queue<int> que;
  for (int i = 1; i <= N; i++) dis[i] = INF;
  cnt[0] = 1, que.push(0);
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = fir[x]; ~i; i = e[i].next) {
      int v = e[i].to, w = e[i].cost;
      if (!--deg[v]) que.push(v);
      if (dis[x] + w < dis[v])
        dis[v] = dis[x] + w, cnt[v] = cnt[x];
      else if (dis[x] + w == dis[v])
        cnt[v] = (cnt[v] + cnt[x]) % Mod;
    }
  }
}
int main() {
  N = gi();
  for (int i = 1; i <= N; i++) p[i].second = gi(), p[i].first = gi();
  sort(&p[1], &p[N + 1]);
  clearGraph();
  for (int i = 1; i <= N; i++) Add_Edge(i - 1, i, p[i].first - p[i - 1].first);
  for (int i = 1; i <= N; i++) {
    int j = lower_bound(&p[i + 1], &p[N + 1], make_pair(p[i].second, 0)) - p;
    Add_Edge(i, j, p[j].first - p[i].second);
  }
  TopSort();
  int mdis = INF;
  for (int i = 1; i <= N; i++)
    if (p[i].second > p[N].first) mdis = min(mdis, dis[i]);
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (p[i].second > p[N].first && mdis == dis[i]) ans = (ans + cnt[i]) % Mod;
  printf("%d\n", ans);
  return 0;
}
