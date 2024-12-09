#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 4e5 + 5;
char s[MAXN], t[MAXN];
int N;
struct SAM {
  int ch[MAXN][26], fa[MAXN], dep[MAXN];
  int tot, lst, root;
  inline int NewNode(int d) {
    dep[tot] = d;
    memset(ch[tot], fa[tot] = 0, sizeof(ch[tot]));
    return tot++;
  }
  inline void Init() {
    tot = 0;
    lst = root = NewNode(0);
  }
  inline void Extend(int c, int op) {
    int p = lst, np = NewNode(dep[p] + 1);
    sz[np] = op;
    while (!ch[p][c]) {
      ch[p][c] = np;
      p = fa[p];
    }
    if (p == root && ch[p][c] == np)
      fa[np] = root;
    else {
      int q = ch[p][c];
      if (dep[q] == dep[p] + 1)
        fa[np] = q;
      else {
        int nq = NewNode(dep[p] + 1);
        fa[nq] = fa[q];
        fa[q] = fa[np] = nq;
        memcpy(ch[nq], ch[q], sizeof(ch[nq]));
        while (ch[p][c] == q) {
          ch[p][c] = nq;
          p = fa[p];
        }
      }
    }
    lst = np;
  }
  int to[MAXN << 1], nxt[MAXN << 1], head[MAXN];
  int cnte;
  int sz[MAXN];
  long long ans;
  inline void addedge(int x, int y) {
    to[++cnte] = y;
    nxt[cnte] = head[x];
    head[x] = cnte;
  }
  inline void dfs(int x) {
    for (int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      dfs(y);
      sz[x] += sz[y];
    }
    ans = max(ans, (long long)dep[x] * sz[x]);
  }
  inline void solve() {
    for (int i = 1; i < tot; i++) addedge(fa[i], i);
    dfs(0);
  }
} sam;
int main() {
  N = read();
  sam.Init();
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 1; i <= N; i++) sam.Extend(s[i] - 'a', (t[i] - '0') ^ 1);
  sam.solve();
  printf("%lld\n", sam.ans);
  return 0;
}
