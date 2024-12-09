#include <bits/stdc++.h>
int N, tot, Ans;
char s[101];
int d[101], A[101], vis[101];
int first[101], next[10010], end[10010];
void Add(int x, int y) {
  next[++tot] = first[x];
  first[x] = tot;
  end[tot] = y;
}
void Dfs(int x) {
  ++Ans;
  vis[x] = 1;
  for (int k = first[x], v; v = end[k], k; k = next[k]) ++d[v];
  for (int k = first[x], v; v = end[k], k; k = next[k])
    if (d[v] == A[v]) Dfs(v);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%s", s);
    for (int j = 1; j <= N; ++j)
      if (s[j - 1] == '1') Add(i, j);
  }
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= N; ++i)
    if (d[i] == A[i]) Dfs(i);
  printf("%d\n", Ans);
  for (int i = 1; i <= N; ++i)
    if (vis[i]) printf("%d ", i);
}
