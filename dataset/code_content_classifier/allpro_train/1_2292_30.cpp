#include <bits/stdc++.h>
using namespace std;
int vis[11];
int a[1100000], cnt;
int N;
void out() {
  int i, j;
  for (i = 1; i <= N; i++)
    if (vis[i] == i) {
      if (i - 1) printf(",");
      printf("{");
      int num = 0;
      for (j = i; j <= N; j++)
        if (vis[j] == i) num++;
      for (j = i; j <= N; j++)
        if (vis[j] == i) {
          printf("%d", j);
          --num;
          if (num) printf(",");
        }
      printf("}");
    }
  puts("");
}
int wori, num;
void dfs(int n, int now) {
  if (n > N) {
    if (wori)
      out();
    else
      num++;
    return;
  }
  int t = vis[n];
  dfs(n + 1, now);
  if (t == n) {
    int M = 0;
    for (int i = n + 1; i <= N; i++)
      if (vis[i] == t) {
        M = i;
        break;
      }
    if (M) {
      for (int i = n + 1; i <= N; i++)
        if (vis[i] == t) vis[i] = M;
    }
  }
  for (int i = 1; i <= n; i++)
    if (i - t && (vis[i] == i || i == n)) {
      vis[n] = i;
      dfs(n + 1, now);
    }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) vis[i] = 1;
  dfs(1, 0);
  wori = 1;
  for (int i = 1; i <= N; i++) vis[i] = 1;
  printf("%d\n", num);
  dfs(1, 0);
}
