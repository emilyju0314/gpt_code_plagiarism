#include <bits/stdc++.h>
using namespace std;
vector<int> edges[10];
vector<int> edgesAccum[10];
map<vector<int>, int> dp1;
map<vector<int>, int> dp2;
int cons[4][4] = {{0, 1, 2, 3}, {1, 4, 5, 6}, {2, 5, 7, 8}, {3, 6, 8, 9}};
int revCon[4][10] = {{0, 1, 2, 3, -1, -1, -1, -1, -1, -1},
                     {-1, 0, -1, -1, 1, 2, 3, -1, -1, -1},
                     {-1, -1, 0, -1, -1, 1, -1, 2, 3, -1},
                     {-1, -1, -1, 0, -1, -1, 1, -1, 2, 3}};
set<vector<int> > seen;
vector<int> t;
int dfs(int w) {
  int ret = w;
  int id = t.back();
  int selfEdgeId = cons[id][id];
  int selfEdgeAmount = t[cons[id][id]];
  if (t[selfEdgeId]) {
    w += (edgesAccum[selfEdgeId][selfEdgeAmount] - edgesAccum[selfEdgeId][0]);
    t[selfEdgeId] = 0;
    ret = w;
  }
  for (int con : cons[id]) {
    int edgeCount = t[con];
    if (edgeCount > 0) {
      t.back() = revCon[id][con];
      int startEdge;
      if (edgeCount == 1)
        startEdge = 0;
      else if (edgeCount % 2 == 0)
        startEdge = 1;
      else
        startEdge = 2;
      t[con] = startEdge;
      if (!seen.count(t)) {
        seen.insert(vector<int>(t));
        int wAdd = (edgesAccum[con][edgeCount] - edgesAccum[con][startEdge]);
        ret = max(ret, dfs(w + wAdd));
      }
      t[con] = edgeCount;
    }
  }
  t.back() = id;
  t[cons[id][id]] = selfEdgeAmount;
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, w, b;
    scanf("%d%d%d", &a, &w, &b);
    a--;
    b--;
    edges[cons[a][b]].push_back(w);
  }
  for (int i = 0; i < 10; i++) {
    sort(edges[i].begin(), edges[i].end());
    edgesAccum[i].push_back(0);
    for (int j = 0; j < edges[i].size(); j++) {
      edgesAccum[i].push_back(edges[i][j] + edgesAccum[i].back());
    }
  }
  int maxW = 0;
  for (int i = 0; i < 4; i++) {
    t.clear();
    for (int j = 0; j < 10; j++) t.push_back(edges[j].size());
    t.push_back(i);
    maxW = max(maxW, dfs(0));
  }
  printf("%d\n", maxW);
}
