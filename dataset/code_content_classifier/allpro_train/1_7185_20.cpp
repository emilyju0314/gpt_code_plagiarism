#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct edge {
  int v, w;
};

const int N = 1e5;
vector<edge> g[N];
int low[N], ord[N], k;
long long ws[N];
long long total;
tuple<long long, int, int> ans;

void dfs(int u, int p) {
  low[u] = ord[u] = k++;
  for (edge e : g[u]) {
    if (ord[e.v] == -1) {
      dfs(e.v, u);
      ws[u] += e.w;
      ws[u] += ws[e.v];
      low[u] = min(low[u], low[e.v]);
      if (ord[u] < low[e.v]) {
        long long A = ws[e.v];
        long long B = total - ws[e.v] - e.w;
        ans = min(ans, make_tuple(abs(A - B), u, e.v));
        ans = min(ans, make_tuple(abs(A - B), e.v, u));
      } else {
        ans = min(ans, make_tuple(total - e.w, u, e.v));
        ans = min(ans, make_tuple(total - e.w, e.v, u));
      }
    } else if (e.v != p && ord[u] > ord[e.v]) {
      ws[u] += e.w;
      low[u] = min(low[u], ord[e.v]);
      ans = min(ans, make_tuple(total - e.w, u, e.v));
      ans = min(ans, make_tuple(total - e.w, e.v, u));
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    g[u].push_back((edge){v, w});
    g[v].push_back((edge){u, w});
    total += w;
  }
  memset(ord, -1, sizeof(ord));
  ans = make_tuple(total, 0, 1);
  dfs(0, -1);
  printf("%d %d\n", get<1>(ans) + 1, get<2>(ans) + 1);
}
