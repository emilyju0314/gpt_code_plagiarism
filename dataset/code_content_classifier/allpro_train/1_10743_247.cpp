#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, a[N], b;
bool vis[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int at = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &b);
    if (vis[b])
      printf("0 ");
    else {
      int ans = 0;
      while (at < n && !vis[b]) {
        vis[a[at]] = 1;
        ans++;
        at++;
      }
      printf("%d ", ans);
    }
  }
}
