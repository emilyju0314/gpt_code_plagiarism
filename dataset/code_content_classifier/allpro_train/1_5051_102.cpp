#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[10];
bool vis[10];
long long ans = 0;
long long pow(int d, int c) {
  long long a = 1;
  while (c--) {
    a *= d;
    a %= 1000000007;
  }
  return a;
}
bool check() {
  for (int i = 1; i < k; i++) {
    int j = arr[i];
    memset(vis, 0, sizeof(vis));
    vis[j] = 1;
    while (j != 0) {
      j = arr[j];
      if (vis[j] && j != 0) return 0;
      vis[j] = 1;
    }
  }
  return 1;
}
void dfs(int sta) {
  if (sta == k) {
    if (check()) ans++;
    return;
  }
  for (int i = 0; i < k; i++) {
    arr[sta] = i;
    dfs(sta + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  dfs(1);
  printf("%I64d\n", (1ll * k * ans * pow(n - k, n - k)) % (1000000007));
  return 0;
}
