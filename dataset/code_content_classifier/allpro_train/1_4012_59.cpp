#include <bits/stdc++.h>
using namespace std;
bool used[1000005];
int tot = 0, start[1000005], anss, du[1000005], n, m, mul, ans[1000005];
struct node {
  int x, y, next;
} road[1000005 * 2];
void build(int x, int y) {
  tot++, road[tot].x = x, road[tot].y = y, road[tot].next = start[x],
         start[x] = tot;
}
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d%d", &p, &q);
    build(p, q), build(q, p);
    du[p]++, du[q]++;
  }
}
void dfs(int x) {
  if (du[x] & 1) anss++;
  mul += du[x];
  used[x] = true;
  for (int i = start[x]; i; i = road[i].next)
    if (used[road[i].y] == false) dfs(road[i].y);
}
void work() {
  int CC = 0;
  for (int i = 1; i <= n; i++)
    if (used[i] == false) {
      mul = 0, anss = 0;
      dfs(i);
      if (mul != 0 || i == 1) ans[++CC] = anss;
    }
  int summ = 0;
  for (int i = 1; i <= CC; i++)
    if (ans[i] != 0) summ += (ans[i] - 2) / 2;
  summ += CC;
  if (CC == 1 && ans[1] == 0) summ--;
  printf("%d\n", summ);
}
int main() {
  init();
  work();
  return 0;
}
