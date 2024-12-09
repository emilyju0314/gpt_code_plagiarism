#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXF = 2;
const int MAXN = 1000;
const int MAXM = MAXN - 2;
const int MAXTN = MAXN - 1;
const int MAXTM = MAXTN - 1;
const int MAXRT = MAXN - 1 + 2 * MAXM;
const int MAXRTN = 10 + MAXTN;
const int MAXRTNSUM = MAXF * MAXRT * MAXRTN + 2 * MAXTN;
typedef struct RT {
  int root, u, v, vv;
} RT;
typedef struct RF {
  int n;
  int par[MAXRTNSUM];
  int chead[MAXRTNSUM];
  int cnxt[MAXRTNSUM];
  int coff[MAXRTNSUM];
  int ccnt[MAXRTNSUM];
  int cidx[MAXRTNSUM];
  int id[MAXRTNSUM];
  int d[MAXRTNSUM];
  int q[MAXRTNSUM], qhead, qtail;
  int orig[MAXRTNSUM];
  RF() { n = 0; }
  int addNode(int p, int o) {
    assert(n < MAXRTNSUM);
    int ret = n++;
    par[ret] = p, chead[ret] = -1, cnxt[ret] = -1, orig[ret] = o;
    if (p != -1) cnxt[ret] = chead[p], chead[p] = ret;
    return ret;
  }
  void print(int at) {
    printf("(");
    for (int to = chead[at]; to != -1; to = cnxt[to]) print(to);
    printf(")");
  }
  int cidcmp(const int &a, const int &b) {
    for (int i = 0; i < ccnt[a] || i < ccnt[b]; ++i) {
      if (i >= ccnt[a]) return -1;
      if (i >= ccnt[b]) return +1;
      int aa = id[cidx[coff[a] + i]], bb = id[cidx[coff[b] + i]];
      if (aa != bb) return aa < bb ? -1 : +1;
    }
    return 0;
  }
  struct cidless {
    RF *rf;
    cidless(RF *rf) : rf(rf) {}
    bool operator()(const int &a, const int &b) { return rf->cidcmp(a, b) < 0; }
  };
  vector<int> calcids(vector<RT> t) {
    int nt = ((int)(t).size());
    qhead = qtail = 0;
    for (int i = (0); i < (nt); ++i) {
      int at = t[i].root;
      d[at] = 0, q[qhead++] = at;
    }
    while (qtail < qhead) {
      int at = q[qtail++];
      for (int to = chead[at]; to != -1; to = cnxt[to])
        d[to] = d[at] + 1, q[qhead++] = to;
    }
    int nq = qtail;
    int nc = 0;
    for (int i = (0); i < (nq); ++i) {
      int at = q[i];
      coff[at] = nc, ccnt[at] = 0;
      for (int to = chead[at]; to != -1; to = cnxt[to]) ++ccnt[at], ++nc;
    }
    int dmx = d[q[nq - 1]];
    int c = nq, b = nq, a = nq;
    while (a > 0 && d[q[a - 1]] == dmx) --a;
    for (int i = (a); i < (b); ++i) {
      int at = q[i];
      id[at] = 0;
    }
    for (int cd = dmx - 1; cd >= 0; --cd) {
      c = b, b = a;
      while (a > 0 && d[q[a - 1]] == cd) --a;
      for (int i = (b); i < (c); ++i) {
        int at = q[i];
        cidx[coff[par[at]]++] = at;
      }
      for (int i = (a); i < (b); ++i) {
        int at = q[i];
        for (int to = chead[at]; to != -1; to = cnxt[to]) --coff[at];
      }
      sort(q + a, q + b, cidless(this));
      for (int i = (a); i < (b); ++i) {
        int at = q[i];
        id[at] =
            i == a ? 0 : id[q[i - 1]] + (cidcmp(at, q[i - 1]) == 0 ? 0 : 1);
      }
    }
    vector<int> ret(nt, -1);
    for (int i = (0); i < (nt); ++i) ret[i] = id[t[i].root];
    return ret;
  }
} RF;
RF rf;
typedef struct T {
  int n, m, root;
  int ghead[MAXTN], gnxt[2 * MAXTM], gto[2 * MAXTM];
  int orig[MAXTN];
  int d1[MAXTN], d2[MAXTN], d3[MAXTN];
  int q[MAXTN], qhead, qtail;
  void init(int o) {
    n = 1, m = 0;
    root = 0;
    ghead[0] = -1, orig[0] = o;
  }
  int addNode(int p, int o) {
    assert(n < MAXTN);
    int ret = n++;
    ghead[ret] = -1, orig[ret] = o;
    if (p != -1) {
      gnxt[m] = ghead[ret], ghead[ret] = m, gto[m] = p, ++m;
      gnxt[m] = ghead[p], ghead[p] = m, gto[m] = ret, ++m;
    }
    return ret;
  }
  vector<int> calcCenters(int rt) {
    for (int i = (0); i < (n); ++i) d1[i] = INT_MAX;
    qhead = qtail = 0;
    d1[rt] = 0, q[qhead++] = rt;
    while (qtail < qhead) {
      int at = q[qtail++];
      for (int x = ghead[at]; x != -1; x = gnxt[x]) {
        int to = gto[x];
        if (d1[to] != INT_MAX) continue;
        d1[to] = d1[at] + 1;
        q[qhead++] = to;
      }
    }
    int u = rt;
    for (int i = (0); i < (n); ++i)
      if (d1[i] != INT_MAX && d1[i] > d1[u]) u = i;
    for (int i = (0); i < (n); ++i) d2[i] = INT_MAX;
    qhead = qtail = 0;
    d2[u] = 0, q[qhead++] = u;
    while (qtail < qhead) {
      int at = q[qtail++];
      for (int x = ghead[at]; x != -1; x = gnxt[x]) {
        int to = gto[x];
        if (d2[to] != INT_MAX) continue;
        d2[to] = d2[at] + 1;
        q[qhead++] = to;
      }
    }
    int v = u;
    for (int i = (0); i < (n); ++i)
      if (d2[i] != INT_MAX && d2[i] > d2[v]) v = i;
    for (int i = (0); i < (n); ++i) d3[i] = INT_MAX;
    qhead = qtail = 0;
    d3[v] = 0, q[qhead++] = v;
    while (qtail < qhead) {
      int at = q[qtail++];
      for (int x = ghead[at]; x != -1; x = gnxt[x]) {
        int to = gto[x];
        if (d3[to] != INT_MAX) continue;
        d3[to] = d3[at] + 1;
        q[qhead++] = to;
      }
    }
    int w = v;
    for (int i = (0); i < (n); ++i)
      if (d3[i] != INT_MAX && d3[i] > d3[w]) w = i;
    vector<int> ret;
    for (int i = (0); i < (n); ++i)
      if (d2[i] + d3[i] == d2[v] && d2[v] - 1 <= 2 * d2[i] &&
          2 * d2[i] <= d2[v] + 1)
        ret.push_back(i);
    return ret;
  }
  void appendTo(int at, int par, int idx) {
    for (int x = ghead[at]; x != -1; x = gnxt[x]) {
      int to = gto[x];
      if (to == par) continue;
      int nidx = rf.addNode(idx, orig[to]);
      appendTo(to, at, nidx);
    }
  }
} T;
T t;
typedef struct F {
  int n, m;
  vector<vector<int> > adj;
  bool done[MAXN];
  int wantdeg;
  void input(int _n) {
    n = _n;
    adj = vector<vector<int> >(n, vector<int>());
    scanf("%d", &m);
    for (int i = (0); i < (m); ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  void buildTree(int at, int idx) {
    done[at] = true;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (done[to]) continue;
      int nidx = t.addNode(idx, to);
      buildTree(to, nidx);
    }
  }
  int calcncomp() {
    for (int i = (0); i < (n); ++i) done[i] = false;
    int ret = 0;
    for (int i = (0); i < (n); ++i)
      if (!done[i]) {
        t.init(i);
        buildTree(i, t.root);
        ++ret;
      }
    return ret;
  }
  RT createCanonical(int u, int v, int vv, bool swp) {
    RT ret;
    ret.u = u;
    ret.v = v;
    ret.vv = vv;
    ret.root = rf.addNode(-1, -1);
    int rt = ret.root, a = rf.addNode(rt, -1), b = rf.addNode(rt, -1),
        c = rf.addNode(rt, -1);
    a = rf.addNode(a, -1);
    rf.addNode(b, -1), b = rf.addNode(b, -1);
    rf.addNode(c, -1), rf.addNode(c, -1), c = rf.addNode(c, -1);
    for (int i = (0); i < (n); ++i) done[i] = false;
    done[u] = true;
    done[v] = true;
    for (int i = (0); i < (((int)(adj[v]).size())); ++i) {
      t.init(adj[v][i]);
      buildTree(adj[v][i], t.root);
      vector<int> centers = t.calcCenters(t.root);
      int par = adj[v][i] == vv ? b : swp ? a : c, bj = 0;
      for (int j = (1); j < (((int)(centers).size())); ++j) {
        int on = rf.n;
        RT a;
        a.root = rf.addNode(-1, centers[bj]);
        t.appendTo(centers[bj], -1, a.root);
        RT b;
        b.root = rf.addNode(-1, centers[j]);
        t.appendTo(centers[j], -1, b.root);
        vector<RT> c;
        c.push_back(a);
        c.push_back(b);
        vector<int> id = rf.calcids(c);
        if (id[1] < id[0]) bj = j;
        rf.n = on;
      }
      {
        int ridx = rf.addNode(par, t.orig[centers[bj]]);
        t.appendTo(centers[bj], -1, ridx);
      }
    }
    for (int i = (0); i < (n); ++i)
      if (!done[i]) {
        t.init(i);
        buildTree(i, t.root);
        vector<int> centers = t.calcCenters(t.root);
        int par = swp ? c : a, bj = 0;
        for (int j = (1); j < (((int)(centers).size())); ++j) {
          int on = rf.n;
          RT a;
          a.root = rf.addNode(-1, centers[bj]);
          t.appendTo(centers[bj], -1, a.root);
          RT b;
          b.root = rf.addNode(-1, centers[j]);
          t.appendTo(centers[j], -1, b.root);
          vector<RT> c;
          c.push_back(a);
          c.push_back(b);
          vector<int> id = rf.calcids(c);
          if (id[1] < id[0]) bj = j;
          rf.n = on;
        }
        {
          int ridx = rf.addNode(par, t.orig[centers[bj]]);
          t.appendTo(centers[bj], -1, ridx);
        }
      }
    return ret;
  }
  vector<RT> createAll(bool swp) {
    int u = -1;
    for (int i = (0); i < (n); ++i)
      if (((int)(adj[i]).size()) == 0) {
        u = i;
        break;
      }
    assert(u != -1);
    vector<RT> ret;
    ret.reserve(n - 1 + 2 * m);
    for (int v = (0); v < (n); ++v)
      if (v != u) {
        if (((int)(adj[v]).size()) + 1 == wantdeg)
          ret.push_back(createCanonical(u, v, -1, swp));
        if (((int)(adj[v]).size()) == wantdeg)
          for (int i = (0); i < (((int)(adj[v]).size())); ++i)
            ret.push_back(createCanonical(u, v, adj[v][i], swp));
      }
    return ret;
  }
  void print(RT a, RT b, F &fb) {
    queue<pair<int, int> > q;
    q.push(make_pair(a.root, b.root));
    vector<int> ab(n, -1), ba(n, -1);
    ab[a.u] = b.v, ba[b.v] = a.u;
    ab[a.v] = b.u, ba[b.u] = a.v;
    while (!q.empty()) {
      int ai = q.front().first, bi = q.front().second;
      q.pop();
      if (rf.orig[ai] != -1 && rf.orig[bi] != -1)
        ab[rf.orig[ai]] = rf.orig[bi], ba[rf.orig[bi]] = rf.orig[ai];
      for (int k = (0); k < (rf.ccnt[ai]); ++k)
        q.push(make_pair(rf.cidx[rf.coff[ai] + k], rf.cidx[rf.coff[bi] + k]));
    }
    for (int i = (0); i < (n); ++i)
      for (int j = (0); j < (((int)(adj[i]).size())); ++j)
        if (i < adj[i][j]) printf("%d %d\n", i + 1, adj[i][j] + 1);
    int x = ab[a.u];
    for (int j = (0); j < (((int)(fb.adj[x]).size())); ++j) {
      int y = fb.adj[x][j];
      printf("%d %d\n", a.u + 1, ba[y] + 1);
    }
    if (a.vv == -1) printf("%d %d\n", a.u + 1, a.v + 1);
  }
} F;
int qq;
int n, nf;
F f[2];
void input() {
  scanf("%d%d", &n, &nf);
  for (int i = (0); i < (nf); ++i) f[i].input(n);
}
bool solve() {
  f[0].wantdeg = f[1].calcncomp() - 1, f[1].wantdeg = f[0].calcncomp() - 1;
  vector<RT> a = f[0].createAll(false);
  vector<RT> b = f[1].createAll(true);
  vector<RT> c;
  for (int i = (0); i < (((int)(a).size())); ++i) c.push_back(a[i]);
  for (int i = (0); i < (((int)(b).size())); ++i) c.push_back(b[i]);
  vector<int> id = rf.calcids(c);
  map<int, int> mp;
  for (int i = (0); i < (((int)(a).size())); ++i)
    if (mp.count(id[i]) == 0) mp[id[i]] = i;
  for (int j = (0); j < (((int)(b).size())); ++j)
    if (mp.count(id[((int)(a).size()) + j])) {
      int i = mp[id[((int)(a).size()) + j]];
      printf("YES\n");
      f[0].print(a[i], b[j], f[1]);
      rf.n = 0;
      return true;
    }
  rf.n = 0;
  printf("NO\n");
  return false;
}
void run() {
  input();
  solve();
}
void test() {
  while (true) {
    int n = 1000;
    vector<int> par(n, -1);
    for (int i = (1); i < (n); ++i) par[i] = rand() % i;
    int u = rand() % n, v = rand() % (n - 1);
    if (v >= u) ++v;
    for (int i = (0); i < (2); ++i) {
      f[i].n = n;
      f[i].adj = vector<vector<int> >(n);
    }
    for (int j = (1); j < (n); ++j) {
      if (j != u && par[j] != u)
        f[0].adj[j].push_back(par[j]), f[0].adj[par[j]].push_back(j);
      if (j != v && par[j] != v)
        f[1].adj[j].push_back(par[j]), f[1].adj[par[j]].push_back(j);
    }
    if (!solve()) {
      printf("1\n");
      printf("%d %d\n", n, 2);
      for (int i = (0); i < (2); ++i) {
        int m = 0;
        for (int j = (0); j < (n); ++j)
          for (int k = (0); k < (((int)(f[i].adj[j]).size())); ++k)
            if (j < f[i].adj[j][k]) ++m;
        printf("%d\n", m);
        for (int j = (0); j < (n); ++j)
          for (int k = (0); k < (((int)(f[i].adj[j]).size())); ++k)
            if (j < f[i].adj[j][k])
              printf("%d %d\n", j + 1, f[i].adj[j][k] + 1);
      }
      break;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  qq = n;
  for (int i = (1); i <= (n); ++i) run();
  return 0;
}
