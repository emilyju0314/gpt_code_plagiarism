#include <bits/stdc++.h>
using namespace std;
struct edge_type {
  int x, y, init, lower, upper;
} edge[20 + 1];
int n, m;
int flow[20 + 1];
int inflow[10 + 1], outflow[10 + 1];
int maxcost, minflow;
bool cmp(const edge_type &x, const edge_type &y) {
  if (x.x != y.x) return x.x < y.x;
  return x.y < y.y;
}
void dfs(int depth) {
  if (depth > m) {
    for (int i = 2; i < n; i++)
      if (inflow[i] != outflow[i]) return;
    int cur_cost, cur_flow;
    cur_cost = 0;
    cur_flow = 0;
    for (int i = 1; i <= m; i++)
      if (edge[i].x == 1) cur_flow += flow[i];
    for (int i = 1; i <= m; i++)
      if (flow[i]) cur_cost += flow[i] * flow[i] + edge[i].init;
    if (cur_flow <= minflow) {
      minflow = cur_flow;
      if (cur_cost > maxcost) maxcost = cur_cost;
    }
    return;
  }
  for (int i = 1; (i < depth) && (edge[i].x != edge[depth].x); i++)
    if (outflow[edge[i].x] != inflow[edge[i].x])
      if ((edge[i].x != 1) && (edge[i].x != n)) return;
  for (int i = edge[depth].lower; i <= edge[depth].upper; i++) {
    flow[depth] = i;
    inflow[edge[depth].y] += i;
    outflow[edge[depth].x] += i;
    if ((inflow[edge[depth].y] <= minflow) &&
        (outflow[edge[depth].x] <= minflow))
      dfs(depth + 1);
    inflow[edge[depth].y] -= i;
    outflow[edge[depth].x] -= i;
  }
}
int main() {
  scanf("%d", &n);
  m = n * (n - 1) / 2;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d%d", &edge[i].x, &edge[i].y, &edge[i].lower, &edge[i].upper,
          &edge[i].init);
  }
  sort(edge + 1, edge + m + 1, cmp);
  maxcost = 0;
  minflow = 2147483647;
  dfs(1);
  if (minflow >= 2147483647)
    printf("-1 -1\n");
  else
    printf("%d %d\n", minflow, maxcost);
  return 0;
}
