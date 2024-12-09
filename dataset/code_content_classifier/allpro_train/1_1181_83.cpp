#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, f = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';) f = (ch == '-');
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) x = x * 10 + ch - '0';
  return f ? -x : x;
}
int N, M, D;
int dsu[100005], siz[100005], G[100005];
int st[100005], fa[100005], Dfn[100005], wei[100005];
map<int, int> Col[100005];
struct Lin {
  int v, next;
} E[100005];
void Link(int u, int v) {
  E[++D] = (Lin){v, st[u]};
  st[u] = D;
  E[++D] = (Lin){u, st[v]};
  st[v] = D;
}
int Get(int u) { return dsu[u] == u ? u : dsu[u] = Get(dsu[u]); }
void Merge(int x, int y) {
  int fx = Get(x), fy = Get(y);
  if (fx != fy)
    dsu[fx] = fy, G[fy] |= G[fx];
  else
    G[fx] = 1;
}
void DFS(int u, int f) {
  Dfn[u] = ++*Dfn;
  fa[u] = f;
  for (int i = st[u], v; i; i = E[i].next)
    if ((v = E[i].v) != f) {
      if (!Dfn[v])
        DFS(v, u);
      else if (Dfn[v] < Dfn[u]) {
        int t = Col[u][v];
        for (int x = u; x != v; x = fa[x]) Merge(t, Col[x][fa[x]]), wei[x] = 1;
      }
    }
}
int main(int argc, char* argv[]) {
  N = IN();
  M = IN();
  for (int i = 1, lim = M; i <= lim; i++) {
    int u = IN(), v = IN(), c = IN();
    Link(u, v);
    Col[u][v] = Col[v][u] = c;
    siz[c] = 1;
  }
  int Ans = 0;
  for (int i = 1, lim = M; i <= lim; i++) dsu[i] = i, Ans += siz[i];
  DFS(1, 0);
  for (int i = 2, lim = N; i <= lim; i++)
    if (!wei[i]) G[Get(Col[i][fa[i]])] = 1;
  for (int i = 1, lim = M; i <= lim; i++)
    if (Get(i) == i && siz[i] && !G[i]) Ans--;
  cout << Ans << endl;
  return 0;
}
