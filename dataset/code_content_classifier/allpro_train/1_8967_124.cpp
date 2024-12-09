#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
int head[maxn], cnt;
vector<int> pos[maxn];
int len[maxn];
int val[maxn], pre[maxn], vis[maxn];
char str[1100];
char pat[1100];
struct edge {
  int from, to, flow, next, cost;
} e[2 * maxn];
void addedge(int from, int to, int flow, int cost) {
  e[cnt].from = from;
  e[cnt].to = to;
  e[cnt].flow = flow;
  e[cnt].cost = cost;
  e[cnt].next = head[from];
  head[from] = cnt++;
}
void line(int from, int to, int flow, int cost) {
  addedge(from, to, flow, cost);
  addedge(to, from, 0, -cost);
}
int dis[maxn];
queue<int> q;
int spfa(int s, int t, int st) {
  while (!q.empty()) q.pop();
  memset(vis, 0, sizeof(vis));
  memset(pre, 0, sizeof(pre));
  for (int i = 0; i <= st; i++) dis[i] = 1;
  q.push(s);
  vis[s] = 1, dis[s] = 0;
  while (!q.empty()) {
    int now = q.front();
    vis[now] = 0;
    q.pop();
    for (int i = head[now]; i != -1; i = e[i].next) {
      if (!e[i].flow) continue;
      if (dis[now] + e[i].cost < dis[e[i].to]) {
        dis[e[i].to] = dis[now] + e[i].cost;
        pre[e[i].to] = i;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          q.push(e[i].to);
        }
      }
    }
  }
  if (dis[t] >= 0) return 1;
  int u = t;
  while (u != s) {
    int xy = pre[u];
    e[xy].flow -= 1;
    e[xy ^ 1].flow += 1;
    u = e[xy].from;
  }
  return dis[t];
}
int MFMC(int s, int t, int ct) {
  int sum = 0;
  int a;
  while ((a = spfa(s, t, ct)) < 0) {
    sum += a;
  }
  return sum;
}
struct Ac {
  int next[maxn][26], fail[maxn];
  int size;
  queue<int> q;
  void insert(char *S, int xi) {
    int len = strlen(S);
    int now = 0;
    for (int i = 0; i < len; i++) {
      char c = S[i];
      if (next[now][c - 'a'] == 0) {
        next[now][c - 'a'] = ++size;
        now = size;
      } else {
        now = next[now][c - 'a'];
      }
    }
    pos[now].push_back(xi);
  }
  void build() {
    for (int i = 0; i < 26; i++) {
      if (next[0][i]) q.push(next[0][i]);
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < 26; i++) {
        if (next[now][i]) {
          fail[next[now][i]] = next[fail[now]][i];
          q.push(next[now][i]);
        } else
          next[now][i] = next[fail[now]][i];
      }
    }
  }
  void match(char *S) {
    int le = strlen(S);
    int now = 0;
    for (int i = 0; i < le; i++) {
      int x = S[i] - 'a';
      now = next[now][x];
      int temp = now;
      while (temp) {
        for (int j = 0; j < pos[temp].size(); j++) {
          int k = pos[temp][j];
          line(i - len[k] + 1, i + 1, 1, -val[k]);
        }
        temp = fail[temp];
      }
    }
  }
} ac;
int main() {
  memset(head, -1, sizeof(head));
  cnt = 0;
  int n;
  scanf("%d", &n);
  scanf("%s", pat);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s %d", str, &val[i]);
    len[i] = strlen(str);
    ac.insert(str, i);
  }
  int x;
  scanf("%d", &x);
  int s = n + 1, t = n + 2;
  line(s, 0, x, 0);
  line(n, t, x, 0);
  for (int i = 0; i < n; i++) {
    line(i, i + 1, x, 0);
  }
  ac.build();
  ac.match(pat);
  int ans = -MFMC(s, t, n + 2);
  printf("%d\n", ans);
  return 0;
}
