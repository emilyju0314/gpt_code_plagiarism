#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int N;
vector<int> G[MAXN];
int oddDepthCount = 0;
void DFS(int at, int par, int depth) {
  for (int nxt : G[at]) {
    if (nxt != par) {
      DFS(nxt, at, depth + 1);
    }
  }
  if (depth % 2 == 1) {
    oddDepthCount++;
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DFS(1, -1, 1);
  printf("%d\n", min(oddDepthCount, N - oddDepthCount) - 1);
  return 0;
}
