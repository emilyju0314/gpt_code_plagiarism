#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m;
int f[1000010], p[1000010];
long long g[1000010], tim, ti;
struct ww {
  int a;
  inline bool operator<(const ww &A) const { return g[a] > g[A.a]; }
};
priority_queue<ww> q;
void work(int x) {
  int A = x - 1;
  for (; A > 1;) {
    int C = p[f[A]];
    A /= C;
    g[C] += min(g[x], tim);
  }
  g[x] -= min(g[x], tim);
}
inline void tui() {
  int i, k;
  for (i = 1; i <= *p; i++)
    if (g[p[i]]) {
      g[p[i]]--;
      for (k = p[i] - 1; k > 1; k /= p[f[k]]) g[p[f[k]]]++;
    }
}
int main() {
  for (i = 2; i <= 1000010 - 1; i++) {
    if (!f[i]) p[++*p] = i, f[i] = *p;
    for (j = 1; j <= f[i] && i * p[j] < 1000010; j++) f[i * p[j]] = j;
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d", &k), scanf("%I64d", &g[k]);
  scanf("%I64d", &tim);
  for (i = 1; i <= 12 && tim; tim--, i++) tui();
  for (i = *p; i; i--) work(p[i]);
  k = 0;
  for (i = 1; i <= *p; i++)
    if (g[p[i]]) k++;
  printf("%d\n", k);
  for (i = 1; i <= *p; i++)
    if (g[p[i]]) printf("%d %I64d\n", p[i], g[p[i]]);
  return 0;
}
