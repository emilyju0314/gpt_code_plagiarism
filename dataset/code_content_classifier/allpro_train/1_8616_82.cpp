#include <bits/stdc++.h>
int N, M, _X, _Y, L, T[262144], ID[262144], HL, ql[50001], qr[50001];
struct point {
  long double x, y;
} p[50001];
struct angle {
  int side;
  long double ik;
} H[100001];
inline bool operator<(const angle &a, const angle &b) {
  return a.side < b.side || (a.side == b.side && a.ik > b.ik);
}
inline bool operator==(const angle &a, const angle &b) {
  return !(a < b) && !(b < a);
}
std::pair<std::pair<angle, angle>, int> q[50001];
void build(int p, int l, int r) {
  T[p] = 0;
  if (l < r) {
    int m = (l + r) >> 1;
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
  }
}
void P(int x, int y) {
  int p = 1, l = 1, r = HL;
  T[p]++;
  while (l < r) {
    int m = (l + r) >> 1;
    if (x <= m)
      p <<= 1, r = m;
    else
      p = p << 1 | 1, l = m + 1;
    T[p]++;
  }
  ID[p] = y;
}
int G(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) return T[p];
  int m = (l + r) >> 1;
  if (R <= m) return G(p << 1, l, m, L, R);
  if (L > m) return G(p << 1 | 1, m + 1, r, L, R);
  return G(p << 1, l, m, L, R) + G(p << 1 | 1, m + 1, r, L, R);
}
long double dis(int u, int v) {
  long double x = (p[u].y - p[v].y) / (p[v].x - p[u].x),
              y = x * p[u].x + p[u].y;
  return sqrt(x * x + y * y);
}
long double list(int p, int l, int r, int L, int R, int start) {
  if (!T[p]) return 0;
  if (l == r) return T[p] ? dis(start, ID[p]) : 0;
  int m = (l + r) >> 1;
  if (R <= m) return list(p << 1, l, m, L, R, start);
  if (L > m) return list(p << 1 | 1, m + 1, r, L, R, start);
  return list(p << 1, l, m, L, R, start) +
         list(p << 1 | 1, m + 1, r, L, R, start);
}
std::pair<int, long double> F(long double R, int tag) {
  L = 0;
  for (int i = 1; i <= N; i++) {
    long double delta = (p[i].x * p[i].x + 1) * R * R - p[i].y * p[i].y;
    if (delta >= 0) {
      delta = sqrt(delta);
      long double x0 = (-p[i].x * p[i].y + delta) / (p[i].x * p[i].x + 1),
                  y0 = x0 * p[i].x + p[i].y;
      long double x1 = (-p[i].x * p[i].y - delta) / (p[i].x * p[i].x + 1),
                  y1 = x1 * p[i].x + p[i].y;
      q[++L] = {{{y0 ? (y0 < 0 ? 3 : 1) : (x0 > 0 ? 2 : 0), y0 ? x0 / y0 : 0},
                 {y1 ? (y1 < 0 ? 3 : 1) : (x1 > 0 ? 2 : 0), y1 ? x1 / y1 : 0}},
                i};
      if (q[L].first.second < q[L].first.first)
        std::swap(q[L].first.first, q[L].first.second);
    }
  }
  for (int i = 1; i <= L; i++) {
    H[i] = q[i].first.first;
    H[L + i] = q[i].first.second;
  }
  std::sort(H + 1, H + L + L + 1);
  HL = std::unique(H + 1, H + L + L + 1) - H;
  build(1, 1, HL);
  std::sort(q + 1, q + L + 1);
  int count = 0;
  for (int i = 1; i <= L; i++) {
    ql[i] = std::lower_bound(H + 1, H + HL + 1, q[i].first.first) - H;
    qr[i] = std::lower_bound(H + 1, H + HL + 1, q[i].first.second) - H;
    count += G(1, 1, HL, ql[i], qr[i]);
    P(qr[i], q[i].second);
  }
  if (count == M || (count < M && tag)) {
    build(1, 1, HL);
    long double SUM = 0;
    for (int i = 1; i <= L; i++) {
      SUM += list(1, 1, HL, ql[i], qr[i], q[i].second);
      P(qr[i], q[i].second);
    }
    return {count, SUM};
  } else
    return {count, 0};
}
int main() {
  scanf("%d%d%d%d", &N, &_X, &_Y, &M);
  for (int i = 1, K, B; i <= N; i++) {
    scanf("%d%d", &K, &B);
    p[i].x = K / 1000.0L;
    p[i].y = (B - _Y) / 1000.0L + (long double)K * _X / 1000000.0L;
  }
  long double l = 0, r = 1e12;
  while (1) {
    long double m = (l + r) / 2;
    std::pair<int, long double> f = F(m, r - l < 1e-6);
    if (f.first == M || (f.first < M && r - l < 1e-6)) {
      printf("%.10Lf\n", f.second + (M - f.first) * l);
      return 0;
    }
    if (m < 1e-13 && f.first > M) {
      puts("0.0000000000");
      return 0;
    }
    (f.first < M ? l : r) = m;
  }
}
