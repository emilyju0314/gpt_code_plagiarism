#include <bits/stdc++.h>
using namespace std;
bool vis[1000005];
int v[1000005];
int main() {
  int n, i, at, cnt, ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= n; i++) {
    if (vis[i]) continue;
    at = i, cnt = 0;
    while (!vis[at]) {
      cnt++;
      vis[at] = 1;
      at = v[at];
    }
    ans += (cnt - 1);
  }
  if ((ans & 1) == (n & 1))
    printf("Petr\n");
  else
    printf("Um_nik\n");
}
