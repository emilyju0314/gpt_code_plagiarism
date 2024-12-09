#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Node {
  vector<int> nb;
  bool is_cut = false;
  int parent = -1;
  int cut;
  int Size;
};
int n, a, b, k;
map<pair<int, int>, bool> e;
Node vec[100005];
vector<int> treesToCut;
vector<pair<int, int> > E;
int visited[100005] = {0};
int cut(int root, int level, int t_Size, bool sel) {
  visited[root] = level;
  int Tot = 0;
  for (int nb : vec[root].nb)
    if (!vec[nb].is_cut && visited[nb] < level) {
      vec[nb].parent = root;
      visited[nb] = level;
      Tot += cut(nb, level, t_Size, false);
    }
  Tot += 1;
  if (Tot >= sqrt(t_Size) && t_Size > k) {
    vec[root].is_cut = true;
    vec[root].cut = level;
    for (int nb : vec[root].nb)
      if (!vec[nb].is_cut && vec[root].parent != nb)
        cut(nb, level + 1, vec[nb].Size, true);
    return 0;
  } else {
    vec[root].Size = Tot;
    if (sel && t_Size > k) cut(root, level + 1, vec[root].Size, true);
    return Tot;
  }
}
vector<int> NCN;
vector<int> CN;
vector<int> tmp;
void dfs(int node, int level) {
  visited[node] = level;
  NCN.push_back(node);
  if (vec[node].is_cut && vec[node].cut == level + 1) tmp.push_back(node);
  for (int nb : vec[node].nb) {
    if (vec[nb].is_cut) {
      if (vec[nb].cut < level) continue;
      if (vec[nb].cut == level) {
        CN.push_back(nb);
        continue;
      }
    }
    if (visited[nb] > level) {
      visited[nb] = level;
      dfs(nb, level);
    }
  }
}
void connect() {
  for (int cut : CN)
    for (int notCut : NCN)
      if (!e[make_pair(cut, notCut)]) E.push_back(make_pair(cut, notCut));
  for (int node1 : tmp)
    for (int node2 : tmp) {
      if (node1 == node2) continue;
      if (!e[make_pair(node1, node2)]) E.push_back(make_pair(node1, node2));
    }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    vec[a - 1].nb.push_back(b - 1);
    vec[b - 1].nb.push_back(a - 1);
    e[make_pair(a - 1, b - 1)] = true;
    e[make_pair(b - 1, a - 1)] = true;
  }
  vec[0].parent = -1;
  vec[0].Size = n;
  cut(0, 1, n, true);
  for (int i = 0; i < n; ++i) visited[i] = n + 1;
  for (int level = 20; level >= 0; --level) {
    NCN.clear();
    CN.clear();
    tmp.clear();
    for (int j = 0; j < n; ++j)
      if ((!vec[j].is_cut || (vec[j].cut > level)) && visited[j] > level) {
        dfs(j, level);
        connect();
        NCN.clear();
        CN.clear();
        tmp.clear();
      }
  }
  cout << E.size() << "\n";
  for (auto edge : E) cout << edge.first + 1 << " " << edge.second + 1 << "\n";
  return 0;
}
