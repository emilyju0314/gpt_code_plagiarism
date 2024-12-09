#include <bits/stdc++.h>
const int N = 300050;
std::queue<int> Q;
int pre[N], nxt[N * 2], to[N * 2], cnt = 0;
inline void addEdge(int u, int v) {
  to[cnt] = v;
  nxt[cnt] = pre[u];
  pre[u] = cnt++;
}
inline int readInt() {
  int ans = 0;
  char c;
  do c = getchar();
  while (!isdigit(c));
  while (isdigit(c)) {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans;
}
int vis[N];
bool used[N];
int main() {
  int n, k, x, y;
  memset(pre, -1, sizeof pre);
  n = readInt();
  k = readInt();
  readInt();
  while (!Q.empty()) Q.pop();
  memset(vis, -1, sizeof vis);
  for (int i = 0; i < k; ++i) {
    x = readInt();
    Q.push(--x);
    vis[x] = -2;
  }
  for (int i = 1; i < n; ++i) {
    x = readInt();
    y = readInt();
    addEdge(--x, --y);
    addEdge(y, x);
  }
  while (!Q.empty()) {
    x = Q.front();
    Q.pop();
    for (int i = pre[x]; ~i; i = nxt[i])
      if (to[i] != vis[x] && vis[to[i]] == -1) {
        used[i / 2 + 1] = true;
        vis[to[i]] = x;
        Q.push(to[i]);
      }
  }
  int ansc = 0;
  for (int i = 1; i < n; ++i)
    if (!used[i]) ++ansc;
  printf("%d\n", ansc);
  for (int i = 1; i < n; ++i)
    if (!used[i]) printf("%d ", i);
  return 0;
}
