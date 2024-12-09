#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int M = 4e4 + 100;
const int mod = 1e9 + 9;
int head[N], Next[M], tot, ver[M], edge[M];
void add(int x, int y, int v) {
  ver[++tot] = y;
  edge[tot] = v;
  Next[tot] = head[x];
  head[x] = tot;
}
int dpb[N], dpf[N];
void sol1(int x, int pre, int flag) {
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (y == pre || y == flag) continue;
    sol1(y, x, flag);
    dpb[x] += dpb[y] + (1 - edge[i]);
  }
}
int tmp;
void sol2(int x, int pre, int flag) {
  if (pre == -1)
    dpf[x] = 0;
  else {
    dpf[x] += dpf[ver[pre ^ 1]] + dpb[ver[pre ^ 1]] +
              (edge[pre] == 0 ? -1 : 1) - dpb[x];
  }
  tmp = min(tmp, dpf[x] + dpb[x]);
  for (int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (i == (pre ^ 1) || y == flag) continue;
    sol2(y, i, flag);
  }
}
int main() {
  int n, x, y, mini, ans;
  while (cin >> n) {
    tot = 1;
    ans = mini = 0x3f3f3f3f;
    memset(head, 0, sizeof(head));
    memset(ver, 0, sizeof(ver));
    memset(Next, 0, sizeof(Next));
    memset(edge, 0, sizeof(edge));
    for (int i = 1; i <= n - 1; i++) {
      cin >> x >> y;
      add(x, y, 1);
      add(y, x, 0);
    }
    for (int i = 2; i <= tot; i += 2) {
      y = ver[i];
      x = ver[i ^ 1];
      memset(dpf, 0, sizeof(dpf));
      memset(dpb, 0, sizeof(dpb));
      sol1(x, -1, y);
      sol1(y, -1, x);
      tmp = 0x3f3f3f3f;
      sol2(x, -1, y);
      mini = tmp;
      tmp = 0x3f3f3f3f;
      sol2(y, -1, x);
      mini += tmp;
      ans = min(ans, mini);
    }
    if (ans >= 0x3f3f3f3f) ans = 0;
    cout << ans << endl;
  }
  return 0;
}
