#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int color[100005], visited[100005];
int flag = 0;
void dfs(int s, int c) {
  if (visited[s]) {
    if (color[s] != c) {
      flag = 1;
    }
    return;
  }
  visited[s] = 1;
  color[s] = c;
  c = (c + 1) % 2;
  for (int i = 0; i < v[s].size(); i++) {
    dfs(v[s][i], c);
  }
}
int main() {
  int n, m, x, y, count1 = 0, count2 = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) dfs(i, 1);
  }
  if (flag == 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (color[i] == 1)
      count1++;
    else
      count2++;
  }
  printf("%d\n", count1);
  for (int i = 1; i <= n; i++) {
    if (color[i] == 1) printf("%d ", i);
  }
  printf("\n%d\n", count2);
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) printf("%d ", i);
  }
  return 0;
}
