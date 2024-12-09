#include <bits/stdc++.h>
using namespace std;
int head[200005], v[200005 * 2], w[200005 * 2], nxt[200005 * 2], en;
struct subtree {
  int id, c;
  subtree(int id = 0, int c = 0) : id(id), c(c) {}
  bool operator<(subtree xx) const {
    return c > xx.c || (c == xx.c && id < xx.id);
  }
};
set<subtree> S;
void addedge(int iu, int iv, int iw) {
  en++;
  v[en] = iv;
  w[en] = iw;
  nxt[en] = head[iu];
  head[iu] = en;
}
int cg, min_max, n;
int dfs1(int s, int par) {
  int sz = 1, ma = 0, x;
  for (int i = head[s]; i; i = nxt[i])
    if (v[i] != par) {
      x = dfs1(v[i], s);
      ma = max(x, ma);
      sz += x;
    }
  ma = max(n - sz, ma);
  if (ma < min_max) {
    cg = s;
    min_max = ma;
  }
  return sz;
}
int sz[200005], in[200005], out[200005], tim;
long long ans, d[200005];
void dfs2(int s, int par) {
  in[s] = ++tim;
  sz[s] = 1;
  ans += d[s];
  for (int i = head[s]; i; i = nxt[i])
    if (v[i] != par) {
      d[v[i]] = d[s] + w[i];
      dfs2(v[i], s);
      sz[s] += sz[v[i]];
    }
  out[s] = tim;
}
int c[200005];
void dfs3(int s, int par, int cc) {
  c[s] = cc;
  for (int i = head[s]; i; i = nxt[i])
    if (v[i] != par) dfs3(v[i], s, cc);
}
int it[200005 * 4], qx, qans, qs, qt;
void add(int f, int r, int at) {
  if (f == r) {
    it[at] = qx;
    return;
  }
  int mid = (f + r) >> 1;
  if (qs <= mid)
    add(f, mid, at * 2);
  else
    add(mid + 1, r, at * 2 + 1);
  it[at] = min(it[at * 2], it[at * 2 + 1]);
}
void query(int f, int r, int at) {
  if (qs <= f && r <= qt) {
    qans = min(it[at], qans);
    return;
  }
  int mid = (f + r) >> 1;
  if (qs <= mid) query(f, mid, at * 2);
  if (qt > mid) query(mid + 1, r, at * 2 + 1);
}
int wait[200005], go[200005], L[200005], R[200005];
void decrease(int col) {
  subtree color = subtree(col, go[col] + wait[col]);
  S.erase(color);
  color.c--;
  if (color.c > 0) S.insert(color);
}
int main() {
  int i, j, k;
  int a, b, iw;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d%d", &a, &b, &iw);
    addedge(a, b, iw);
    addedge(b, a, iw);
  }
  min_max = 200000008;
  dfs1(1, 0);
  d[cg] = 0;
  tim = 0;
  dfs2(cg, 0);
  printf("%I64d\n", ans * 2);
  L[1] = R[1] = 1;
  c[cg] = j = 1;
  S.insert(subtree(j, 0));
  for (i = head[cg]; i; i = nxt[i]) {
    dfs3(v[i], cg, ++j);
    L[j] = in[v[i]];
    R[j] = out[v[i]];
    go[j] = wait[j] = sz[v[i]];
    S.insert(subtree(j, go[j] + wait[j]));
  }
  for (i = 1; i <= n; i++) {
    qs = in[i];
    qx = i;
    add(1, n, 1);
  }
  for (i = 1; i <= n; i++) {
    subtree x = *S.begin();
    if (c[i] != x.id && n - i < x.c) {
      qs = L[x.id];
      qt = R[x.id];
      qans = 200000008;
      query(1, n, 1);
      qs = in[qans];
      qx = 200000008;
      add(1, n, 1);
      printf("%d ", qans);
      decrease(x.id);
      decrease(c[i]);
      go[c[i]]--;
      wait[x.id]--;
      continue;
    }
    qans = 200000008;
    if (L[c[i]] > 1) {
      qs = 1;
      qt = L[c[i]] - 1;
      query(1, n, 1);
    }
    if (R[c[i]] < n) {
      qs = R[c[i]] + 1;
      qt = n;
      query(1, n, 1);
    }
    if (L[c[i]] == 1) qans = min(i, qans);
    printf("%d ", qans);
    qs = in[qans];
    qx = 200000008;
    add(1, n, 1);
    decrease(c[qans]);
    decrease(c[i]);
    go[c[i]]--;
    wait[c[qans]]--;
  }
  return 0;
}
