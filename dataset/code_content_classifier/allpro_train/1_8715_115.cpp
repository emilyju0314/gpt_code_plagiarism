#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
const int maxm = (int)1e5 + 5;
int hd[maxn], eg[maxm << 1], nxt[maxm << 1], tot = 0, n, m, in[maxn], deg[maxn],
                                             q[maxn << 1], N;
void addedge(int u, int v) {
  eg[++tot] = v;
  nxt[tot] = hd[u];
  hd[u] = tot;
}
bool vis[maxn], tag[maxn];
vector<int> can;
void topo() {
  int head = 0, tail = -1;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q[++tail] = i;
  while (head <= tail) {
    int v = q[head % N];
    head++;
    vis[v] = true;
    for (int i = hd[v]; i; i = nxt[i]) {
      int u = eg[i];
      if (--in[u] == 0) {
        tail++;
        q[tail % N] = u;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) can.push_back(i);
}
bool cal(int v) {
  memset(tag, 0, sizeof(tag));
  int head = 0, tail = 0;
  if (--in[v] != 0)
    return false;
  else {
    q[head] = v;
    while (head <= tail) {
      int v = q[head % N];
      head++;
      tag[v] = true;
      for (int i = hd[v]; i; i = nxt[i]) {
        int u = eg[i];
        if (--in[u] == 0) {
          tail++;
          q[tail % N] = u;
        }
      }
    }
    for (int i = 0; i < (int)can.size(); i++)
      if (!tag[can[i]]) return false;
    return true;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  N = n + 5;
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    in[v]++;
  }
  topo();
  if (!can.size()) {
    printf("YES\n");
    exit(0);
  }
  memcpy(deg, in, sizeof(in));
  for (int i = 0; i < (int)can.size(); i++) {
    if (cal(can[i])) {
      printf("YES\n");
      exit(0);
    }
    memcpy(in, deg, sizeof(deg));
  }
  printf("NO\n");
  return 0;
}
