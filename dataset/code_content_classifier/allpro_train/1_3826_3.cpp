#include <bits/stdc++.h>
const int N = 3e5 + 7, MOD = 998244353;
const long double eps = 1e-15;
void M(int &a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int sign(long double x) {
  if (x < -eps) return -1;
  return x > eps;
}
int qp(int a, int b = MOD - 2) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return ans % MOD;
}
const int inv = qp(100);
int n, pro[N][2];
bool limit[N][2][2];
namespace seg {
static const int XN = N * 4;
int tree[XN][2][2];
void pushup(int p, int mid) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      tree[p][i][j] = 0;
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++)
          if (!limit[mid][k][l])
            M(tree[p][i][j] +=
              1LL * tree[p << 1][i][k] * tree[p << 1 | 1][l][j] % MOD);
    }
}
void build(int p, int l, int r) {
  if (l == r) {
    tree[p][1][1] = pro[l][1];
    tree[p][0][0] = pro[l][0];
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p, mid);
}
void update(int p, int l, int r, int pos) {
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid)
    update(p << 1, l, mid, pos);
  else
    update(p << 1 | 1, mid + 1, r, pos);
  pushup(p, mid);
}
int query() {
  int ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) M(ans += tree[1][i][j]);
  return ans;
}
}  // namespace seg
struct Node {
  int x, xp, yp;
  long double t;
  int tt;
  Node() {}
  Node(int x, int xp, int yp, long double t, int tt)
      : x(x), xp(xp), yp(yp), t(t), tt(tt) {}
  bool operator<(const Node &p) const { return sign(t - p.t) < 0; }
} P[N];
int main() {
  scanf("%d", &n);
  int cnt = 0;
  int lastx = 0, lastv = 0;
  for (int i = 1; i <= n; i++) {
    int x, v, p;
    scanf("%d%d%d", &x, &v, &p);
    if (i > 1) {
      int dis = x - lastx;
      ++cnt;
      P[cnt] = Node(i - 1, 1, 0, dis / 1.0 / (lastv + v),
                    1LL * dis * qp(lastv + v) % MOD);
      if (v > lastv) {
        ++cnt;
        P[cnt] = Node(i - 1, 0, 0, dis / 1.0 / (v - lastv),
                      1LL * dis * qp(v - lastv) % MOD);
      } else if (lastv > v) {
        ++cnt;
        P[cnt] = Node(i - 1, 1, 1, dis / 1.0 / (lastv - v),
                      1LL * dis * qp(lastv - v) % MOD);
      }
    }
    lastv = v;
    lastx = x;
    pro[i][0] = 1LL * (100 - p) * inv % MOD;
    pro[i][1] = 1LL * p * inv % MOD;
  }
  seg::build(1, 1, n);
  std::sort(P + 1, P + 1 + cnt);
  int ans = 0, lastp = 1;
  for (int i = 1; i <= cnt; i++) {
    Node p = P[i];
    limit[p.x][p.xp][p.yp] = 1;
    seg::update(1, 1, n, p.x);
    int curp = seg::query();
    M(ans += 1LL * p.tt * (lastp - curp + MOD) % MOD);
    lastp = curp;
  }
  printf("%d\n", ans);
  return 0;
}
