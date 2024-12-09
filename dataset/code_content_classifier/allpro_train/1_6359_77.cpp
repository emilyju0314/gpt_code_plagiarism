#include <bits/stdc++.h>
using namespace std;
struct Vertex {
  int number;
  int factor;
  int part;
  Vertex() { part = 0; }
};
int k1 = 1, k2 = 0;
vector<Vertex> vertices;
vector<vector<int> > graph;
vector<char> used;
vector<int> chain;
int nod(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return nod(b, a % b);
}
void fillParts(int v) {
  used[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (!used[to]) {
      if (vertices[v].part == 1) {
        vertices[to].part = 2;
        k2++;
      } else {
        vertices[to].part = 1;
        k1++;
      }
      fillParts(to);
    }
  }
}
bool findChain(int v) {
  used[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (chain[to] == -1 || !used[chain[to]] && findChain(chain[to])) {
      chain[to] = v;
      return true;
    }
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<int, int> > p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first--;
    p[i].second--;
  }
  vector<vector<pair<int, int> > > groups(n);
  for (int i = 0; i < n; i++) {
    int k = a[i];
    int j = 2;
    while (k != 1 && j * j <= k)
      if (k % j == 0) {
        k /= j;
        Vertex v;
        v.number = a[i];
        v.factor = j;
        groups[i].push_back(make_pair(j, vertices.size()));
        vertices.push_back(v);
      } else
        j++;
    if (k != 1) {
      Vertex v;
      v.number = a[i];
      v.factor = k;
      groups[i].push_back(make_pair(k, vertices.size()));
      vertices.push_back(v);
    }
  }
  graph.resize(vertices.size());
  for (int k = 0; k < m; k++) {
    int x = p[k].first, y = p[k].second;
    for (int i = 0; i < groups[x].size(); i++)
      for (int j = 0; j < groups[y].size(); j++)
        if (groups[x][i].first == groups[y][j].first) {
          graph[groups[x][i].second].push_back(groups[y][j].second);
          graph[groups[y][j].second].push_back(groups[x][i].second);
        }
  }
  used.resize(vertices.size());
  for (int i = 0; i < vertices.size(); i++) {
    if (!used[i]) {
      k1++;
      vertices[i].part = 1;
      fillParts(i);
    }
  }
  chain.assign(vertices.size(), -1);
  vector<bool> trivial(vertices.size());
  for (int i = 0; i < vertices.size(); i++)
    if (k1 < k2 && vertices[i].part == 1 || k1 >= k2 && vertices[i].part == 2)
      for (int j = 0; j < graph[i].size(); j++) {
        int to = graph[i][j];
        if (chain[to] == -1) {
          chain[to] = i;
          trivial[i] = true;
          break;
        }
      }
  for (int i = 0; i < vertices.size(); i++) {
    if (trivial[i]) continue;
    used.assign(vertices.size(), false);
    if (k1 < k2 && vertices[i].part == 1 || k1 >= k2 && vertices[i].part == 2)
      findChain(i);
  }
  int ans = 0;
  for (int i = 0; i < vertices.size(); i++)
    if (chain[i] != -1) ans++;
  cout << ans << endl;
  return 0;
}
