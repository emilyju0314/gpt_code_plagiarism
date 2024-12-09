// implement  140min
// implement2  75min
// debug1      10min
// debug2      30min
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef vector<int> Edges;
typedef vector<Edges> Graph;

struct Memo {
  int v[4][10][10];
  Memo() {
    MEMSET(v, 0);
  }
};

const ll MOD = 1e+9 + 7;
int n, k;
vector<int> lens;
bool connect[40][40];
pair<int, int> g[40][40];
Memo memo[40][40];
vector<int> memo2[4][4][4][10][10];
Memo EndState;

int dfs(Graph &g, int from, int inicolor, int weight[6], int color[6], bool visit[6]) {
  if (inicolor != color[from] || visit[from]) { return 0; }
  visit[from] = true;
  int ret = weight[from];
  FORIT(it, g[from]) {
    ret += dfs(g, *it, inicolor, weight, color, visit);
  }
  return ret;
}

void AddEdge(Graph &g, int f, int t) {
  g[f].push_back(t);
  g[t].push_back(f);
}

vector<int> ConnectStraight(int node, int nnode, int c1, int c2, int fh, int fi, int dir) {
  int initial = fh == 0 && fi == 0;
  int end = (fi + dir == 0 || fi + dir == lens[fh] - 1);
  int flag = initial * 2 + end;
  if (!memo2[flag][node][nnode][c1][c2].empty())  { return memo2[flag][node][nnode][c1][c2]; }
  int weight[6] = { 1, 1, 0, 0, c1, c2 };
  if (end) { weight[2] = weight[3] = 1; }
  int color[6] = { (node >> 0) & 1, (node >> 1) & 1, (nnode >> 0) & 1, (nnode >> 1) & 1, 0, 1 };
  Graph g(6); // 4, 5 is color weight node
  // o o node
  // | |
  // o o nnode
  AddEdge(g, 0, 2);
  AddEdge(g, 1, 3);
  if (!initial) {
    // o-o node
    //    
    // o o nnode
    AddEdge(g, 0, 1);
  }
  if (!end) {
    // o o node
    //    
    // o-o nnode
    AddEdge(g, 2, 3);
  }
  if (!end) {
    REP(c, 2) {
      REP(i, 2) {
        if (color[i + 2] == c) { AddEdge(g, i + 2, 4 + c); }
      }
    }
  }
  vector<int> ret(2);
  bool visit[6];
  MEMSET(visit, false);
  REP(i, 2) {
    int c = color[i];
    ret[c] = max(ret[c], dfs(g, i, c, weight, color, visit));
  }
  return memo2[flag][node][nnode][c1][c2] = ret;
}

// xx
//o03o
//o12o
// oo
void CrossPointUpdate(Memo &ret, const Memo &mret, const Memo &nret, const Memo &pret, int node, int nnode,int dir) {
  int nextShift = (dir == 1) ? 1 : 0;
  int midShift = (dir == 1) ? 0 : 1;
  int plusNode = (((nnode >> 1) & 1) << nextShift) | (((node >> 1) & 1) << midShift);
  int minusNode = (((nnode >> 0) & 1) << nextShift) | (((node >> 0) & 1) << midShift);

  int temp1[10][10]; // 0 & 2 weight
  int temp2[10][10]; // 0 & 3 weight
  int n0 = (node >> 0) & 1;
  int n1 = (nnode >> 0) & 1;
  int n2 = (nnode >> 1) & 1;
  int n3 = (node >> 1) & 1;
  MEMSET(temp1, 0);
  MEMSET(temp2, 0);

  FOREQ(c1, 0, k) {
    FOREQ(c2, 0, k) {
      FOREQ(c3, 0, k) {
        FOREQ(c4, 0, k) {
          int w0 = 0, w1 = 0, w2 = 0;
          if (n1 == 0) { w1 = c1 + c3 - 1; }
          else if (n1 == 1) { w1 = c2 + c4 - 1; }
          if (n0 != n1 && n0 == 0) { w0 = c1; }
          else if (n0 != n1 && n0 == 1) { w0 = c2; }
          if (n2 != n1 && n2 == 0) { w2 = c3; }
          else if (n2 != n1 && n2 == 1) { w2 = c4; }
          if (w1 < 0 || w1 > k) { continue; }

          if (n1 == n2) {
            assert(w2 == 0);
            w2 = w1;
            w1 = 0;
          } else if (n1 == n0) {
            assert(w0 == 0);
            w0 = w1;
            w1 = 0;
          }
          if (n0 == n1 && n1 == n2) {
            w2 += w0;
            w0 = 0;
          }

          assert(w0 >= 0 || w2 >= 0);
          assert(w0 <= k && w2 <= k);
          assert(w0 != 0 || w2 != 0 || nret.v[nnode][c3][c4] == 0 || mret.v[minusNode][c1][c2] == 0);
          temp1[w0][w2] = (temp1[w0][w2] + (ll)nret.v[nnode][c3][c4] * mret.v[minusNode][c1][c2]) % MOD;
        }
      }
    }
  }
  assert(temp1[0][0] == 0);

  FOREQ(c1, 0, k) {
    FOREQ(c2, 0, k) {
      FOREQ(rw0, 0, k) {
        FOREQ(rw2, 0, k) {
          int w0 = rw0;
          int w2 = 0;
          int w3 = 0;
          if (n2 == 0) { w2 = rw2 + c1 - 1; }
          else if (n2 == 1) { w2 = rw2 + c2 - 1; }
          if (n2 != n3 && n3 == 0) { w3 = c1; }
          else if (n2 != n3 && n3 == 1) { w3 = c2; }
          if (w2 < 0 || w2 > k) { continue; }

          if (n2 == n3) {
            assert(w3 == 0);
            w3 = w2;
            w2 = 0;
          }
          if (n0 == n3) {
            w0 += w3;
            w3 = 0;
          }
          if (n2 == n1 && n1 == n0) {
            w0 += w2;
            w2 = 0;
          }
          if (w0 > k) { continue; }

          assert((n0 == n1 && n0 == n2) || rw0 != 0 || temp1[rw0][rw2] == 0);
          assert(w0 <= k && w3 <= k);
          assert(w0 != 0 || w3 != 0 || temp1[rw0][rw2] == 0 || pret.v[plusNode][c1][c2] == 0);
          temp2[w0][w3] = (temp2[w0][w3] + (ll)temp1[rw0][rw2] * pret.v[plusNode][c1][c2]) % MOD;
        }
      }
    }
  }

  FOREQ(w0, 0, k) {
    FOREQ(w3, 0, k) {
      int c1 = 0, c2 = 0;
      if (n0 == 0) { c1 = max(c1, w0); }
      if (n0 == 1) { c2 = max(c2, w0); }
      if (n3 == 0) { c1 = max(c1, w3); }
      if (n3 == 1) { c2 = max(c2, w3); }
      assert(c1 != 0 || c2 != 0 || temp2[w0][w3] == 0);
      ret.v[node][c1][c2] = (ret.v[node][c1][c2] + temp2[w0][w3]) % MOD;
    }
  }
}

// Merge Rule
//                     m  p  
// oo oo    oo          oo  m
// 01 01 -\ 01 o02o -\ oXXo  
// 23 23 -/ 23 o13o -/ oXXo  
// oo oo    oo          oo  p
// 
// bits
// 01 01    01          01 
// oo oo -\ oo 0oo0 -\ 0oo0
// oo oo -/ oo 1oo1 -/ 1oo1
// 01 01    01          01 
//
Memo calc(int dir, int fh, int fi, bool ignore) {
  bool end = (fi == 0 || fi == lens[fh] - 1) && (fh != 0 || fi != 0);
  if (end) {
    return EndState;
  }
  if (memo[fh][fi].v[0][0][0] != -1) { return memo[fh][fi]; }
  Memo ret;
  if (ignore || !connect[fh][fi])  {
    Memo nret = calc(dir, fh, fi + dir, false);
    REP(node, 4) {
      REP(nnode, 4) {
        FOREQ(c1, 0, k) {
          FOREQ(c2, 0, k) {
            if (nret.v[nnode][c1][c2] == 0) { continue; }
            vector<int> nc = ConnectStraight(node, nnode, c1, c2, fh, fi, dir);
            if (nc[0] > k || nc[1] > k) { continue; }
            ret.v[node][nc[0]][nc[1]] =
              (ret.v[node][nc[0]][nc[1]] + nret.v[nnode][c1][c2]) % MOD;
          }
        }
      }
    }
  } else {
    int th = g[fh][fi].first;
    int ti = fi + dir;
    int plusTi = g[fh][ti].second + 1;
    int minusTi = g[fh][ti].second;
    Memo nret = calc(dir, fh, ti, true);
    Memo pret = calc(1, th, plusTi, true);
    Memo mret = calc(-1, th, minusTi, true);
    REP(node, 4) {
      REP(nnode, 4) {
        CrossPointUpdate(ret, mret, nret, pret, node, nnode, dir);
      }
    }
  }
  return memo[fh][fi] = ret;
}

int main() {
  REP(node, 4) {
    int c1 = 1 ^ (((node >> 0) & 1) | ((node >> 1) & 1));
    int c2 = 0 ^ (((node >> 0) & 1) | ((node >> 1) & 1));
    EndState.v[node][c1][c2] = 1;
  }
  while (scanf("%d %d", &n, &k) > 0 && n|k) {
    // Initialize
    lens = vector<int>(n);
    MEMSET(connect, false);
    MEMSET(g, 0xef);
    MEMSET(memo, -1);
    REP(flag, 4) REP(prev, 4) REP(nnode, 4) REP(c1, 10) REP(c2, 10) {
      memo2[flag][prev][nnode][c1][c2].clear();
    }

    // Input
    REP(i, n) {
      scanf("%d", &lens[i]);
      lens[i] += 3;
    }
    REP(i, n - 1) {
      int fh, fi, th, ti;
      scanf("%d %d %d %d", &fh, &fi, &th, &ti);
      connect[fh][fi + 1] = connect[fh][fi + 2] = true;
      connect[th][ti + 1] = connect[th][ti + 2] = true;
      g[fh][fi + 1] = g[fh][fi + 2] = make_pair(th, ti + 1);
      g[th][ti + 1] = g[th][ti + 2] = make_pair(fh, fi + 1);
    }

    // Solve
    calc(1, 0, 0, false);
    ll ans = 0;
    REP(node, 4) {
      FOREQ(c1, 0, k) {
        FOREQ(c2, 0, k) {
          ans = (ans + memo[0][0].v[node][c1][c2]) % MOD;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
