#include <bits/stdc++.h>
using namespace std;
const int N = 7;
const int M = 8;
int mp[8][8], ex[105], ey[105], eCnt;
int have[10], ans, as[8][8], ax[10], A[10][10], line[10][10], al[10][10];
int aCnt[10], aMp[10][10], Mp[10][10];
char *to = "BRWY";
char *name[10] = {"BY", "BW", "BR", "BB", "RY", "RW", "RR", "WY", "WW", "YY"};
int id[4][4] = {{3, 2, 1, 0}, {2, 6, 5, 4}, {1, 5, 8, 7}, {0, 4, 7, 9}};
int ID(char c) {
  if (c == 'B') return 0;
  if (c == 'R') return 1;
  if (c == 'W') return 2;
  return 3;
}
const int MaxN = 25;
const int MaxM = MaxN * MaxN;
const int Inf = 50;
struct Edge {
  int v, cap, nxt;
} e[2 * MaxM];
int g[MaxN], pt;
int pre[MaxN], pree[MaxN], cur[MaxN], gap[MaxN];
int low[MaxN], d[MaxN];
int n, ed, st;
void init() {
  for (int i = 0; i < n; i++) g[i] = -1;
  pt = 0;
}
void add(int u, int v, int cap) {
  e[pt].v = v;
  e[pt].cap = cap;
  e[pt].nxt = g[u];
  g[u] = pt++;
  e[pt].v = u;
  e[pt].cap = 0;
  e[pt].nxt = g[v];
  g[v] = pt++;
}
int sap() {
  int ret = 0;
  bool fail;
  for (int i = 0; i < n; i++) {
    d[i] = gap[i] = 0;
    cur[i] = g[i];
  }
  low[st] = Inf;
  gap[0] = n;
  int u = st;
  while (d[st] < n) {
    fail = true;
    for (int i = cur[u]; i != -1; i = e[i].nxt) {
      int v = e[i].v;
      cur[u] = i;
      if (e[i].cap && d[u] == d[v] + 1) {
        pre[v] = u;
        pree[v] = i;
        low[v] = min(low[u], e[i].cap);
        u = v;
        if (u == ed) {
          for (; u != st; u = pre[u]) {
            e[pree[u]].cap -= low[ed];
            e[pree[u] ^ 1].cap += low[ed];
          }
          ret += low[ed];
        }
        fail = false;
        break;
      }
    }
    if (fail) {
      gap[d[u]]--;
      if (!gap[d[u]]) break;
      d[u] = n;
      for (int i = g[u]; i != -1; i = e[i].nxt)
        if (e[i].cap) d[u] = min(d[u], d[e[i].v] + 1);
      gap[d[u]]++;
      cur[u] = g[u];
      if (u != st) u = pre[u];
    }
  }
  return ret;
}
int mx[15];
void Gao() {
  n = 22;
  st = n - 1;
  ed = n - 2;
  init();
  int ret = 0;
  for (int i = 0; i < 10; i++) mx[i] = min(ax[i], have[i]);
  for (int i = 0; i < eCnt; i++)
    if (ax[ex[i]] - mx[ex[i]] && have[ey[i]] - mx[ey[i]])
      add(ex[i], ey[i] + 10, Inf);
  for (int i = 0; i < 10; i++) {
    int t = min(ax[i], have[i]);
    ret += 2 * t;
    if (ax[i] - t) add(st, i, ax[i] - t);
    if (have[i] - t) add(i + 10, ed, have[i] - t);
  }
  ret += sap();
  if (ans < ret) {
    ans = ret;
    memcpy(al, line, sizeof(line));
    memset(aMp, 0, sizeof(aMp));
    int ct = 0;
    for (int i = 0; i < eCnt; i++)
      if (ax[ex[i]] - mx[ex[i]] && have[ey[i]] - mx[ey[i]]) {
        aMp[ex[i]][ey[i]] = Inf - e[ct * 2].cap;
        ct++;
      }
  }
}
int tot;
void sol(int x, int y) {
  if (x == N) {
    Gao();
    return;
  }
  if (y == M) {
    sol(x + 1, 0);
    return;
  }
  int p = y == 0 ? 0 : (line[x][y - 1] == 1),
      q = x == 0 ? 0 : (line[x - 1][y] == 2);
  if (p + q == 0) {
    if (x + 1 < N) {
      line[x][y] = 2;
      line[x + 1][y] = 0;
      int idx = id[mp[x][y]][mp[x + 1][y]];
      ax[idx]++;
      sol(x, y + 1);
      ax[idx]--;
    }
    if (y + 1 < M) {
      line[x][y] = 1;
      line[x][y + 1] = 3;
      int idx = id[mp[x][y]][mp[x][y + 1]];
      ax[idx]++;
      sol(x, y + 1);
      ax[idx]--;
    }
  } else if (p == 0 || q == 0)
    sol(x, y + 1);
}
char str[20];
int main() {
  for (int i = 0; i < N; i++) {
    scanf("%s", str);
    for (int j = 0; j < M; j++) mp[i][j] = ID(str[j]);
  }
  for (int i = 0; i < 10; i++) scanf("%d", &have[i]);
  eCnt = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (i != j)
        if (name[i][0] == name[j][0] || name[i][0] == name[j][1] ||
            name[i][1] == name[j][0] || name[i][1] == name[j][1]) {
          ex[eCnt] = i, ey[eCnt] = j;
          eCnt++;
        }
  ans = -1;
  tot = 0;
  sol(0, 0);
  printf("%d\n", ans);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (al[i][j] == 1 || al[i][j] == 2) {
        int x = i, y = j;
        if (al[i][j] == 1)
          y++;
        else
          x++;
        int idx = id[mp[i][j]][mp[x][y]];
        if (have[idx]) {
          have[idx]--;
          Mp[i][j] = mp[i][j];
          Mp[x][y] = mp[x][y];
          continue;
        }
        int k = 0;
        for (; k < 10; k++)
          if (aMp[idx][k]) {
            aMp[idx][k]--;
            have[k]--;
            break;
          }
        if (k == 10) {
          Mp[i][j] = Mp[x][y] = -1;
          continue;
        }
        if (to[mp[i][j]] == name[k][0] || to[mp[i][j]] == name[k][1])
          Mp[i][j] = mp[i][j],
          Mp[x][y] = ID(name[k][0]) + ID(name[k][1]) - mp[i][j];
        else
          Mp[x][y] = mp[x][y],
          Mp[i][j] = ID(name[k][0]) + ID(name[k][1]) - mp[x][y];
      }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (Mp[i][j] == -1) {
        int x = i, y = j;
        if (al[i][j] == 1)
          y++;
        else
          x++;
        for (int k = 0; k < 10; k++)
          if (have[k]) {
            have[k]--;
            Mp[i][j] = ID(name[k][0]);
            Mp[x][y] = ID(name[k][1]);
            break;
          }
      }
  for (int i = 0; i < 2 * N - 1; i++) {
    if (i & 1)
      for (int j = 0; j < 2 * M - 1; j++) {
        if (j & 1)
          printf(".");
        else
          printf("%c", al[i / 2][j / 2] == 2 ? '|' : '.');
      }
    else
      for (int j = 0; j < 2 * M - 1; j++) {
        if (j & 1)
          printf("%c", al[i / 2][j / 2] == 1 ? '-' : '.');
        else
          printf("%c", to[Mp[i / 2][j / 2]]);
      }
    puts("");
  }
  return 0;
}
