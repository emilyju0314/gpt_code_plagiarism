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

typedef int Weight;
struct Edge {
  int index;
  int src;
  int dest;
  Weight weight;
  Edge(int index, int src, int dest, Weight weight) : index(index), src(src), dest(dest), weight(weight) {;}
  bool operator<(const Edge &rhs) const {
    if (weight != rhs.weight) { return weight > rhs.weight; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void PrintMatrix(const Matrix &matrix) {
  for (int y = 0; y < (int)matrix.size(); y++) {
    for (int x = 0; x < (int)matrix[y].size(); x++) {
      printf("%d ", matrix[y][x]);
    }
    puts("");
  }
}

Weight augment(const Graph &g, Array &capacity, const vector<int> &level, vector<bool> &finished, int from, int t, Weight cur) {
  if (from == t || cur == 0) { return cur; }
  if (finished[from]) { return 0; }
  for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
    int to = it->dest;
    if (level[to] != level[from] + 1) { continue; }
    Weight f = augment(g, capacity, level, finished, to, t, min(cur, capacity[it->index]));
    if (f > 0) {
      capacity[it->index] -= f;
      capacity[it->index^1] += f;
      return f;
    }
  }
  finished[from] = true;
  return 0;
}

// index^1 is reverse edge
Weight MaxFlow(const Graph &g, int e, int s, int t) {
  int n = g.size();
  Array capacity(e);
  for (int from = 0; from < n; from++) {
    for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
      capacity[it->index] += it->weight;
    }
  }
  int ans = 0;
  while (true) {
    vector<int> level(n, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    for (int d = n; !que.empty() && level[que.front()] < d; ) {
      int from = que.front();
      que.pop();
      if (from == t) { d = level[from]; }
      for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
        int to = it->dest;
        if (capacity[it->index] > 0 && level[to] == -1) {
          que.push(to);
          level[to] = level[from] + 1;
        }
      }
    }
    vector<bool> finished(n);
    bool end = true;
    while (true) {
      Weight f = augment(g, capacity, level, finished, s, t, 2000000000LL);
      if (f == 0) { break; }
      ans += f;
      end = false;
    }
    if (end) { break; }
  }
  return ans;
}

void AddEdge(Graph &g, int &e, int from, int to, Weight capacity) {
  g[from].push_back(Edge(e++, from, to, capacity));
  g[to].push_back(Edge(e++, to, from, 0));
}

int n;
int seq[1000];
int use[1000];
inline int IN(int x) { return x; }
inline int OUT(int x) { return n + x; }
inline int SOURCE() { return n * 2 + 0; }
inline int DEST() { return n * 2 + 1; }
inline int SIZE() { return n * 2 + 2; }

bool Ban(int i, int j) { return seq[i] % seq[j] == 0; }

int Solve() {
  Graph g(SIZE());
  int e = 0;
  int m = 0;
  REP(i, n) {
    if (use[i] != -1) { continue; }
    REP(j, n) {
      if (use[j] != 1) { continue; }
      if (Ban(i, j) || Ban(j, i)) { goto next; }
    }
    m++;
    AddEdge(g, e, SOURCE(), IN(i), 1);
    AddEdge(g, e, OUT(i), DEST(), 1);
    REP(j, n) {
      if (i == j) { continue; }
      if (use[j] != -1) { continue; }
      if (Ban(i, j)) { AddEdge(g, e, IN(i), OUT(j), 1); }
    }
next:;
  }
  return m - MaxFlow(g, e, SOURCE(), DEST());
}

int main() {
  while (scanf("%d", &n) > 0) {
    MEMSET(use, -1);
    REP(i, n) { scanf("%d", &seq[i]); }
    int maxAns = Solve();
    vector<int> ans;
    REP(i, n) {
      REP(j, i) {
        if (use[j] != 1) { continue; }
        if (Ban(i, j) || Ban(j, i)) {
          use[i] = 0;
          goto next;
        }
      }
      use[i] = 1;
      if (Solve() + 1 + (int)ans.size() == maxAns) {
        ans.push_back(i);
      } else {
        use[i] = 0;
      }
next:;
    }
    assert(maxAns == (int)ans.size());
    REP(i, maxAns) {
      if (i != 0) { putchar(' '); }
      printf("%d", ans[i] + 1);
    }
    puts("");
  }
}