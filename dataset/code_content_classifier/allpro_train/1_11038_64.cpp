#include <bits/stdc++.h>
using namespace std;
const int N = 405;
const int K = 55;
const int mod = 1000000007;
const int inf = 1000000000;
const long long INF = 1000000000000LL;
class MaximumFlow {
  int s, f;

 public:
  struct edge {
    int u, v;
    long long capacity, flow;
    edge() { u = v = capacity = flow = 0; }
    edge(int u_, int v_, long long capacity_, long long flow_)
        : u(u_), v(v_), capacity(capacity_), flow(flow_) {}
  };
  vector<edge> edges;
  vector<vector<int> > graph;
  vector<int> ptr, level;
  queue<int> q;
  int n;
  MaximumFlow() {}
  MaximumFlow(int number) {
    n = number;
    graph.resize(n);
    ptr.assign(n, 0);
    level.resize(n);
  }
  void addEdge(int u, int v, long long capacity) {
    int sz = (int)(edges.size());
    edges.push_back(edge(u, v, capacity, 0));
    edges.push_back(edge(v, u, 0, 0));
    graph[u].push_back(sz);
    graph[v].push_back(sz + 1);
  }
  void updateLevels() {
    level.assign(n, -1);
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int topq = q.front();
      q.pop();
      for (int index = 0; index < graph[topq].size(); ++index) {
        int i = graph[topq][index];
        int to = edges[i].v;
        if (edges[i].capacity - edges[i].flow == 0) {
          continue;
        }
        if (level[to] == -1) {
          level[to] = level[topq] + 1;
          q.push(to);
        }
      }
    }
  }
  long long pushFlow(int v, long long flow) {
    if (v == f || flow == 0) {
      return flow;
    }
    for (; ptr[v] < graph[v].size(); ++ptr[v]) {
      int index = graph[v][ptr[v]];
      int to = edges[index].v;
      if (level[v] + 1 == level[to]) {
        long long pushed =
            pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
        if (pushed > 0) {
          edges[index].flow += pushed;
          edges[index ^ 1].flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  long long dinicFlow(int start, int finish) {
    s = start, f = finish;
    long long result = 0;
    while (true) {
      updateLevels();
      if (level[f] == -1) {
        break;
      }
      while (true) {
        long long pushed = pushFlow(start, INF);
        if (pushed == 0) {
          break;
        }
        result += pushed;
      }
      ptr.assign(n, 0);
    }
    return result;
  }
};
char tab[25][25];
int n, m, females, males, frees;
int d_females[25 * 25][25][25], v_females[25 * 25], x_females[25 * 25],
    y_females[25 * 25];
int d_males[25 * 25][25][25], v_males[25 * 25], x_males[25 * 25],
    y_males[25 * 25];
bool check(long long time) {
  int tot = females + males + n * m * 2 + 2;
  int source = tot - 2, sink = tot - 1;
  MaximumFlow solve(tot);
  for (int i = 0; i < females; ++i) {
    solve.addEdge(source, i, 1);
  }
  for (int i = 0; i < males; ++i) {
    solve.addEdge(females + i, sink, 1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tab[i][j] == '#') {
        continue;
      }
      solve.addEdge(females + males + i * m + j,
                    females + males + i * m + j + n * m, 1);
      for (int k = 0; k < females; ++k) {
        if (d_females[k][i][j] != -1 &&
            (long long)v_females[k] * d_females[k][i][j] <= time) {
          solve.addEdge(k, females + males + i * m + j, INF);
        }
      }
      for (int k = 0; k < males; ++k) {
        if (d_males[k][i][j] != -1 &&
            (long long)v_males[k] * d_males[k][i][j] <= time) {
          solve.addEdge(females + males + i * m + j + n * m, females + k, INF);
        }
      }
    }
  }
  return solve.dinicFlow(source, sink) == females;
}
bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && tab[x][y] == '.';
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void init() {
  for (int i = 0; i < females; ++i) {
    memset(d_females[i], -1, sizeof d_females[i]);
    queue<pair<int, int> > q;
    q.push({x_females[i], y_females[i]});
    d_females[i][x_females[i]][y_females[i]] = 0;
    while (!q.empty()) {
      pair<int, int> where = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int xnew = where.first + dx[k];
        int ynew = where.second + dy[k];
        if (!valid(xnew, ynew)) {
          continue;
        }
        if (d_females[i][xnew][ynew] == -1) {
          d_females[i][xnew][ynew] =
              1 + d_females[i][where.first][where.second];
          q.push({xnew, ynew});
        }
      }
    }
  }
  for (int i = 0; i < males; ++i) {
    memset(d_males[i], -1, sizeof d_males[i]);
    queue<pair<int, int> > q;
    q.push({x_males[i], y_males[i]});
    d_males[i][x_males[i]][y_males[i]] = 0;
    while (!q.empty()) {
      pair<int, int> where = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int xnew = where.first + dx[k];
        int ynew = where.second + dy[k];
        if (!valid(xnew, ynew)) {
          continue;
        }
        if (d_males[i][xnew][ynew] == -1) {
          d_males[i][xnew][ynew] = 1 + d_males[i][where.first][where.second];
          q.push({xnew, ynew});
        }
      }
    }
  }
}
int main() {
  cin >> n >> m >> males >> females;
  for (int i = 0; i < n; ++i) {
    cin >> tab[i];
  }
  int x, y, t;
  cin >> x >> y >> t;
  x--;
  y--;
  for (int i = 0; i < males; ++i) {
    cin >> x_males[i] >> y_males[i] >> v_males[i];
    x_males[i]--;
    y_males[i]--;
  }
  for (int i = 0; i < females; ++i) {
    cin >> x_females[i] >> y_females[i] >> v_females[i];
    x_females[i]--;
    y_females[i]--;
  }
  if (females < males) {
    x_females[females] = x;
    y_females[females] = y;
    v_females[females++] = t;
  } else {
    x_males[males] = x;
    y_males[males] = y;
    v_males[males++] = t;
  }
  init();
  if (females != males || !check(INF)) {
    cout << -1 << endl;
    return 0;
  }
  long long low = -1, high = INF;
  while (high - low > 1) {
    long long mid = (low + high) / 2;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << high << endl;
  return 0;
}
