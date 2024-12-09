#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
template <typename T>
void read(T &x) {
  T flag = 1;
  char ch = getchar();
  for (; '0' > ch || ch > '9'; ch = getchar())
    if (ch == '-') flag = 1;
  for (x = 0; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  x *= flag;
}
int n, m;
int pre[MAXN << 1], to[MAXN << 1], head[MAXN], tot;
int f[MAXN];
void add_edge(int u, int v) {
  pre[++tot] = head[u];
  to[tot] = v;
  head[u] = tot;
}
int cntv, cnte;
int col[MAXN], cnt;
int deg[MAXN];
int stk[MAXN];
void dfs(int u) {
  col[u] = cnt;
  cntv++;
  for (int i = head[u]; i; i = pre[i]) {
    int v = to[i];
    cnte++;
    if (col[v]) continue;
    dfs(v);
  }
}
int num;
void dfs2(int u) {
  col[u] = cnt;
  if (deg[u] == 3) num++, stk[num] = u;
  for (int i = head[u]; i; i = pre[i]) {
    int v = to[i];
    if (col[v]) continue;
    dfs2(v);
  }
}
int stkk[MAXN], top;
void find(int u, int t, int fa) {
  stkk[++top] = u;
  if (u == t) {
    for (int i = 1; i <= top; i++) f[stkk[i]] = 2;
    return;
  }
  for (int i = head[u]; i; i = pre[i]) {
    int v = to[i];
    if (v == fa) continue;
    find(v, t, u);
  }
  top--;
}
vector<int> vv[5];
void get_chain(int u, int id, int fa) {
  vv[id].push_back(u);
  for (int i = head[u]; i; i = pre[i]) {
    int v = to[i];
    if (v == fa) continue;
    get_chain(v, id, u);
  }
}
bool cmp(vector<int> a, vector<int> b) { return a.size() < b.size(); }
void Clear() {
  for (int i = 1; i <= 3; i++) vv[i].clear();
  cnte = cntv = cnt = num = top = tot = 0;
  for (int i = 1; i <= n; i++) head[i] = col[i] = deg[i] = f[i] = 0;
}
void solve() {
  read(n);
  read(m);
  for (int i = 1, u, v; i <= m; i++) {
    read(u);
    read(v);
    add_edge(u, v);
    add_edge(v, u);
    deg[u]++;
    deg[v]++;
  }
  if (m >= n) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", 1);
    puts("");
    return;
  } else {
    if (m == 0) {
      puts("NO");
      return;
    } else {
      for (int i = 1; i <= n; i++) {
        if (!head[i]) continue;
        if (col[i]) continue;
        cntv = cnte = 0;
        cnt++;
        dfs(i);
        cnte >>= 1;
        if (cnte >= cntv) {
          puts("YES");
          for (int j = 1; j <= n; j++) {
            if (col[j] == cnt)
              putchar('1');
            else
              putchar('0');
            putchar(' ');
          }
          puts("");
          return;
        }
      }
      bool flag = 0;
      for (int i = 1; i <= n; i++) {
        if (deg[i] >= 3) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        puts("NO");
        return;
      }
      for (int i = 1; i <= n; i++) {
        if (deg[i] >= 4) {
          puts("YES");
          f[i] = 2;
          for (int j = head[i]; j; j = pre[j]) {
            f[to[j]] = 1;
          }
          for (int j = 1; j <= n; j++) {
            printf("%d ", f[j]);
          }
          puts("");
          return;
        }
      }
      memset(col, 0, sizeof(col));
      cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (!col[i]) {
          cnt++;
          num = 0;
          dfs2(i);
          if (num >= 2) {
            puts("YES");
            for (int j = head[stk[1]]; j; j = pre[j]) f[to[j]] = 1;
            for (int j = head[stk[2]]; j; j = pre[j]) f[to[j]] = 1;
            find(stk[1], stk[2], 0);
            for (int j = 1; j <= n; j++) cout << f[j] << " ";
            puts("");
            return;
          }
        }
      }
      memset(col, 0, sizeof(col));
      cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (!col[i]) {
          cnt++;
          num = 0;
          dfs2(i);
          if (num >= 1) {
            int xwinp = 0;
            for (int j = head[stk[1]]; j; j = pre[j]) {
              get_chain(to[j], ++xwinp, stk[1]);
            }
            sort(vv + 1, vv + 4, cmp);
            if (vv[1].size() >= 2) {
              f[stk[1]] = 3;
              f[vv[1][0]] = 2;
              f[vv[1][1]] = 1;
              f[vv[2][0]] = 2;
              f[vv[2][1]] = 1;
              f[vv[3][0]] = 2;
              f[vv[3][1]] = 1;
              puts("YES");
              for (int j = 1; j <= n; j++) printf("%d ", f[j]);
              puts("");
              return;
            } else if (vv[2].size() >= 3) {
              f[stk[1]] = 4;
              f[vv[1][0]] = 2;
              f[vv[2][0]] = 3;
              f[vv[2][1]] = 2;
              f[vv[2][2]] = 1;
              f[vv[3][0]] = 3;
              f[vv[3][1]] = 2;
              f[vv[3][2]] = 1;
              puts("YES");
              for (int j = 1; j <= n; j++) printf("%d ", f[j]);
              puts("");
              return;
            } else if (vv[2].size() >= 2 && vv[3].size() >= 5) {
              f[stk[1]] = 6;
              f[vv[1][0]] = 3;
              f[vv[2][0]] = 4;
              f[vv[2][1]] = 2;
              f[vv[3][0]] = 5;
              f[vv[3][1]] = 4;
              f[vv[3][2]] = 3;
              f[vv[3][3]] = 2;
              f[vv[3][4]] = 1;
              puts("YES");
              for (int j = 1; j <= n; j++) printf("%d ", f[j]);
              puts("");
              return;
            }
            for (int g = 1; g <= 3; g++) vv[g].clear();
          }
        }
      }
    }
  }
  puts("NO");
}
int main() {
  int T;
  read(T);
  while (T--) solve(), Clear();
  return 0;
}
