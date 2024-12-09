#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
bool bs[125];
class MaxFlow {
 public:
  int cap[10000], flow[10000];
  int to[10000], prev[10000], last[125], used[125], level[125];
  int V, E;
  MaxFlow(int n) {
    V = n;
    E = 0;
    for (int(i) = 0; (i) < (int)(V); (i)++) last[i] = -1;
  }
  void add_edge(int x, int y, int f) {
    cap[E] = f;
    flow[E] = 0;
    to[E] = y;
    prev[E] = last[x];
    last[x] = E;
    E++;
    cap[E] = 0;
    flow[E] = 0;
    to[E] = x;
    prev[E] = last[y];
    last[y] = E;
    E++;
  }
  bool bfs(int s, int t) {
    int i;
    for (int(i) = 0; (i) < (int)(V); (i)++) level[i] = -1;
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (i = last[x]; i >= 0; i = prev[i])
        if (level[to[i]] == -1 && cap[i] > flow[i]) {
          q.push(to[i]);
          level[to[i]] = level[x] + 1;
        }
    }
    return (level[t] != -1);
  }
  int dfs(int v, int t, int f) {
    int i;
    if (v == t) return f;
    for (i = used[v]; i >= 0; used[v] = i = prev[i])
      if (level[to[i]] > level[v] && cap[i] > flow[i]) {
        int tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
        if (tmp > 0) {
          flow[i] += tmp;
          flow[i ^ 1] -= tmp;
          return tmp;
        }
      }
    return 0;
  }
  void dfs1(int i) {
    bs[i] = 1;
    for (int j = last[i]; j >= 0; j = prev[j])
      if (cap[j] - flow[j] > 0) {
        int v = to[j];
        if (!bs[v]) dfs1(v);
      }
  }
  int maxflow(int s, int t) {
    while (bfs(s, t)) {
      for (int(i) = 0; (i) < (int)(V); (i)++) used[i] = last[i];
      while (dfs(s, t, (1 << 29)) != 0)
        ;
    }
    int ans = 0;
    for (int i = last[s]; i >= 0; i = prev[i]) ans += flow[i];
    return ans;
  }
};
int u[125 * 10], v[125 * 10], g[125 * 10];
int rid[125 * 10];
int in[125], out[125];
void fmain(int tid) {
  int s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  MaxFlow mf = MaxFlow(n + 5);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%d%d%d", u + i, v + i, g + i);
    if (g[i] == 0) {
      mf.add_edge(u[i], v[i], (1 << 30));
    } else {
      mf.add_edge(u[i], v[i], 1);
      mf.add_edge(v[i], u[i], (1 << 30));
    }
  }
  int ans = mf.maxflow(s, t);
  printf("%d\n", ans);
  mf.dfs1(s);
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (mf.level[i] != -1) {
      assert(bs[i]);
    }
  mf = MaxFlow(n + 5);
  int S = n + 1, T = S + 1;
  for (int(i) = 1; (i) <= (int)(m); (i)++)
    if (g[i]) {
      rid[i] = mf.E;
      mf.add_edge(u[i], v[i], 10000);
      in[v[i]]++;
      in[u[i]]--;
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    if (in[i] > 0)
      mf.add_edge(S, i, in[i]);
    else if (in[i] < 0)
      mf.add_edge(i, T, -in[i]);
  }
  mf.add_edge(t, s, (1 << 30));
  mf.maxflow(S, T);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    if (g[i] == 0)
      puts("0 1");
    else {
      int flw = 10001 - (mf.cap[rid[i]] - mf.flow[rid[i]]);
      int cp = bs[u[i]] && !bs[v[i]] ? flw : (1000000000);
      printf("%d %d\n", flw, cp);
    }
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
