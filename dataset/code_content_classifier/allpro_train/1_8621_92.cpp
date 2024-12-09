#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-8;
struct Edge {
  int v, next, c;
} edge[210 * 210 * 2];
int head[210];
int deg[210];
int tot;
vector<pair<int, int> > ans;
void init() {
  memset(head, -1, sizeof(head));
  memset(deg, 0, sizeof(deg));
  tot = 0;
}
void add_edge(int a, int b, int c) {
  edge[tot] = (Edge){b, head[a], c};
  head[a] = tot++;
}
void dfs(int u) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (edge[i].c == -1) continue;
    if (edge[i].c == 0) ans.push_back(make_pair(u, v));
    edge[i].c = edge[i ^ 1].c = -1;
    dfs(v);
  }
}
int main() {
  int t;
  scanf("%d", &(t));
  while (t--) {
    int n, m;
    scanf("%d", &(n)), scanf("%d", &(m));
    init();
    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d", &(a)), scanf("%d", &(b));
      add_edge(a, b, 0);
      add_edge(b, a, 0);
      deg[a]++;
      deg[b]++;
    }
    vector<int> temp;
    int anss = 0;
    for (int i = 1; i <= n; i++) {
      if (deg[i] & 1)
        temp.push_back(i);
      else
        anss++;
    }
    for (int i = 0; i < temp.size(); i += 2) {
      add_edge(temp[i], temp[i + 1], 1);
      add_edge(temp[i + 1], temp[i], 1);
    }
    ans.clear();
    for (int i = 1; i <= n; i++) dfs(i);
    cout << anss << endl;
    for (int i = 0; i < ans.size(); i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
}
