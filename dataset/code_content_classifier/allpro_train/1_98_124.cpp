#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 2e5 + 9;
int head[N], nex[N], to[N], cnt;
inline void add(int u, int v) {
  nex[++cnt] = head[u];
  head[u] = cnt, to[cnt] = v;
}
int n, m, vis[N], peg, ins[N];
inline void dfs(int u) {
  vis[u] = ins[u] = 1;
  for (int i = head[u]; i; i = nex[i]) {
    if (!ins[to[i]] && vis[to[i]]) peg = 1;
    if (!vis[to[i]]) dfs(to[i]);
  }
  ins[u] = 0;
}
int dep[N], pos[N], a[N], g[N];
inline void pre(int u) {
  vis[u] = 1;
  for (int i = head[u]; i; i = nex[i]) {
    if (!vis[to[i]]) {
      dep[to[i]] = dep[u] + 1, pre(to[i]), a[u] += a[to[i]],
      pos[u] ^= pos[to[i]];
    } else if (dep[to[i]] < dep[u])
      a[u]++, a[to[i]]--, pos[u] ^= to[i], pos[to[i]] ^= to[i];
  }
}
inline void get(int u) {
  vis[u] = 1;
  if (a[u] == 1 && g[pos[u]]) g[u] = 1;
  for (int i = head[u]; i; i = nex[i])
    if (!vis[to[i]]) get(to[i]);
}
int main() {
  srand(1);
  int T = read<int>();
  while (T--) {
    n = read<int>(), m = read<int>(), cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= m; i++) {
      int u = read<int>(), v = read<int>();
      add(u, v);
    }
    int rt = -1;
    for (int t = 1; t <= 100; t++) {
      int x = ((rand() << 14) ^ rand()) % n + 1;
      for (int i = 1; i <= n; i++) vis[i] = 0;
      peg = 0, dfs(x);
      if (!peg) {
        rt = x;
        break;
      }
    }
    if (rt == -1) {
      puts("-1");
      continue;
    }
    for (int i = 1; i <= n; i++) pos[i] = a[i] = vis[i] = 0;
    dep[rt] = 1, pre(rt);
    for (int i = 1; i <= n; i++) g[i] = vis[i] = 0;
    g[rt] = 1, get(rt);
    vector<int> tmp(0);
    for (int i = 1; i <= n; i++)
      if (g[i]) tmp.push_back(i);
    if (tmp.size() >= (n + 4) / 5) {
      sort(tmp.begin(), tmp.end());
      for (int i = 0; i < tmp.size(); i++) printf("%d ", tmp[i]);
      puts("");
    } else
      puts("-1");
  }
  return 0;
}
}  // namespace run
int main() { return run::main(); }
