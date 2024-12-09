#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
} b[15][39393];
struct nodee {
  int ans, b[39393];
} t[39];
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return w ? -x : x;
}
char s[393939];
int n, k, a[39393], ans[39];
inline bool cmp(node a, node b) {
  if (abs(a.a) != abs(b.a)) return abs(a.a) < abs(b.a);
  if (a.a != b.a) return a.a < b.a;
  if (a.a < 0)
    return a.b < b.b;
  else
    return a.b > b.b;
}
inline bool cmp1(nodee a, nodee b) {
  if (a.ans != b.ans) return a.ans < b.ans;
  for (int i = 1; i <= n; ++i)
    if (a.b[i] != b.b[i]) return a.b[i] < b.b[i];
}
int main() {
  n = read(), k = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) a[i] = s[i] - 48;
  for (int p = 0; p < 10; ++p) {
    for (int i = 1; i <= n; ++i) b[p][i].a = p - a[i], b[p][i].b = i;
    sort(b[p] + 1, b[p] + 1 + n, cmp);
    for (int i = 1; i <= k; ++i) ans[p] += abs(b[p][i].a);
    t[p].ans = ans[p];
  }
  for (int p = 0; p < 10; ++p)
    for (int i = 1; i <= n; ++i) t[p].b[i] = a[i];
  for (int p = 0; p < 10; ++p)
    for (int i = 1; i <= k; ++i) t[p].b[b[p][i].b] = p;
  sort(t, t + 10, cmp1);
  printf("%d\n", t[0].ans);
  for (int i = 1; i <= n; ++i) printf("%d", t[0].b[i]);
}
