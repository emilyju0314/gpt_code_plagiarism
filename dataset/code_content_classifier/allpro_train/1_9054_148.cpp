#include <bits/stdc++.h>
using namespace std;
struct Dinic {
  struct Edge {
    int to, flow, next;
  };
  vector<Edge> edges;
  vector<int> head, act, h;
  int S, D;
  void AddEdge(int from, int to, int f, int rev_f = 0) {
    edges.push_back({to, f, (int)edges.size()});
    swap(edges.back().next, head[from]);
    edges.push_back({from, rev_f, (int)edges.size()});
    swap(edges.back().next, head[to]);
  }
  bool bfs() {
    fill(h.begin(), h.end(), -1);
    h[S] = 0;
    vector<int> q = {S};
    for (int it = 0; it < q.size() && h[D] == -1; it++) {
      int nod = q[it];
      for (int i = head[nod]; i != -1; i = edges[i].next)
        if (edges[i].flow && h[edges[i].to] == -1)
          h[edges[i].to] = 1 + h[nod], q.push_back(edges[i].to);
    }
    return h[D] != -1;
  }
  int dfs(int nod, int flow) {
    if (flow == 0 || nod == D) return flow;
    while (act[nod] != -1) {
      Edge& e = edges[act[nod]];
      int d;
      if (e.flow && h[e.to] == 1 + h[nod] &&
          (d = dfs(e.to, min(flow, e.flow))) != 0) {
        e.flow -= d;
        edges[act[nod] ^ 1].flow += d;
        return d;
      }
      act[nod] = edges[act[nod]].next;
    }
    return 0;
  }
  int GetFlow() {
    int f = 0;
    while (bfs()) {
      act = head;
      int d;
      while ((d = dfs(S, 1e9)) != 0) f += d;
    }
    return f;
  }
  Dinic(int dim = 0, int s = 0, int d = 0)
      : head(dim + 1, -1), h(dim + 1), S(s), D(d) {}
};
struct FlowWithMinRestrictions {
  struct Edge {
    int from, to, flowmin, flowmax, id;
  };
  vector<Edge> edges;
  int S, D, n;
  void AddEdge(int from, int to, int flowmin, int flowmax) {
    edges.push_back({from, to, flowmin, flowmax, 0});
  }
  vector<int> Solve(bool& feasible, int& flow) {
    feasible = 1;
    flow = 0;
    int news = n + 1, newd = n + 2;
    Dinic first_flow(n + 2, news, newd);
    first_flow.AddEdge(D, S, 1e9);
    int s_minime = 0;
    for (auto& i : edges) {
      if (i.flowmax < i.flowmin) {
        feasible = 0;
        return vector<int>();
      }
      s_minime += i.flowmin;
      i.id = first_flow.edges.size();
      first_flow.AddEdge(i.from, i.to, i.flowmax - i.flowmin);
      first_flow.AddEdge(news, i.to, i.flowmin);
      first_flow.AddEdge(i.from, newd, i.flowmin);
    }
    if (first_flow.GetFlow() != s_minime) {
      feasible = 0;
      return vector<int>();
    }
    Dinic curent_flow(n, S, D);
    for (auto& i : edges) {
      int passed = first_flow.edges[i.id ^ 1].flow;
      int nid = curent_flow.edges.size();
      curent_flow.AddEdge(i.from, i.to, first_flow.edges[i.id].flow, passed);
      i.id = nid;
    }
    curent_flow.GetFlow();
    vector<int> ans(edges.size());
    for (int i = 0; i < edges.size(); i++) {
      int cntflow = curent_flow.edges[edges[i].id ^ 1].flow + edges[i].flowmin;
      ans[i] = cntflow;
      if (edges[i].from == S) flow += cntflow;
      if (edges[i].to == S) flow -= cntflow;
    }
    return ans;
  }
  FlowWithMinRestrictions(int n = 0, int s = 0, int d = 0) : n(n), S(s), D(d) {}
};
namespace ProbD {
const int NMAX = 200010;
map<int, int> nrmx, nrmy;
FlowWithMinRestrictions flow;
pair<int, int> shields[NMAX];
int idshield[NMAX];
int n, S, D;
int difmax[NMAX];
int nr_on_poz[NMAX];
int cnt = 0;
void normalize() {
  for (int i = 0; i < n; i++)
    nrmx[shields[i].first] = nrmy[shields[i].second] = 0;
  for (auto& i : nrmx) i.second = cnt++;
  for (auto& i : nrmy) i.second = cnt++;
  S = cnt++;
  D = cnt;
  fill(difmax, difmax + cnt + 1, 1e9);
}
void solve() {
  int r, b;
  int nrc;
  cin >> n >> nrc >> r >> b;
  for (int i = 0; i < n; i++) cin >> shields[i].first >> shields[i].second;
  normalize();
  flow = FlowWithMinRestrictions(cnt, S, D);
  for (int i = 0; i < n; i++) {
    shields[i].first = nrmx[shields[i].first],
    shields[i].second = nrmy[shields[i].second];
    idshield[i] = flow.edges.size();
    nr_on_poz[shields[i].first]++, nr_on_poz[shields[i].second]++;
    flow.AddEdge(shields[i].first, shields[i].second, 0, 1);
  }
  while (nrc--) {
    int t, p, val;
    cin >> t >> p >> val;
    if (t == 1 && nrmx.find(p) != nrmx.end())
      difmax[nrmx[p]] = min(difmax[nrmx[p]], val);
    else if (t == 2 && nrmy.find(p) != nrmy.end())
      difmax[nrmy[p]] = min(difmax[nrmy[p]], val);
  }
  vector<pair<int, pair<int, int>>> verif;
  for (auto i : nrmx) {
    int nr = nr_on_poz[i.second];
    int dmax = difmax[i.second];
    int vmax = (dmax + nr) / 2;
    int vmin = max(0, (nr - dmax + 1) / 2);
    verif.push_back({(int)flow.edges.size(), {vmin, vmax}});
    flow.AddEdge(S, i.second, vmin, vmax);
  }
  for (auto i : nrmy) {
    int nr = nr_on_poz[i.second];
    int dmax = difmax[i.second];
    int vmax = (dmax + nr) / 2;
    int vmin = max(0, (nr - dmax + 1) / 2);
    verif.push_back({(int)flow.edges.size(), {vmin, vmax}});
    flow.AddEdge(i.second, D, vmin, vmax);
  }
  int f;
  bool posibil;
  auto ans = flow.Solve(posibil, f);
  if (!posibil) {
    cout << "-1\n";
    return;
  }
  for (auto i : verif)
    assert(ans[i.first] >= i.second.first && ans[i.first] <= i.second.second);
  cout << 1LL * f * min(r, b) + 1LL * (n - f) * max(r, b) << '\n';
  string s = "rb";
  if (r < b) s = "br";
  for (int i = 0; i < n; i++) cout << s[ans[idshield[i]]];
  cout << '\n';
}
}  // namespace ProbD
int main() {
  ios_base::sync_with_stdio(0);
  ProbD::solve();
  return 0;
  FILE* in = fopen("cuplaj.in", "r");
  int n, m;
  fscanf(in, "%d%d", &n, &m);
  FlowWithMinRestrictions flow(n, 1, n);
  while (m--) {
    int a, b, c, d;
    fscanf(in, "%d%d%d%d", &a, &b, &c, &d);
    flow.AddEdge(a, b, c, d);
  }
  bool feasible;
  int f;
  auto ans = flow.Solve(feasible, f);
  ofstream out("flux.out");
  out << feasible << '\n' << f << '\n';
  for (auto i : ans) out << i << ' ';
  return 0;
}
