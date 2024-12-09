#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
using namespace std;
long long a[maxn], b[maxn];
map<long long, int> mp;
int ansvec[7005];
bool vis[7005];
int main() {
  memset((vis), (0), sizeof(vis));
  int cnt = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    mp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mp[a[i]] >= 2) {
      ansvec[cnt++] = i;
      vis[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    for (int j = 0; j < cnt; j++) {
      if (a[i] < a[ansvec[j]] && ((a[i] & a[ansvec[j]]) == a[i])) {
        ansvec[cnt++] = i;
        vis[i] = 1;
        break;
      }
    }
  }
  for (int i = 0; i < cnt; i++) ans += b[ansvec[i]];
  printf("%lld\n", ans);
  return 0;
}
