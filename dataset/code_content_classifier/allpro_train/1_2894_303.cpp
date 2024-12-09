#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
const int MAXV = 500;
const int MAXE = 30000;
const int INF = 1000000000;
struct node {
  int v, c;
  node *next, *rev;
} space[MAXE], *adj[MAXV], *cur[MAXV];
int n, m, s, t, E;
int _n, _m, a[MAXN], x[MAXN], y[MAXN];
vector<pair<int, int> > f[MAXN];
vector<int> prime;
map<int, int> mp;
void AddEdge(int v, int u, int c) {
  node *p = &space[++E];
  node *q = &space[++E];
  p->v = u;
  p->c = c;
  p->rev = q;
  p->next = adj[v];
  adj[v] = p;
  q->v = v;
  q->c = 0;
  q->rev = p;
  q->next = adj[u];
  adj[u] = q;
}
int d[MAXV], cnt[MAXV];
int min(int a, int b) { return (a < b) ? a : b; }
int FindPath(int v, int curFlow) {
  if (v == t) return curFlow;
  node *p = cur[v];
  for (; p != NULL; p = p->next) {
    int u = p->v;
    if (p->c > 0 && d[v] == d[u] + 1) {
      cur[v] = p;
      int res = FindPath(u, min(curFlow, p->c));
      if (res > 0) {
        p->c -= res;
        p->rev->c += res;
        return res;
      } else if (d[s] == n)
        return 0;
    }
  }
  int label1 = d[v];
  cnt[label1]--;
  d[v] = n;
  cur[v] = adj[v];
  for (p = adj[v]; p != NULL; p = p->next)
    if (p->c > 0 && d[p->v] < d[v]) d[v] = d[p->v] + 1;
  cnt[d[v]]++;
  if (cnt[label1] == 0 && cnt[label1 + 1] != 0) d[s] = n;
  return 0;
}
int MaxFlow() {
  memset(d, 0, sizeof(d));
  memset(cnt, 0, sizeof(cnt));
  memcpy(cur, adj, sizeof(adj));
  cnt[0] = n;
  int res = 0;
  while (d[s] < n) res += FindPath(s, INF);
  return res;
}
void solvef() {
  prime.clear();
  mp.clear();
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j * j <= a[i]; j++)
      if (a[i] % j == 0) {
        if (mp[j] == 0) {
          mp[j] = j;
          prime.push_back(j);
        }
        int cnt = 0;
        while (a[i] % j == 0) {
          cnt++;
          a[i] /= j;
        }
        f[i].push_back(make_pair(j, cnt));
      }
    if (a[i] != 1) {
      f[i].push_back(make_pair(a[i], 1));
      if (mp[a[i]] == 0) {
        mp[a[i]] = a[i];
        prime.push_back(a[i]);
      }
    }
  }
}
bool show[MAXN];
int solve() {
  int ans = 0, _n = n;
  s = n + 1, t = n + 2;
  n = n + 2;
  for (int i = 0; i < prime.size(); i++) {
    E = 0;
    memset(show, false, sizeof(show));
    memset(adj, NULL, sizeof(adj));
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < f[x[j]].size(); k++)
        if (!show[x[j]] && f[x[j]][k].first == prime[i]) {
          AddEdge(s, x[j], f[x[j]][k].second);
          show[x[j]] = true;
          break;
        }
      for (int k = 0; k < f[y[j]].size(); k++)
        if (!show[y[j]] && f[y[j]][k].first == prime[i]) {
          AddEdge(y[j], t, f[y[j]][k].second);
          show[y[j]] = true;
          break;
        }
      AddEdge(x[j], y[j], INF);
    }
    ans += MaxFlow();
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i].clear();
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    if (x[i] % 2 == 0) swap(x[i], y[i]);
  }
  solvef();
  cout << solve() << endl;
  return 0;
}
