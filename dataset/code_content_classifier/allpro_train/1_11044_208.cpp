#include <bits/stdc++.h>
int INF = 2147483647;
double INFD = 2147483647;
double PI = 3.14159265359;
using namespace std;
bool DFS(int u, int p, vector<vector<int> >& graph, vector<int>& visited,
         int& visit_count) {
  bool answer = false;
  if (visited[u] == 1) {
    return true;
  }
  visit_count++;
  visited[u] = 1;
  int i = 0;
  while (i < graph[u].size()) {
    int v = graph[u][i];
    if (v != p) {
      bool dfs = DFS(v, u, graph, visited, visit_count);
      answer = answer || dfs;
    }
    i++;
  }
  return answer;
}
int Solve(vector<vector<int> >& graph) {
  int u = 0, count = 0;
  vector<int> visited(graph.size(), 0);
  while (u < graph.size()) {
    if (!visited[u]) {
      int visit_count = 0;
      bool dfs = !DFS(u, u, graph, visited, visit_count);
      if (visit_count == 1 || dfs) {
        count++;
      }
    }
    u++;
  }
  return count;
}
int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  int i = 0;
  while (i < m) {
    int u = 0, v = 0;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
    i++;
  }
  cout << Solve(graph) << endl;
  return 0;
}
