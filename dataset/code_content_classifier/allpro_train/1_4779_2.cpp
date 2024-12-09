#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100;
const int MOD = 998244353;
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
};
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
long long operator^(const P& a, const P& b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
int side(const P& a, const P& b, const P& c) {
  long long res = (b - a) ^ (c - a);
  return res < 0 ? -1 : res > 0 ? +1 : 0;
}
bool operator<(const P& a, const P& b) {
  bool apos = a.y > 0 || a.y == 0 && a.x > 0,
       bpos = b.y > 0 || b.y == 0 && b.x > 0;
  if (apos != bpos) return apos;
  long long res = a ^ b;
  return res > 0;
}
void inc(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
void dec(int& a, int b) {
  if ((a -= b) < 0) a += MOD;
}
void incprod(int& a, int b, int c) { a = (a + (long long)b * c) % MOD; }
int n;
P p[MAXN];
vector<int> adj[MAXN];
int par[MAXN];
vector<int> path[MAXN][MAXN];
void dfsinit(int at) {
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    par[to] = at;
    dfsinit(to);
  }
}
void dfspath(int at, int prv, int root) {
  path[root][at] = prv == -1 ? vector<int>() : path[root][prv];
  path[root][at].push_back(at);
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == prv) continue;
    dfspath(to, at, root);
  }
}
int dp[MAXN];
int dpprod[MAXN];
int dpedge[MAXN][MAXN];
bool hasroot[MAXN][MAXN];
void ensuredpedge(int s, int t, int skip) {
  if (dpedge[s][t] != -1) return;
  const vector<int>& curpath = path[s][t];
  for (int i = (0); i < (((int)(curpath).size())); ++i) {
    int at = curpath[i];
    if (at != s && at != t && side(p[s], p[t], p[at]) <= 0)
      return void(dpedge[s][t] = 0);
  }
  dpedge[s][t] = 1;
  for (int i = (0); i < (((int)(curpath).size())); ++i) {
    int at = curpath[i];
    for (int j = (0); j < (((int)(adj[at]).size())); ++j) {
      int to = adj[at][j];
      if (to == skip) continue;
      if (i - 1 < 0) {
        if (side(p[at], p[curpath[i + 1]], p[to]) >= 0) continue;
      } else if (i + 1 >= ((int)(curpath).size())) {
        if (side(p[curpath[i - 1]], p[at], p[to]) >= 0) continue;
      } else {
        int prv = curpath[i - 1], nxt = curpath[i + 1];
        if (side(p[prv], p[at], p[nxt]) <= 0 &&
            (side(p[prv], p[at], p[to]) >= 0 ||
             side(p[at], p[nxt], p[to]) >= 0))
          continue;
        if (side(p[prv], p[at], p[nxt]) >= 0 &&
            (side(p[prv], p[at], p[to]) >= 0 &&
             side(p[at], p[nxt], p[to]) >= 0))
          continue;
      }
      assert(dp[to] != -1);
      dpedge[s][t] = (long long)dpedge[s][t] * dp[to] % MOD;
    }
  }
}
void dfsnodes(int at, vector<int>& nodes) {
  nodes.push_back(at);
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    dfsnodes(to, nodes);
  }
}
void dfscalc(int at) {
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    dfscalc(to);
  }
  dpprod[at] = 1;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    dpprod[at] = (long long)dpprod[at] * dp[to] % MOD;
  }
  dp[at] = dpprod[at];
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    int cur = dpprod[to];
    for (int j = (0); j < (((int)(adj[at]).size())); ++j)
      if (j != i) {
        int to2 = adj[at][j];
        if (to2 == par[at]) continue;
        cur = (long long)cur * dp[to2] % MOD;
      }
    inc(dp[at], cur);
  }
  vector<int> nodes;
  vector<pair<int, int>> leafedges;
  vector<pair<int, int>> hulledges;
  dfsnodes(at, nodes);
  for (int i = (0); i < (((int)(nodes).size())); ++i) {
    int to = nodes[i];
    if (to == at) continue;
    leafedges.push_back(make_pair(to, par[to]));
    if (par[to] == at) leafedges.push_back(make_pair(par[to], to));
  }
  for (int a = (0); a < (((int)(leafedges).size())); ++a)
    for (int b = (0); b < (((int)(leafedges).size())); ++b) {
      int aa = leafedges[a].first, bb = leafedges[b].first;
      if (side(p[aa], p[bb], p[at]) < 0) continue;
      const vector<int>& curpath = path[aa][bb];
      if (((int)(curpath).size()) < 3 || curpath[1] != leafedges[a].second ||
          curpath[((int)(curpath).size()) - 2] != leafedges[b].second)
        continue;
      ensuredpedge(aa, bb, par[at]);
      if (dpedge[aa][bb] != 0) {
        hulledges.push_back(make_pair(a, b));
        hasroot[aa][bb] = false;
        for (int i = (0); i < (((int)(curpath).size())); ++i)
          if (curpath[i] == at) hasroot[aa][bb] = true;
      }
    }
  sort(hulledges.begin(), hulledges.end(),
       [&](const pair<int, int>& u, const pair<int, int>& v) {
         P udir = p[leafedges[u.second].first] - p[leafedges[u.first].first];
         P vdir = p[leafedges[v.second].first] - p[leafedges[v.first].first];
         return udir < vdir;
       });
  for (int i = (0); i < (((int)(leafedges).size())); ++i) {
    for (int rep = (0); rep < (2); ++rep) {
      vector<int> ways(((int)(leafedges).size()), 0);
      inc(ways[i], 1);
      for (int j = (0); j < (((int)(hulledges).size())); ++j) {
        int a = hulledges[j].first, b = hulledges[j].second;
        int aa = leafedges[a].first, bb = leafedges[b].first;
        if (rep == 1 && hasroot[aa][bb]) continue;
        incprod(ways[b], ways[a], dpedge[aa][bb]);
      }
      dec(ways[i], 1);
      if (rep == 0)
        inc(dp[at], ways[i]);
      else
        dec(dp[at], ways[i]);
    }
  }
}
int solve() {
  for (int i = (0); i < (n); ++i) dp[i] = -1;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) dpedge[i][j] = -1;
  par[0] = -1;
  dfsinit(0);
  for (int i = (0); i < (n); ++i) dfspath(i, -1, i);
  dfscalc(0);
  return dp[0];
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d%d", &p[i].x, &p[i].y);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printf("%d\n", solve());
}
int solvestupid() {
  vector<bool> ok(1 << n, false);
  for (int mask = (1); mask < (1 << n); ++mask) {
    vector<int> cur;
    for (int i = (0); i < (n); ++i)
      if (mask & (1 << i)) cur.push_back(i);
    if (((int)(cur).size()) == 1) {
      ok[mask] = true;
      continue;
    }
    sort(cur.begin(), cur.end(), [](const int& a, const int& b) {
      if (p[a].x != p[b].x) return p[a].x < p[b].x;
      return p[a].y < p[b].y;
    });
    vector<int> hull;
    for (int i = (0); i < (((int)(cur).size())); ++i) {
      while (((int)(hull).size()) >= 2 &&
             side(p[hull[((int)(hull).size()) - 2]],
                  p[hull[((int)(hull).size()) - 1]], p[cur[i]]) < 0)
        hull.pop_back();
      hull.push_back(cur[i]);
    }
    int fixed = ((int)(hull).size());
    for (int i = ((int)(cur).size()) - 2; i >= 0; --i) {
      while (((int)(hull).size()) >= fixed + 1 &&
             side(p[hull[((int)(hull).size()) - 2]],
                  p[hull[((int)(hull).size()) - 1]], p[cur[i]]) < 0)
        hull.pop_back();
      hull.push_back(cur[i]);
    }
    hull.pop_back();
    vector<int> deg(n, 0);
    queue<int> q;
    q.push(cur[0]);
    while (!q.empty()) {
      int at = q.front();
      q.pop();
      for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
        int to = adj[at][i];
        if (deg[to] != 0) continue;
        if ((mask & (1 << to)) == 0) continue;
        ++deg[at], ++deg[to], q.push(to);
      }
    }
    vector<bool> onhull(n, false);
    for (int i = (0); i < (((int)(hull).size())); ++i) onhull[hull[i]] = true;
    bool valid = true;
    for (int i = (0); i < (((int)(cur).size())); ++i) {
      int at = cur[i];
      if (deg[at] == 0) valid = false;
      if ((deg[at] == 1) != onhull[at]) valid = false;
    }
    ok[mask] = valid;
  }
  vector<int> ways(1 << n, 0);
  inc(ways[0], 1);
  for (int mask = (1); mask < (1 << n); ++mask) {
    int fixed = 0;
    while ((mask & (1 << fixed)) == 0) ++fixed;
    for (int pmask = 0; pmask < mask;
         pmask = (pmask + (1 << n) - 1 - mask + 1) & mask)
      if ((pmask & (1 << fixed)) == 0 && ok[mask ^ pmask])
        inc(ways[mask], ways[pmask]);
  }
  return ways[(1 << n) - 1];
}
void stress() {
  for (int rep = (0); rep < (100000); ++rep) {
    n = rnd() % 15 + 1;
    for (int i = (0); i < (n); ++i)
      while (true) {
        p[i].x = rnd() % 100 + 1, p[i].y = rnd() % 100 + 1;
        bool ok = true;
        for (int j = (0); j < (i); ++j)
          if (p[j].x == p[i].x && p[j].y == p[i].y) ok = false;
        for (int j = (0); j < (i); ++j)
          for (int k = (j + 1); k < (i); ++k)
            if (side(p[j], p[k], p[i]) == 0) ok = false;
        if (ok) break;
      }
    vector<pair<int, int>> e;
    vector<int> col(n);
    for (int i = (0); i < (n); ++i) col[i] = i;
    for (int i = (0); i < (n - 1); ++i)
      while (true) {
        int a = rnd() % n, b = rnd() % n;
        if (col[a] == col[b]) continue;
        bool ok = true;
        for (int j = (0); j < (((int)(e).size())); ++j) {
          P A = p[a], B = p[b], C = p[e[j].first], D = p[e[j].second];
          if (side(A, B, C) * side(A, B, D) == -1 &&
              side(C, D, A) * side(C, D, B) == -1)
            ok = false;
        }
        if (!ok) continue;
        e.push_back(make_pair(a, b));
        int ocol = col[b];
        for (int j = (0); j < (n); ++j)
          if (col[j] == ocol) col[j] = col[a];
        break;
      }
    for (int i = (0); i < (n); ++i) adj[i].clear();
    for (int i = (0); i < (((int)(e).size())); ++i) {
      int a = e[i].first, b = e[i].second;
      adj[a].push_back(b), adj[b].push_back(a);
    }
    int have = solve();
    int want = solvestupid();
    if (have == want) {
      if ((rep + 1) % 1000 == 0) printf(".");
      continue;
    }
    printf("have=%d want=%d\n", have, want);
    printf("%d\n", n);
    for (int i = (0); i < (n); ++i) printf("%d %d\n", p[i].x, p[i].y);
    for (int i = (0); i < (((int)(e).size())); ++i)
      printf("%d %d\n", e[i].first + 1, e[i].second + 1);
    break;
  }
}
int main() {
  run();
  return 0;
}
