#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &n) {
  n = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c <= '9' && c >= '0') n = (n << 1) + (n << 3) + c - '0', c = getchar();
}
template <typename T>
void write(T n) {
  if (n <= 9) {
    putchar(n + '0');
    return;
  }
  write(n / 10);
  putchar(n % 10 + '0');
}
long long n;
long long g[3005][3005], mn, s;
long long dis[3005];
bool vis[3005];
inline void dijkstra(long long s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  for (long long i = 1; i <= n; i++) {
    dis[i] = g[s][i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i != j) dis[i] = min(dis[i], g[i][j] * 2);
    }
  }
  vis[s] = true;
  for (long long i = 1; i <= n - 1; i++) {
    long long mi = 1e15;
    long long id;
    for (long long j = 1; j <= n; j++) {
      if (mi > dis[j] && !vis[j]) {
        mi = dis[j];
        id = j;
      }
    }
    vis[id] = true;
    for (long long j = 1; j <= n; j++) {
      dis[j] = min(dis[j], dis[id] + g[j][id]);
    }
  }
}
signed main() {
  read(n);
  mn = 1e15;
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      read<long long>(g[i][j]);
      g[j][i] = g[i][j];
      if (g[i][j] < mn) {
        mn = g[i][j];
        s = i;
      }
    }
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      g[i][j] -= mn;
      g[j][i] = g[i][j];
    }
  }
  dijkstra(s);
  long long ans;
  for (long long i = 1; i <= n; i++) {
    ans = dis[i] + (n - 1) * mn;
    write(ans);
    putchar('\n');
  }
  return 0;
}
