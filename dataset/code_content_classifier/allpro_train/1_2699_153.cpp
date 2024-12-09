#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> g[200201], h[200201];
int v[200201], dist[200201];
queue<int> q;
void BFS(int S) {
  memset(dist, -1, sizeof(dist));
  q.push(S);
  dist[S] = 0;
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int i = 0; i < g[n].size(); i++) {
      int next = g[n][i];
      if (dist[next] == -1) {
        q.push(next);
        dist[next] = dist[n] + 1;
      }
    }
  }
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[b].push_back(a);
    h[a].push_back(b);
  }
  scanf("%d", &K);
  for (int i = 1; i <= K; i++) scanf("%d", &v[i]);
  BFS(v[K]);
  int mn = 0, mx = 0, n;
  n = 1;
  while (n < K - 1) {
    int y = n;
    for (int i = n + 1; i <= K - 1; i++) {
      if (dist[v[n]] == i - n + dist[v[i]])
        y = i;
      else
        break;
    }
    if (y == K - 1) break;
    n = y + 1;
    mn++;
  }
  n = 1;
  while (n < K - 1) {
    int y = K;
    for (int i = n + 1; i <= K - 1; i++) {
      int chk = 0;
      for (auto next : h[v[i - 1]]) {
        if (next == v[i]) continue;
        if (dist[next] <= dist[v[i]]) {
          chk = 1;
          break;
        }
      }
      if (chk) {
        y = i;
        break;
      }
    }
    if (y == K) break;
    n = y;
    mx++;
  }
  printf("%d %d", mn, mx);
  return 0;
}
