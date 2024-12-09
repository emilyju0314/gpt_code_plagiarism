#include <bits/stdc++.h>
using namespace std;
int N, diameter;
int color[210000];
vector<int> edge[210000];
vector<int> revparent[210000];
int parent[210000], subt[210000];
int newparent[210000];
bool seen[210000];
void dfs_par(int i, int prev) {
  parent[i] = prev;
  for (int j = 0; j < edge[i].size(); j++) {
    if (edge[i][j] == prev) {
      continue;
    }
    dfs_par(edge[i][j], i);
  }
}
void dfs_fix(int x, int col, int par) {
  if (color[x] == col) {
    newparent[x] = N + 1;
    for (int i = 0; i < revparent[x].size(); i++) {
      dfs_fix(revparent[x][i], col, par);
    }
  } else {
    newparent[x] = par;
    col = color[x];
    par = x;
    for (int i = 0; i < revparent[x].size(); i++) {
      dfs_fix(revparent[x][i], col, par);
    }
  }
  return;
}
int dfs(int x) {
  int siz = 0;
  for (int i = 0; i < revparent[x].size(); i++) {
    siz = max(siz, dfs(revparent[x][i]));
  }
  subt[x] = siz + 1;
  return subt[x];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  if (fopen("cf734e.in", "r")) {
    freopen("cf734e.in", "r", stdin);
    freopen("cf734e.out", "w", stdout);
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> color[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  parent[N + 1] = N + 1;
  dfs_par(0, N + 1);
  for (int i = 0; i < N; i++) {
    revparent[parent[i]].push_back(i);
  }
  dfs_fix(0, -1, N + 1);
  for (int i = 0; i < N; i++) {
    revparent[i].clear();
  }
  for (int i = 0; i < N; i++) {
    revparent[newparent[i]].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < N; i++) {
    if (newparent[i] == N + 1) {
      continue;
    }
  }
  for (int i = 0; i < N; i++) {
    multiset<int> s;
    s.insert(0);
    s.insert(0);
    for (int j = 0; j < revparent[i].size(); j++) {
      int siz = subt[revparent[i][j]];
      s.insert(siz);
    }
    int biggest = *s.rbegin();
    auto it = s.find(biggest);
    s.erase(it);
    int secondbiggest = *s.rbegin();
    diameter = max(diameter, biggest + secondbiggest);
  }
  cout << (diameter + 1) / 2 << '\n';
  return 0;
}
