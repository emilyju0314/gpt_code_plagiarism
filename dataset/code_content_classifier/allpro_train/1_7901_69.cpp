#include <bits/stdc++.h>
using namespace std;
int const dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
template <unsigned N, unsigned M>
struct LowerBoundedFlows {
  int const inf = 1e9;
  int n, m, target[M], pre[M], last[N], tot = 1, cap[M], d[N], s, t, maxflow,
                                        deep[N], cur[N], lower[M], upper[M],
                                        q[N], invalid, res[M];
  void add(int x, int y, int z) {
    target[++tot] = y;
    pre[tot] = last[x];
    last[x] = tot;
    cap[tot] = z;
    target[++tot] = x;
    pre[tot] = last[y];
    last[y] = tot;
    cap[tot] = 0;
  }
  bool bfs() {
    int he = 1, tl = 1;
    for (int i = 0; i <= n; i++) deep[i] = inf, cur[i] = last[i];
    q[1] = s;
    deep[s] = 0;
    while (he <= tl) {
      int now = q[he++];
      for (int i = last[now]; i; i = pre[i]) {
        int tar = target[i];
        if (cap[i] && (deep[tar] > deep[now] + 1))
          deep[tar] = deep[now] + 1, q[++tl] = tar;
      }
    }
    return deep[t] < inf;
  }
  int dfs(int x, int lim) {
    if (x == t) return lim;
    if (!lim) return 0;
    int flow = 0;
    for (int i = cur[x]; i; i = pre[i]) {
      cur[x] = i;
      int tar = target[i];
      if ((deep[tar] == deep[x] + 1) && cap[i]) {
        int d = dfs(tar, min(lim, cap[i]));
        cap[i] -= d;
        cap[i ^ 1] += d;
        lim -= d;
        flow += d;
        if (!lim) break;
      }
    }
    return flow;
  }
  void dinic(int S, int T) {
    s = S, t = T;
    while (bfs()) maxflow += dfs(s, inf);
  }
  void add_edge(int x, int y, int L, int U) {
    m++;
    add(x, y, U - L);
    d[x] += L, d[y] -= L;
    lower[m] = L;
  }
  void work(int nn, int ss = 0, int tt = 0, int op = 0) {
    n = nn + 2;
    int sum = 0;
    if (ss || tt) add(tt, ss, inf);
    for (int i = 1; i <= nn; i++)
      if (d[i] > 0)
        sum += d[i], add(i, nn + 2, d[i]);
      else
        add(nn + 1, i, -d[i]);
    dinic(nn + 1, nn + 2);
    if (maxflow != sum) {
      invalid = 1;
      return;
    }
    if ((!ss) && (!tt)) {
      for (int i = 1; i <= m; i++) res[i] = lower[i] + cap[2 * i + 1];
      return;
    }
    int now = cap[2 * m + 3];
    for (int i = 2 * m + 2; i <= tot; i++) cap[i] = 0;
    maxflow = 0;
    if (op) swap(ss, tt);
    dinic(ss, tt);
    if (!op)
      maxflow += now;
    else
      maxflow = now - maxflow;
    for (int i = 1; i <= m; i++) res[i] = lower[i] + cap[2 * i + 1];
  }
  void clear() {
    memset(last, 0, sizeof(last));
    memset(d, 0, sizeof(d));
    tot = 1;
    maxflow = invalid = m = 0;
  }
};
LowerBoundedFlows<100005, 1600005> g;
vector<int> a[100005], res[100005], res2[100005];
pair<int, int> p[100005];
bool flag[100005];
int lower[400005];
bool cmp(pair<int, int> x, pair<int, int> y) {
  return a[x.first][x.second] < a[y.first][y.second];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    g.clear();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      a[i].resize(m + 1), res[i].resize(m + 1), res2[i].resize(m + 1);
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        lower[(((i)-1) * (m) + (j))] = 1;
        for (int k = 0; k <= 3; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x <= 0 || y <= 0 || x > n || y > m) continue;
          if (a[i][j] > a[x][y])
            lower[(((i)-1) * (m) + (j))] = 0;
          else if (a[i][j] == a[x][y] && ((i + j) & 1))
            g.add_edge((((i)-1) * (m) + (j)), (((x)-1) * (m) + (y)), 0, 1e9);
        }
        if ((i + j) & 1)
          g.add_edge(n * m + 1, (((i)-1) * (m) + (j)),
                     lower[(((i)-1) * (m) + (j))], 1);
        else
          g.add_edge((((i)-1) * (m) + (j)), n * m + 2,
                     lower[(((i)-1) * (m) + (j))], 1);
      }
    g.work(n * m + 2, n * m + 1, n * m + 2);
    if (g.invalid) {
      puts("NO");
      continue;
    }
    puts("YES");
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (!((i + j) & 1)) {
          cnt++;
          continue;
        }
        for (int k = 0; k <= 3; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x <= 0 || y <= 0 || x > n || y > m) continue;
          if (a[i][j] == a[x][y]) {
            cnt++;
            if (g.res[cnt]) {
              res[i][j] = k, res[x][y] = ((k + 2) & 3);
              res2[i][j] = 1, res2[x][y] = a[i][j] - 1;
              flag[(((i)-1) * (m) + (j))] = flag[(((x)-1) * (m) + (y))] = 1;
            }
          }
        }
        cnt++;
      }
    int tot = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (flag[(((i)-1) * (m) + (j))]) continue;
        for (int k = 0; k <= 3; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x <= 0 || y <= 0 || x > n || y > m) continue;
          if (a[i][j] > a[x][y]) {
            res[i][j] = k;
            break;
          }
        }
        p[++tot] = make_pair(i, j);
      }
    sort(p + 1, p + tot + 1, cmp);
    for (int i = 1; i <= tot; i++) {
      int x = p[i].first, y = p[i].second, t = res[x][y];
      res2[x][y] = a[x][y] - a[x + dx[t]][y + dy[t]];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%d ", res2[i][j]);
      puts("");
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (res[i][j] == 0)
          printf("U ");
        else if (res[i][j] == 1)
          printf("R ");
        else if (res[i][j] == 2)
          printf("D ");
        else
          printf("L ");
      puts("");
    }
  }
  return 0;
}
