#include <bits/stdc++.h>
using namespace std;
inline void R(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
void Redirect() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
struct Blo {
  double sum, mul, add;
} blo[500];
int blon;
int blol;
double a[(int)2e5 + 20];
int n, m;
inline int getIdx(int x) { return ((x - 1) / blol) + 1; }
inline int getL(int x) { return (x - 1) * blol + 1; }
inline int getR(int x) { return x * blol > n ? n : x * blol; }
inline bool Ori(int idx) {
  return fabs(blo[idx].mul - 1) < 1e-8 && fabs(blo[idx].add) < 1e-8;
}
inline void pushdown(int x) {
  if (Ori(x)) return;
  int l = getL(x), r = getR(x);
  blo[x].sum = 0;
  for (int i = l; i <= r; i += 1) {
    a[i] = a[i] * blo[x].mul + blo[x].add;
    blo[x].sum += a[i];
  }
  blo[x].mul = 1;
  blo[x].add = 0;
}
inline double Query(int l, int r) {
  int lb = getIdx(l), rb = getIdx(r);
  double ret = 0;
  if (lb == rb) {
    if (l == getL(lb) && r == getR(lb))
      if (Ori(lb))
        return blo[lb].sum;
      else
        return blo[lb].sum * blo[lb].mul + (r + 1 - l) * blo[lb].add;
    pushdown(lb);
    for (int i = l; i <= r; i += 1) ret += a[i];
    return ret;
  }
  for (int i = lb + 1; i <= rb - 1; i += 1) {
    if (Ori(i))
      ret += blo[i].sum;
    else
      ret += blo[i].sum * blo[i].mul + (getR(i) + 1 - getL(i)) * blo[i].add;
  }
  return Query(l, getR(lb)) + ret + Query(getL(rb), r);
}
void Update(int idx, double mul, double add) {
  blo[idx].add = blo[idx].add * mul + add;
  blo[idx].mul *= mul;
}
void Build(int idx) {
  int l = getL(idx), r = getR(idx);
  blo[idx].sum = 0;
  for (int i = l; i <= r; i += 1) blo[idx].sum += a[i];
  blo[idx].mul = 1;
  blo[idx].add = 0;
}
void ModBlo(int l, int r, double mul, double add) {
  int lb = getIdx(l), rb = getIdx(r);
  if (lb == rb) {
    if (l == getL(lb) && r == getR(lb)) {
      Update(lb, mul, add);
      return;
    }
    pushdown(lb);
    for (int i = l; i <= r; i += 1) {
      a[i] = a[i] * mul + add;
    }
    Build(lb);
    return;
  }
  ModBlo(l, getR(lb), mul, add);
  ModBlo(getL(rb), r, mul, add);
  for (int i = lb + 1; i <= rb - 1; i += 1) Update(i, mul, add);
}
void Modify(int l1, int r1, int l2, int r2) {
  int len1 = (r1 - l1) + 1;
  int len2 = (r2 - l2) + 1;
  double s1 = Query(l1, r1);
  double s2 = Query(l2, r2);
  ModBlo(l1, r1, 1.0 * (len1 - 1) / len1, s2 / len2 / len1);
  ModBlo(l2, r2, 1.0 * (len2 - 1) / len2, s1 / len1 / len2);
}
void Build() {
  blol = sqrt(n);
  cerr << blol << endl;
  blon = (n + (blol - 1)) / blol;
  for (int i = 1; i <= n; i += 1) {
    blo[getIdx(i)].sum += a[i];
    blo[getIdx(i)].mul = 1;
    blo[getIdx(i)].add = 0;
  }
}
int main() {
  R(n);
  R(m);
  for (int i = 1; i <= n; i += 1) {
    int t;
    R(t);
    a[i] = t;
  }
  Build();
  while (m--) {
    int cmd;
    R(cmd);
    if (cmd == 1) {
      int l1, l2, r1, r2;
      R(l1);
      R(r1);
      R(l2);
      R(r2);
      Modify(l1, r1, l2, r2);
    } else {
      int l, r;
      R(l);
      R(r);
      printf("%.8f\n", Query(l, r));
    }
  }
}
