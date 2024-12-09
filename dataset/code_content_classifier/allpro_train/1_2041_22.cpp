#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
const int INF = 1e9 + 1;
struct T {
  int u, f, w, num;
  T(int u, int f, int w, int num) : u(u), f(f), w(w), num(num){};
  T(){};
};
vector<T> G[N];
int n, m, s, t;
bool used[N];
bool ist[N];
int parent[N];
pair<int, pair<int, int> > ans;
pair<int, int> mn;
int Time = 0;
int tin[N];
int fin[N];
void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i].u;
    if (used[to] == false && G[v][i].f == 1) {
      parent[to] = v;
      dfs(to);
    }
  }
}
vector<int> getPath(int s, int t) {
  memset(used, false, sizeof(used));
  vector<int> ans;
  dfs(s);
  if (used[t] == false) return ans;
  int v = t;
  while (v != s) {
    ans.push_back(v);
    v = parent[v];
  }
  ans.push_back(v);
  return ans;
}
void DeleteEdge(int v, int u, int& num) {
  for (int i = 0; i < G[v].size(); ++i) {
    if (G[v][i].u == u) {
      G[v][i].f = 0;
      num = i;
      break;
    }
  }
  for (int i = 0; i < G[u].size(); ++i) {
    if (G[u][i].u == v) {
      G[u][i].f = 0;
      break;
    }
  }
}
void AddEdge(int v, int u) {
  for (int i = 0; i < G[v].size(); ++i) {
    if (G[v][i].u == u) {
      G[v][i].f = 1;
      break;
    }
  }
  for (int i = 0; i < G[u].size(); ++i) {
    if (G[u][i].u == v) {
      G[u][i].f = 1;
      break;
    }
  }
}
void update(int weight, pair<int, int> num) {
  if (ans.first == -1 || weight < ans.first) {
    ans.first = weight;
    ans.second = num;
  }
}
void findMinBridge(int v, int num) {
  if (v == t) ist[v] = true;
  used[v] = true;
  Time++;
  tin[v] = Time;
  fin[v] = Time;
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i].u;
    if (G[v][i].num == num || G[v][i].f == 0) continue;
    if (used[to] == true) {
      fin[v] = min(fin[v], tin[to]);
    } else {
      findMinBridge(to, G[v][i].num);
      ist[v] |= ist[to];
      fin[v] = min(fin[v], fin[to]);
      if (fin[to] > tin[v] && ist[to] == true) {
        if (mn.first > G[v][i].w) {
          mn.first = G[v][i].w;
          mn.second = G[v][i].num;
        }
      }
    }
  }
}
int main() {
  ans.first = -1;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  s--;
  t--;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    G[u].push_back(T(v, 1, w, i));
    G[v].push_back(T(u, 1, w, i));
  }
  vector<int> path = getPath(s, t);
  if (path.size() == 0) {
    printf("0\n0\n");
    return 0;
  }
  for (int i = (int)path.size() - 1; i > 0; --i) {
    int num;
    DeleteEdge(path[i], path[i - 1], num);
    vector<int> tmp = getPath(s, t);
    if (tmp.size() == 0) {
      update(G[path[i]][num].w, make_pair(G[path[i]][num].num, -1));
    } else {
      memset(used, false, sizeof(used));
      memset(ist, false, sizeof(ist));
      mn.first = INF;
      Time = 0;
      findMinBridge(s, -1);
      if (mn.first != INF)
        update(G[path[i]][num].w + mn.first,
               make_pair(G[path[i]][num].num, mn.second));
    }
    AddEdge(path[i], path[i - 1]);
  }
  if (ans.first == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", ans.first);
  if (ans.second.second == -1) {
    printf("1\n%d", ans.second.first + 1);
  } else {
    printf("2\n%d %d\n", ans.second.first + 1, ans.second.second + 1);
  }
  return 0;
}
