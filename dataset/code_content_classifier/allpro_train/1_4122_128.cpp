#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 11;
const long long oo = 1e17 + 11;
int tcases = 1;
int N, M, K = 0;
vector<int> W[maxN];
vector<pair<int, int> > ed;
set<int> vertices;
set<int>::iterator it1, it2;
vector<int> e[maxN];
map<pair<int, int>, int> region;
void dec(int x) {
  --x;
  if (x <= 0) x = N;
}
void inc(int x) {
  ++x;
  if (x > N) x = 1;
}
bool cmpEdge(pair<int, int> x, pair<int, int> y) {
  return min(x.second - x.first - 1, N - x.second + x.first - 1) >
         min(y.second - y.first - 1, N - y.second + y.first - 1);
}
void constructRegions() {
  sort((ed).begin(), (ed).end(), cmpEdge);
  for (int i = 1; i <= N; ++i) vertices.insert(i);
  K = 0;
  while (ed.size()) {
    pair<int, int> edge = ed.back();
    ed.pop_back();
    int x = edge.second - edge.first - 1, y = N - edge.second + edge.first - 1;
    it1 = vertices.find(edge.first);
    it2 = vertices.find(edge.second);
    if (x < y) {
      ++it2;
      W[++K].push_back(edge.first);
      W[K].push_back(edge.second);
      while (true) {
        it2 = vertices.find(edge.second);
        --it2;
        if ((*it2) == edge.first) break;
        W[K].push_back(*it2);
        vertices.erase(it2);
      }
    } else {
      ++it2;
      if (it2 == vertices.end() && it1 == vertices.begin()) continue;
      W[++K].push_back(edge.first);
      W[K].push_back(edge.second);
      while (true) {
        bool cnt = 0;
        it1 = vertices.find(edge.first);
        if (it1 != vertices.begin()) {
          cnt = 1;
          --it1;
          W[K].push_back(*it1);
          vertices.erase(it1);
        }
        it2 = vertices.find(edge.second);
        ++it2;
        if (it2 != vertices.end()) {
          cnt = 1;
          W[K].push_back(*it2);
          vertices.erase(it2);
        }
        if (!cnt) break;
      }
    }
    sort((W[K]).begin(), (W[K]).end());
  }
  if ((int)vertices.size() >= 3) {
    ++K;
    while (vertices.size()) {
      W[K].push_back(*vertices.begin());
      vertices.erase(vertices.begin());
    }
    sort((W[K]).begin(), (W[K]).end());
  }
  for (int i = 1; i <= K; ++i) {
    for (int j = 0; j < W[i].size(); ++j) {
      int x = W[i][j], y = j < (int)W[i].size() - 1 ? W[i][j + 1] : W[i][0];
      if (x > y) swap(x, y);
      int v = region[make_pair(x, y)];
      if (v) {
        e[v].push_back(i);
        e[i].push_back(v);
      } else {
        region[make_pair(x, y)] = i;
      }
    }
  }
}
int C[maxN];
bool cmp(int i, int j) {
  int x = W[i].size(), y = W[j].size();
  for (int k = 1; k <= min(x, y); ++k) {
    if (W[i][x - k] != W[j][y - k]) return W[i][x - k] < W[j][y - k];
  }
  return x < y;
}
bool isCentroid[maxN];
int sz[maxN], color[maxN];
void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : e[u])
    if (v != p && !isCentroid[v]) {
      dfs(v, u);
      sz[u] += sz[v];
    }
}
int find_centroid(int u, int total, int p = 0) {
  for (int v : e[u])
    if (v != p && !isCentroid[v] && sz[v] > total / 2)
      return find_centroid(v, total, u);
  return u;
}
void centroid_decomposition(int u, int height = 1) {
  dfs(u, u);
  int centroid = find_centroid(u, sz[u]);
  isCentroid[centroid] = 1;
  color[centroid] = height;
  for (int v : e[centroid]) {
    if (!isCentroid[v]) centroid_decomposition(v, height + 1);
  }
}
void testcase() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    ;
    if (x > y) swap(x, y);
    ed.push_back(make_pair(x, y));
  }
  constructRegions();
  centroid_decomposition(1);
  for (int i = 1; i <= K; ++i) C[i] = i;
  sort(C + 1, C + 1 + K, cmp);
  for (int i = 1; i <= K; ++i) {
    cout << color[C[i]] << " ";
  }
}
int main() {
  for (int i = 1; i <= tcases; ++i) testcase();
  return 0;
}
