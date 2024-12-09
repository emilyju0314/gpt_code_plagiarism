#include <bits/stdc++.h>
using namespace std;
int graph[105][105];
int result = INT_MAX;
int flag = 0;
int n;
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
void dfs(int current, int sum, int father) {
  if (current == 1) {
    if (flag) {
      result = min(result, sum);
      return;
    }
    flag++;
  }
  for (int i = 1; i <= n; i++) {
    if (i == father) continue;
    if (graph[current][i])
      dfs(i, sum, current);
    else if (graph[i][current])
      dfs(i, sum + graph[i][current], current);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    graph[a][b] = c;
  }
  dfs(1, 0, -1);
  printf("%d\n", result);
  return 0;
}
