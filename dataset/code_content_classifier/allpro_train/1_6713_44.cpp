#include <bits/stdc++.h>
using namespace std;
int parent[1000001], rnk[1000001], values[1000001];
vector<int> edges[1000001];
set<pair<int, int> > nodes;
void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    rnk[i] = 1;
  }
}
int root(int x) { return parent[x] == x ? x : parent[x] = root(parent[x]); }
void join(int x, int y) {
  x = root(x), y = root(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    parent[x] = y;
    rnk[y] += rnk[x];
    edges[y].insert(edges[y].end(), edges[x].begin(), edges[x].end());
  } else {
    parent[y] = x;
    rnk[x] += rnk[y];
    edges[x].insert(edges[x].end(), edges[y].begin(), edges[y].end());
  }
}
void formGraph(vector<pair<int, int> > a) {
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i].first == a[i + 1].first) {
      join(a[i].second, a[i + 1].second);
    } else {
      edges[root(a[i].second)].push_back(root(a[i + 1].second));
    }
  }
}
void dp() {
  for (auto it : nodes) {
    if (it.second != root(it.second)) continue;
    values[it.second] = max(1, values[it.second]);
    for (auto j : edges[it.second]) {
      values[root(j)] = max(values[root(j)], values[it.second] + 1);
    }
  }
}
int main() {
  int n, m, o, k = 0;
  cin >> n >> m;
  vector<pair<int, int> > rows[n], cols[m];
  init(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      k++;
      cin >> o;
      pair<int, int> weight = make_pair(o, k);
      rows[i].push_back(weight);
      cols[j].push_back(weight);
      nodes.insert(weight);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(rows[i].begin(), rows[i].end());
    formGraph(rows[i]);
  }
  for (int i = 0; i < m; i++) {
    sort(cols[i].begin(), cols[i].end());
    formGraph(cols[i]);
  }
  dp();
  k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      k++;
      cout << values[root(k)] << ' ';
    }
    cout << '\n';
  }
}
