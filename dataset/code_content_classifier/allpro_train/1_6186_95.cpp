#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e5 + 10, INF = (int)1e9 + 10;
struct set_tree {
  int l, r, ms, s;
} t[MAXN * 2 * 4];
struct Graph {
  int id, next;
} g[MAXN * 2];
vector<int> L;
int n, k, st[MAXN], fa[MAXN], h[MAXN], s[MAXN], w[MAXN];
void Add(int tot, int first, int second) {
  g[tot].id = second, g[tot].next = st[first], st[first] = tot;
}
void DFS(int first, int f) {
  fa[first] = f;
  for (int i = st[first]; i != -1; i = g[i].next)
    if (g[i].id != f) {
      w[g[i].id] = min(h[first], w[first]);
      DFS(g[i].id, first);
    }
}
void Build(int first, int l, int r) {
  t[first].l = l, t[first].r = r;
  t[first].ms = t[first].s = 0;
  if (l == r) return;
  Build((first << 1), l, ((t[first].l + t[first].r) >> 1)),
      Build(((first << 1) | 1), ((t[first].l + t[first].r) >> 1) + 1, r);
}
void Ins(int first, int p, int d) {
  if (t[first].l == p && t[first].r == p) {
    t[first].s += d, t[first].ms += d;
    return;
  }
  if (p <= ((t[first].l + t[first].r) >> 1))
    Ins((first << 1), p, d);
  else
    Ins(((first << 1) | 1), p, d);
  t[first].s = t[(first << 1)].s + t[((first << 1) | 1)].s;
  t[first].ms =
      min(t[(first << 1)].ms, t[(first << 1)].s + t[((first << 1) | 1)].ms);
}
int Query(int first, int s) {
  if (t[first].l == t[first].r) return t[first].l;
  if (t[(first << 1)].ms + s < 0) return Query((first << 1), s);
  return Query(((first << 1) | 1), t[(first << 1)].s + s);
}
int top, a[MAXN], b[MAXN];
void Vis(int first) {
  a[++top] = first;
  for (int i = st[first]; i != -1; i = g[i].next)
    if (g[i].id != fa[first]) {
      if (w[g[i].id] < h[g[i].id]) Vis(g[i].id);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i]), L.push_back(h[i]);
  memset(st, -1, sizeof(st));
  for (int i = 1; i < n; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    Add(i * 2, first, second), Add(i * 2 + 1, second, first);
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) scanf("%d", &s[i]), L.push_back(s[i]);
  sort((L).begin(), (L).end());
  L.erase(unique((L).begin(), (L).end()), L.end());
  for (int i = 1; i <= n; ++i)
    h[i] = lower_bound((L).begin(), (L).end(), h[i]) - L.begin() + 1;
  for (int i = 1; i <= k; ++i)
    s[i] = lower_bound((L).begin(), (L).end(), s[i]) - L.begin() + 1;
  w[1] = INF;
  DFS(1, 0);
  Build(1, 1, ((int)(L).size()));
  for (int i = 1; i <= n; ++i)
    Ins(1, ((int)(L).size()) - min(w[i], h[i]) + 1, 1);
  for (int i = 1; i <= k; ++i) Ins(1, ((int)(L).size()) - s[i] + 1, -1);
  if (t[1].ms >= 0) puts("0"), exit(0);
  int Tohka = INF;
  for (int i = 1; i <= n; ++i)
    if (h[i] < w[i]) {
      top = 0;
      Vis(i);
      Ins(1, ((int)(L).size()) - h[i] + 1, -top);
      int cur = ((int)(L).size()) - Query(1, 0) + 1;
      if (cur <= w[i]) {
        b[i] = cur;
        Ins(1, ((int)(L).size()) - cur + 1, 1);
        for (int j = 2; j <= top; ++j)
          b[a[j]] = min(h[a[j]], b[fa[a[j]]]),
          Ins(1, ((int)(L).size()) - b[a[j]] + 1, 1);
        if (t[1].ms >= 0) Tohka = min(Tohka, L[cur - 1] - L[h[i] - 1]);
        for (int j = 1; j <= top; ++j)
          Ins(1, ((int)(L).size()) - b[a[j]] + 1, -1);
      }
      Ins(1, ((int)(L).size()) - h[i] + 1, top);
    }
  if (Tohka == INF)
    puts("-1");
  else
    cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
