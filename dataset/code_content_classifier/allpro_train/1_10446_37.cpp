#include <bits/stdc++.h>
using namespace std;
struct division {
  int v, p, t;
  bool operator<(const division& a) const { return v > a.v; }
  division(int v = 0, int p = 0) : v(v), p(p), t(0) {}
};
struct edge {
  int v, c;
  edge(int v = 0, int c = 0) : v(v), c(c) {}
};
const int N = 5000;
priority_queue<division> pq[N];
vector<edge> vec[N];
void dfs(int u, int pre, int tms) {
  for (__typeof(vec[u].begin()) i = vec[u].begin(); i != vec[u].end(); ++i) {
    if (i->v == pre || pq[i->v].size() == 0) continue;
    for (int j = 0; j < i->c && pq[i->v].size(); j++) {
      division d = pq[i->v].top();
      d.t = tms;
      pq[i->v].pop();
      pq[u].push(d);
    }
    dfs(i->v, u, tms);
  }
}
int tms[N];
int main() {
  int n, a, b, c;
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) {
    scanf("%d", &a);
    pq[i].push(division(a, i));
  }
  for (int i = 1; i < int(n); ++i) {
    scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    vec[b].push_back(edge(a, c));
    vec[a].push_back(edge(b, c));
  }
  int now = 1;
  while (pq[0].size() != n) {
    dfs(0, -1, now++);
  }
  while (pq[0].size()) {
    division d = pq[0].top();
    pq[0].pop();
    tms[d.p] = d.t;
  }
  for (int i = 0; i < int(n); ++i)
    printf("%d%c", tms[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
