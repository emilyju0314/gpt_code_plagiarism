#include <bits/stdc++.h>
using namespace std;
int son[500], Ecnt, n;
struct Edge {
  int link, next;
} ed[10004];
pair<int, int> PP[102];
int P[500];
int C[500];
inline void Add(int u, int v) {
  ed[++Ecnt].link = v, ed[Ecnt].next = son[u];
  son[u] = Ecnt;
}
void Dfs1(int x, int c) {
  P[x] = c;
  for (int i = son[x]; i; i = ed[i].next)
    if (!P[ed[i].link]) Dfs1(ed[i].link, c);
}
void Dfs(int x, int c) {
  C[x] = c;
  C[x + 100] = c;
  P[x] = true;
  P[x + 100] = true;
  for (int i = son[x]; i; i = ed[i].next)
    if (!P[ed[i].link]) Dfs(ed[i].link, 1 ^ c);
}
int main() {
  scanf("%d%d", &n, &n);
  for (int i = 1, l, r; i <= n; i++) {
    scanf("%d%d", &l, &r);
    PP[i] = pair<int, int>(min(l, r), max(l, r));
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (PP[i].second == PP[j].second || PP[i].first == PP[j].first) continue;
      int v = 0;
      for (int k = PP[i].first + 1; k < PP[i].second; k++)
        if (PP[j].second == k || PP[j].first == k) v++;
      if (v & 1)
        Add(i, j + 100), Add(j + 100, i), Add(i + 100, j), Add(j, i + 100);
    }
  for (int i = 1; i <= n; i++)
    if (!P[i]) Dfs1(i, i);
  for (int i = 1; i <= n; i++)
    if (P[i] == P[i + 100]) {
      puts("Impossible");
      return 0;
    }
  memset(P, 0, sizeof P);
  for (int i = 1; i <= n; i++)
    if (!P[i] && !P[100 + i]) Dfs(i, 1);
  for (int i = 1; i <= n; i++)
    if (C[i])
      putchar('i');
    else
      putchar('o');
  getchar();
  getchar();
  return 0;
}
