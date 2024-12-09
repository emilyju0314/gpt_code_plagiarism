#include <bits/stdc++.h>
using namespace std;
int n, m, L, lst[3005], col[3005], val[3005], tot, vis[3005];
struct Node {
  int x, y, c, i;
} A[3005];
bool cmpx(Node a, Node b) { return a.x < b.x; }
bool cmpy(Node a, Node b) { return a.y < b.y; }
struct Q {
  int l[3005], r[3005];
  void Delete(int x) {
    l[r[x]] = l[x];
    r[l[x]] = r[x];
  }
} q, w;
struct Data {
  int mn, mx, s, tag;
  Data(int a = 0, int b = 0, int c = 0, int d = 0) {
    mn = a, mx = b, s = c, tag = d;
  }
  Data operator+(Data b) const {
    return Data(min(mn, b.mn), max(mx, b.mx), (s + b.s) % 1000000007, 0);
  }
} S[3005 * 2];
int f[3005];
void Update(int x, int l, int r, long long t) {
  S[x] = Data(t, t, 1LL * (val[r] - val[l - 1]) * t % 1000000007, t);
}
void Build(int x, int l, int r) {
  if (l == r) {
    Update(x, l, r, f[l]);
    return;
  }
  int mid = (l + r) / 2;
  Build((x << 1), l, mid);
  Build((x << 1 | 1), mid + 1, r);
  S[x] = S[(x << 1)] + S[(x << 1 | 1)];
}
void Modify(int x, int l, int r, int L, long long t) {
  if (S[x].mn >= t) return;
  if (S[x].mx <= t && l == L) {
    Update(x, l, r, t);
    return;
  }
  int mid = (l + r) / 2;
  if (S[x].tag) {
    Update((x << 1), l, mid, S[x].tag);
    Update((x << 1 | 1), mid + 1, r, S[x].tag);
    S[x].tag = 0;
  }
  if (L <= mid) Modify((x << 1), l, mid, L, t);
  Modify((x << 1 | 1), mid + 1, r, max(mid + 1, L), t);
  S[x] = S[(x << 1)] + S[(x << 1 | 1)];
}
int main() {
  scanf("%d%d%d", &n, &m, &L);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].c);
  sort(A + 1, A + n + 1, cmpy);
  A[0].x = A[0].y = -1;
  A[n + 1].x = A[n + 1].y = L;
  for (int i = 0; i <= n + 1; i++) val[i] = A[i].y, A[i].i = i;
  for (int i = 1; i <= n; i++) {
    int l = w.l[i] = lst[A[i].c];
    lst[A[i].c] = i;
    w.r[i] = n + 1;
    w.r[l] = i;
  }
  sort(A + 1, A + n + 1, cmpx);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i].x ^ A[i - 1].x) {
      for (int j = 1; j < i; j++) col[A[j].i] = 0;
      for (int j = i; j <= n; j++) col[A[j].i] = A[j].c;
      for (int l = 1, r = 1; l <= n; l++) {
        for (; r <= n && tot < m; r++)
          if (col[r] && !vis[col[r]]++) tot++;
        f[l] = (tot < m) ? L : val[r - 1];
        if (col[l] && !--vis[col[l]]) tot--;
      }
      q = w;
      Build(1, 1, n);
      for (int j = n; j >= i; j--) {
        ans += (1LL * (val[n] + 1) * L - S[1].s) % 1000000007 *
               (A[i].x - A[i - 1].x) % 1000000007 * (A[j + 1].x - A[j].x) %
               1000000007;
        int id = A[j].i, l = q.l[id], r = q.r[id];
        Modify(1, 1, n, l + 1, val[r]);
        q.Delete(id);
      }
      ans %= 1000000007;
    }
    w.Delete(A[i].i);
  }
  printf("%lld\n", ans);
}
