#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-8;
inline void II(int &n) {
  char ch = getchar();
  n = 0;
  bool t = 0;
  for (; ch < '0'; ch = getchar())
    if (ch == '-') t = 1;
  for (; ch >= '0'; n = n * 10 + ch - '0', ch = getchar())
    ;
  if (t) n = -n;
}
inline void OO(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) OO(a / 10);
  putchar(a % 10 + '0');
}
inline int sgn(double x) { return (x > EPS) - (x < -EPS); }
struct EE {
  int v, nx;
} E[200005 * 2 + 200005 * 2];
int hd[200005], EN;
void init_edge(int num) {
  EN = 0;
  memset(hd, -1, (num + 2) << 2);
}
void add_edge(int u, int v) {
  E[EN].v = v;
  E[EN].nx = hd[u];
  hd[u] = EN++;
  E[EN].v = u;
  E[EN].nx = hd[v];
  hd[v] = EN++;
}
int ans[200005][3], cnt;
int vis[200005];
bool dfs(int u, int fa) {
  vis[u] = 1;
  vector<int> s;
  for (int k = hd[u]; ~k; k = E[k].nx) {
    int v = E[k].v;
    if (v == fa) continue;
    if (vis[v] == 2) continue;
    if (!vis[v]) {
      if (dfs(v, u)) s.push_back(v);
    } else
      s.push_back(v);
  }
  vis[u] = 2;
  for (int i = 0; i + 1 < s.size(); i += 2) {
    ans[++cnt][0] = s[i];
    ans[cnt][1] = u;
    ans[cnt][2] = s[i + 1];
  }
  if (fa != -1 && (s.size() & 1)) {
    ans[++cnt][0] = s.back();
    ans[cnt][1] = u;
    ans[cnt][2] = fa;
    return 0;
  }
  return 1;
}
int n, m, u, v;
int main() {
  scanf("%d%d", &n, &m);
  init_edge(n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i, -1);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}
