#include <bits/stdc++.h>
using namespace std;
char s[1111111];
int n, ind[1111111], oud[1111111], ans, x, vis[1111111];
void dfs(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  if (ind[v] == 2 || oud[v] == 2) return;
  dfs((v + 1) % n);
  dfs((v + n - 1) % n);
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < (n); ++i) {
    if (s[i] == '0') {
      ind[(i + 1) % n]++;
      oud[i]++;
    } else {
      ind[i]++;
      oud[(i + 1) % n]++;
    }
  }
  ans = 0;
  for (int i = 0; i < (n); ++i) {
    if (vis[i]) continue;
    if (ind[i] == oud[i]) {
      ans++;
      dfs(i);
    }
  }
  x = -1;
  for (int i = 0; i < (n); ++i)
    if (vis[i]) {
      x = i;
      continue;
    }
  if (x == -1) {
    printf("%d\n", n / 2);
  } else {
    int _x = x;
    x = (x + 1) % n;
    while (x != _x) {
      while (x != _x && vis[x]) x = (x + 1) % n;
      if (x == _x) break;
      int cot = 0;
      while (!vis[x]) {
        cot++;
        x = (x + 1) % n;
      }
      ans += (cot + 1) / 2;
    }
    printf("%d\n", ans);
  }
  return 0;
}
