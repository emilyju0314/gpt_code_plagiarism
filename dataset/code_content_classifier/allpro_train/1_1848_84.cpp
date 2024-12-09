#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, x, maxx, ans;
  int prime[9973];
  bool vis[200000];
  int isprime[200000], f[200000], w[200000];
  scanf("%d", &n);
  maxx = -1;
  ans = 0;
  memset(prime, 0, sizeof(prime));
  memset(vis, false, sizeof(vis));
  memset(isprime, 0, sizeof(isprime));
  memset(f, 0, sizeof(f));
  memset(w, 0, sizeof(w));
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    vis[x] = true;
    if (x > maxx) {
      maxx = x;
    }
  }
  int total = 0;
  for (int i = 2; i <= maxx; i++) {
    if (isprime[i] == 0) {
      prime[total++] = i;
      isprime[i] = i;
      for (int j = 1; i * j <= maxx; j++) {
        isprime[i * j] = i;
      }
    }
  }
  for (int i = 1; i <= maxx; i++) {
    if (vis[i]) {
      f[i] = 1;
      for (int j = i; j > 1; j /= isprime[j]) {
        f[i] = max(f[i], w[isprime[j]] + 1);
      }
      for (int j = i; j > 1; j /= isprime[j]) {
        w[isprime[j]] = max(f[i], w[isprime[j]]);
      }
      if (f[i] > ans) {
        ans = f[i];
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
