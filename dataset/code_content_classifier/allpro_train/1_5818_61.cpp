#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 10;
const int MAX_LEN = 100000 + 10;
const int MAX_LOG_V = 22;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const unsigned long long B = 100000007;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10;
    x += ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct edge {
  int to, cost, coin;
};
struct Node {
  long long cnt, w;
  bool operator<(const Node &b) const {
    return (w - w / 2) * cnt < (b.w - b.w / 2) * b.cnt;
  }
};
vector<edge> g[MAXN];
priority_queue<Node> q1, q2;
int n;
int vis[MAXN];
long long v1[MAXN], v2[MAXN];
long long S, sum;
int dfs(int v, int p) {
  if (vis[v]) return 1;
  int cnt = 0;
  for (int i = 0; i < g[v].size(); i++) {
    edge &e = g[v][i];
    if (e.to == p) continue;
    int t = dfs(e.to, v);
    sum += 1ll * t * e.cost;
    cnt += t;
    if (e.coin == 1)
      q1.emplace(Node{t, e.cost});
    else
      q2.emplace(Node{t, e.cost});
  }
  return cnt;
}
void sovle() {
  scanf("%d %lld", &n, &S);
  while (!q1.empty()) q1.pop();
  while (!q2.empty()) q2.pop();
  sum = 0;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v, w, c;
    scanf("%d %d %d %d", &u, &v, &w, &c);
    g[u].emplace_back(edge{v, w, c});
    g[v].emplace_back(edge{u, w, c});
  }
  for (int i = 2; i <= n; i++) {
    if (g[i].size() == 1) vis[i] = 1;
  }
  dfs(1, 0);
  int tot1 = 0, tot2 = 0;
  for (int i = 1; !q1.empty(); i++) {
    Node p = q1.top();
    q1.pop();
    v1[i] = v1[i - 1] + (p.w - p.w / 2) * p.cnt;
    if (v1[i] == v1[i - 1]) break;
    p.w /= 2;
    q1.emplace(p);
    tot1 = i;
  }
  for (int i = 1; !q2.empty(); i++) {
    Node p = q2.top();
    q2.pop();
    v2[i] = v2[i - 1] + (p.w - p.w / 2) * p.cnt;
    if (v2[i] == v2[i - 1]) break;
    p.w /= 2;
    q2.emplace(p);
    tot2 = i;
  }
  long long d = sum - S;
  if (d <= 0) {
    puts("0");
    return;
  }
  int ans = INF;
  for (int i = 0; i <= tot1; i++) {
    if (v1[i] >= d) {
      ans = min(ans, i);
      break;
    }
    int p = lower_bound(v2 + 1, v2 + 1 + tot2, d - v1[i]) - v2;
    if (p > tot2) continue;
    ans = min(ans, i + p * 2);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    sovle();
  }
}
