#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
typedef struct MCMF {
  int n, m;
  vector<int> ghead, gnxt, gto, gcap;
  vector<long long> gcost;
  vector<long long> d;
  vector<int> bck;
  vector<long long> pot;
  vector<int> flow;
  void init(int _n) {
    n = _n, m = 0;
    ghead = vector<int>(n, -1);
    gnxt.clear(), gto.clear(), gcap.clear(), gcost.clear();
    d = vector<long long>(n);
    bck = vector<int>(n);
    pot = vector<long long>(n, 0);
    flow = vector<int>(n);
  }
  void addedge(int a, int b, int c, long long d) {
    gnxt.push_back(ghead[a]);
    ghead[a] = m;
    gto.push_back(b);
    gcap.push_back(c);
    gcost.push_back(+d);
    ++m;
    gnxt.push_back(ghead[b]);
    ghead[b] = m;
    gto.push_back(a);
    gcap.push_back(0);
    gcost.push_back(-d);
    ++m;
  }
  pair<int, long long> solve(int s, int t) {
    for (int i = (0); i < (n); ++i) d[i] = LLONG_MAX, bck[i] = -1;
    d[s] = 0, bck[s] = -2;
    while (true) {
      bool change = false;
      for (int at = (0); at < (n); ++at)
        if (d[at] != LLONG_MAX)
          for (int x = ghead[at]; x != -1; x = gnxt[x])
            if (gcap[x] > 0) {
              int to = gto[x];
              if (d[at] + gcost[x] >= d[to]) continue;
              d[to] = d[at] + gcost[x];
              bck[to] = x ^ 1;
              change = true;
            }
      if (!change) break;
    }
    if (d[t] == LLONG_MAX) return make_pair(0, 0);
    for (int i = (0); i < (n); ++i) pot[i] = d[i];
    pair<int, long long> ret = make_pair(0, 0LL);
    while (true) {
      for (int i = (0); i < (n); ++i)
        d[i] = LLONG_MAX, bck[i] = -1, flow[i] = 0;
      d[s] = 0, bck[s] = -2, flow[s] = INT_MAX;
      priority_queue<pair<long long, int> > q;
      q.push(make_pair(-d[s], s));
      while (!q.empty()) {
        long long cost = -q.top().first;
        int at = q.top().second;
        q.pop();
        if (cost > d[at]) continue;
        for (int x = ghead[at]; x != -1; x = gnxt[x])
          if (gcap[x] > 0) {
            int to = gto[x];
            long long rcost = gcost[x] - pot[at] + pot[to];
            if (d[at] + rcost >= d[to]) continue;
            d[to] = d[at] + rcost;
            bck[to] = x ^ 1;
            flow[to] = min(flow[at], gcap[x]);
            q.push(make_pair(-d[to], to));
          }
      }
      if (d[t] == LLONG_MAX) break;
      assert(flow[t] > 0);
      ret.first += flow[t], ret.second += (d[t] - pot[t]) * flow[t];
      for (int i = (0); i < (n); ++i)
        if (d[i] != LLONG_MAX) pot[i] -= d[i];
      for (int at = t; at != s; at = gto[bck[at]]) {
        gcap[bck[at]] += flow[t];
        gcap[bck[at] ^ 1] -= flow[t];
      }
    }
    return ret;
  }
} MCMF;
const int MAXN = 50;
const int MAXK = 50;
const int MAXT = MAXN + MAXK;
int n, m, k, c, d;
int start[MAXN];
vector<int> adj[MAXN];
int nid, sid, tid;
int vid[MAXN][MAXT + 1];
MCMF g;
long long solve() {
  nid = 0;
  sid = nid++;
  tid = nid++;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j <= (n + k); ++j) vid[i][j] = nid++;
  g.init(nid);
  for (int i = (0); i < (k); ++i) g.addedge(sid, vid[start[i]][0], 1, 0);
  for (int z = k - 1; z >= 0; --z)
    for (int at = (0); at < (n); ++at)
      for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
        int to = adj[at][i];
        for (int j = (0); j < (n + k); ++j)
          g.addedge(vid[at][j], vid[to][j + 1], 1, (2 * z + 1) * d);
      }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n + k); ++j)
      g.addedge(vid[i][j], vid[i][j + 1], k, 0);
  for (int j = (0); j <= (n + k); ++j) g.addedge(vid[0][j], tid, k, c * j);
  pair<int, long long> res = g.solve(sid, tid);
  assert(res.first == k);
  return res.second;
}
void run() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  for (int i = (0); i < (k); ++i) scanf("%d", &start[i]), --start[i];
  for (int i = (0); i < (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printf("%lld\n", solve());
}
int main() {
  run();
  return 0;
}
