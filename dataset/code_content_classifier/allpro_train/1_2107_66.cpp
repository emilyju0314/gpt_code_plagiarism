#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1501;
int n, nxt[N << 1], h[N], vet[N << 1], num[N], f[N], d[N], fa[N], siz[N], en;
struct Point {
  int a, b, c;
  double tan;
} P[N], st;
vector<Point> vec;
double tanj(int x, int y, int x1, int y1) {
  return (double)(y1 - y) / (x1 - x);
}
bool cmp1(Point x, Point y) { return x.a < y.a; }
bool cmp2(Point x, Point y) {
  return (long long)(x.b - st.b) * (y.a - st.a) <
         (long long)(y.b - st.b) * (x.a - st.a);
}
void add(int u, int v) {
  nxt[++en] = h[u];
  h[u] = en;
  vet[en] = v;
}
void dfs(int u) {
  siz[u] = 1;
  for (int e = h[u]; e; e = nxt[e]) {
    int v = vet[e];
    if (!d[v]) {
      d[v] = d[u] + 1;
      fa[v] = u;
      dfs(v);
      siz[u] += siz[v];
    }
  }
}
void solve(int u, vector<Point> vec) {
  num[vec[0].c] = u;
  st = vec[0];
  sort(vec.begin() + 1, vec.end(), cmp2);
  vector<Point> tmp;
  int now = 1;
  for (int e = h[u]; e; e = nxt[e]) {
    int v = vet[e];
    tmp.clear();
    if (v != fa[u]) {
      while (tmp.size() < siz[v]) {
        tmp.push_back(vec[now]);
        now++;
      }
      solve(v, tmp);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; i++) scanf("%d%d", &P[i].a, &P[i].b), P[i].c = i;
  sort(P + 1, P + 1 + n, cmp1);
  d[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) vec.push_back(P[i]);
  solve(1, vec);
  for (int i = 1; i <= n; i++) printf("%d ", num[i]);
}
