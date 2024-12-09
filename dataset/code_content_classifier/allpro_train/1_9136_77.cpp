#include <bits/stdc++.h>
const int MAXN = 400007;
const int MAXM = 0;
const long long LLINF = 9000000000000000000;
const int INF = 2147483647;
const int MOD = 1000000007;
double eps = 0.00000001;
using namespace std;
struct Tree {
  long long w;
  bool lazy;
};
int n, m;
Tree T[MAXN << 2];
int c[MAXN];
int nc[MAXN], bg[MAXN], ed[MAXN];
int cnt = 0;
vector<int> G[MAXN];
void dfs(int now, int fa) {
  cnt++;
  bg[now] = cnt;
  nc[cnt] = c[now];
  for (int i = 0; i < (int)G[now].size(); i++) {
    if (G[now][i] == fa) continue;
    dfs(G[now][i], now);
  }
  ed[now] = cnt;
}
void push_down(int now) {
  if (T[now].lazy) {
    T[now].lazy = 0;
    T[now * 2].lazy = 1;
    T[now * 2 + 1].lazy = 1;
    T[now * 2].w = T[now].w;
    T[now * 2 + 1].w = T[now].w;
  }
}
void push_up(int now) {
  T[now].w = T[now * 2].w | T[now * 2 + 1].w;
  ;
}
void T_set(int now, int l, int r) {
  if (l == r) {
    T[now].w = (long long)1 << (nc[l] - 1);
    return;
  }
  int mid = (l + r) / 2;
  T_set(now * 2, l, mid);
  T_set(now * 2 + 1, mid + 1, r);
  push_up(now);
}
void T_update(int now, int l, int r, int L, int R, int v) {
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    T[now].w = (long long)1 << (v - 1);
    T[now].lazy = 1;
    return;
  }
  int mid = (l + r) / 2;
  push_down(now);
  T_update(now * 2, l, mid, L, R, v);
  T_update(now * 2 + 1, mid + 1, r, L, R, v);
  push_up(now);
}
long long T_query(int now, int l, int r, int L, int R) {
  if (l > R || r < L) return 0;
  if (L <= l && r <= R) {
    return T[now].w;
  }
  int mid = (l + r) / 2;
  push_down(now);
  return T_query(now * 2, l, mid, L, R) |
         T_query(now * 2 + 1, mid + 1, r, L, R);
}
int main() {
  memset(T, 0, sizeof(T));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, -1);
  T_set(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int f, x, v;
    scanf("%d", &f);
    if (f == 1) {
      scanf("%d%d", &x, &v);
      T_update(1, 1, n, bg[x], ed[x], v);
    } else {
      scanf("%d", &x);
      long long tmp = T_query(1, 1, n, bg[x], ed[x]);
      int cnt = 0;
      while (tmp != 0) {
        if (tmp % 2 == 1) cnt++;
        tmp = tmp / 2;
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
