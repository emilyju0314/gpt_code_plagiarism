#include <bits/stdc++.h>
using namespace std;
int n;
int iin() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 1e5 * 2;
vector<int> adj[N + 1];
int dis[N + 1];
void bfs() {
  vector<int> bfsa;
  bfsa.push_back(0);
  for (int i = 0; i < bfsa.size(); i++) {
    for (int ne : adj[bfsa[i]]) {
      if (!dis[ne] && ne != 0) {
        bfsa.push_back(ne);
        dis[ne] = dis[bfsa[i]] + 1;
      }
    }
  }
}
int main() {
  n = iin();
  for (int i = 0; i < n; i++) {
    adj[i].push_back(iin() - 1);
    if (i != n - 1) adj[i].push_back(i + 1);
    if (i) adj[i].push_back(i - 1);
  }
  bfs();
  for (int i = 0; i < n; i++) printf("%d ", dis[i]);
}
