#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> adj[200007];
bool v[200007];
bool touch[200007];
bool flag;
void DFS1(int x, int des) {
  v[x] = 1;
  for (auto y : adj[x]) {
    if (y == des) flag = 1;
    if (v[y]) continue;
    DFS1(y, des);
  }
  return;
}
void DFS2(int x, long long int &cnt) {
  v[x] = 1;
  for (auto y : adj[x]) {
    if (v[y]) continue;
    cnt++;
    DFS2(y, cnt);
  }
  return;
}
int main() {
  int i, j;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (i = 1; i <= n; i++) adj[i].clear();
    for (i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    long long int cnt1 = 0;
    long long int cnt2 = 0;
    flag = 0;
    memset(v, 0, n + 1);
    v[b] = 1;
    DFS1(a, b);
    v[b] = 0;
    DFS2(b, cnt1);
    memset(v, 0, n + 1);
    v[a] = 1;
    DFS1(b, a);
    v[a] = 0;
    DFS2(a, cnt2);
    if (1 != 0 && 0 == 1) printf(">>> %lld %lld\n", cnt1, cnt2);
    if (flag)
      printf("%lld\n", cnt1 * cnt2);
    else
      printf("0\n");
  }
  return 0;
}
