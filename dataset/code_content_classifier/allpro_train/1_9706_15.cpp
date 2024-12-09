#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 20005;
const int maxm = 90005;
int getnode() {
  static int nodecnt;
  return ++nodecnt;
}
int treeNo[maxn >> 1];
int weaponNo[5005];
int enemyNo[5005];
void addedge(int u, int v, int c);
void build(int o, int l, int r) {
  treeNo[o] = getnode();
  if (o >> 1) {
    addedge(treeNo[o >> 1], treeNo[o], inf);
  }
  if (l == r) {
    enemyNo[l] = treeNo[o];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
}
void query(int o, int l, int r, int ql, int qr, int from) {
  if (ql <= l && r <= qr) {
    addedge(from, treeNo[o], 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) query(o << 1, l, mid, ql, qr, from);
  if (qr > mid) query(o << 1 | 1, mid + 1, r, ql, qr, from);
}
struct Ed {
  int u, v, nx, c;
  Ed() {}
  Ed(int _u, int _v, int _nx, int _c) : u(_u), v(_v), nx(_nx), c(_c) {}
} E[maxm << 1];
int G[maxn], edtot, cur[maxn];
void addedge(int u, int v, int c) {
  E[edtot] = Ed(u, v, G[u], c);
  G[u] = edtot++;
  E[edtot] = Ed(v, u, G[v], 0);
  G[v] = edtot++;
}
int level[maxn];
int s, t;
bool bfs() {
  static int que[maxn];
  int qh(0), qt(0);
  memset(level, 0, sizeof(level));
  level[que[++qt] = s] = 1;
  while (qh != qt) {
    int x = que[++qh];
    for (int i = G[x]; i != -1; i = E[i].nx)
      if (!level[E[i].v] && E[i].c) {
        level[que[++qt] = E[i].v] = level[x] + 1;
      }
  }
  return !!level[t];
}
int dfs(int u, int rm) {
  if (u == t) return rm;
  int rm1 = rm;
  for (int &i = cur[u]; i != -1; i = E[i].nx) {
    if (level[E[i].v] == level[u] + 1 && E[i].c) {
      int flow = dfs(E[i].v, min(rm, E[i].c));
      E[i].c -= flow, E[i ^ 1].c += flow;
      if ((rm -= flow) == 0) break;
    }
  }
  if (rm1 == rm) level[u] = 0;
  return rm1 - rm;
}
int n;
int find(int x) {
  if (x >= 1 && x <= n) return x;
  for (int i = G[x]; i != -1; i = E[i].nx)
    if ((i & 1) && E[i].c) {
      E[i].c--;
      return find(E[i].v);
    }
}
int kind[5005];
int belong[5005];
vector<int> possess[5005];
vector<int> need[5005];
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) weaponNo[i] = getnode();
  memset(G, -1, sizeof(G));
  build(1, 1, m);
  s = getnode();
  t = getnode();
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 0) {
      int cnt;
      scanf("%d", &cnt);
      while (cnt--) {
        int x;
        scanf("%d", &x);
        addedge(weaponNo[i], enemyNo[x], 1);
      }
    } else if (op == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      query(1, 1, m, l, r, weaponNo[i]);
    } else {
      for (int j = 1; j <= 3; j++) {
        int x;
        scanf("%d", &x);
        addedge(weaponNo[i], enemyNo[x], 1);
        need[i].push_back(x);
      }
    }
    kind[i] = op;
  }
  for (int i = 1; i <= n; i++) {
    if (kind[i] != 2)
      addedge(s, weaponNo[i], 1);
    else
      addedge(s, weaponNo[i], 2);
  }
  for (int i = 1; i <= m; i++) addedge(enemyNo[i], t, 1);
  int ans = 0;
  while (bfs()) memcpy(cur, G, sizeof(G)), ans += dfs(s, inf);
  for (int i = 1; i <= m; i++) {
    belong[i] = find(enemyNo[i]);
    possess[belong[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (kind[i] == 2 && possess[i].size() == 1) {
      for (int x : need[i]) {
        if (belong[x] != i) {
          possess[belong[x]].clear();
          belong[x] = i;
          possess[i].push_back(x);
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int x : possess[i]) {
      printf("%d %d\n", i, x);
    }
  }
  return 0;
}
