#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXPOL = 10000;
struct Frac {
  long long num, den;
  Frac() : num(0), den(1) {}
  Frac(long long _num, long long _den) : num(_num), den(_den) {
    if (den < 0) den = -den, num = -num;
    if (den == 0) {
      num = 0;
      return;
    }
    long long g = gcd(abs(num), den);
    num /= g, den /= g;
  }
};
int cmp(const Frac &a, const Frac &b) {
  long long res = a.num * b.den - b.num * a.den;
  return res < 0 ? -1 : res > 0 ? +1 : 0;
}
bool operator<(const Frac &a, const Frac &b) { return cmp(a, b) < 0; }
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
};
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
long long operator^(const P &a, const P &b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
int side(const P &a, const P &b, const P &c) {
  long long res = (b - a) ^ (c - a);
  return res < 0 ? -1 : res > 0 ? +1 : 0;
}
int cmp(const P &a, const P &b) {
  bool apos = a.y > 0 || a.y == 0 && a.x > 0,
       bpos = b.y > 0 || b.y == 0 && b.x > 0;
  if (apos != bpos) return apos ? -1 : +1;
  long long s = a ^ b;
  if (s != 0) return s > 0 ? -1 : +1;
  return 0;
}
bool operator<(const P &a, const P &b) { return cmp(a, b) < 0; }
bool operator==(const P &a, const P &b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const P &a, const P &b) { return a.x != b.x || a.y != b.y; }
Frac dist(const P &a, const P &b, const P &dir) {
  P d = b - a;
  return Frac(d ^ a, d ^ dir);
}
struct FP {
  double x, y;
  FP() {}
  FP(double x, double y) : x(x), y(y) {}
};
FP operator*(const Frac &f, const P &p) {
  return FP(1.0 * f.num / f.den * p.x, 1.0 * f.num / f.den * p.y);
}
FP operator-(const FP &a, const FP &b) { return FP(a.x - b.x, a.y - b.y); }
double operator^(const FP &a, const FP &b) { return a.x * b.y - a.y * b.x; }
double area(const FP &a, const FP &b, const FP &c) {
  return 0.5 * ((b - a) ^ (c - a));
}
P curdir;
struct Seg {
  P a, b;
  int pol, idx;
  Seg() {}
  Seg(P a, P b, int pol, int idx) : a(a), b(b), pol(pol), idx(idx) {}
};
bool operator<(const Seg &u, const Seg &v) {
  Frac tu = dist(u.a, u.b, curdir), tv = dist(v.a, v.b, curdir);
  assert(tu.den != 0 && tv.den != 0);
  int s = cmp(tu, tv);
  if (s != 0) return s < 0;
  assert(u.pol == v.pol);
  if (u.idx == v.idx) return 0;
  if (u.a == v.a && u.b != v.b) {
    P tmpdir = curdir;
    curdir = (u.b ^ v.b) > 0 ? u.b : v.b;
    bool res = u < v;
    curdir = tmpdir;
    return res;
  }
  if (u.b == v.b && u.a != v.a) {
    P tmpdir = curdir;
    curdir = (u.a ^ v.a) > 0 ? v.a : u.a;
    bool res = u < v;
    curdir = tmpdir;
    return res;
  }
  printf(
      "failed to compare (%d,%d)-(%d,%d) [%d:%d] and (%d,%d)-(%d,%d) [%d:%d] "
      "with curdir (%d,%d)\n",
      u.a.x, u.a.y, u.b.x, u.b.y, u.pol, u.idx, v.a.x, v.a.y, v.b.x, v.b.y,
      v.pol, v.idx, curdir.x, curdir.y);
  assert(false);
  return 0;
}
struct E {
  P dir;
  int seg, by;
  E() {}
  E(P dir, int seg, int by) : dir(dir), seg(seg), by(by) {}
};
bool operator<(const E &a, const E &b) {
  int s = cmp(a.dir, b.dir);
  if (s != 0) return s < 0;
  if (a.by != b.by) return a.by < 0;
  return 0;
}
double calcarea(const Seg &u, const Seg &v, const P &ldir, const P &rdir) {
  Frac tlu = dist(u.a, u.b, ldir), tlv = dist(v.a, v.b, ldir),
       trv = dist(v.a, v.b, rdir), tru = dist(u.a, u.b, rdir);
  FP A = tlu * ldir, B = tlv * ldir, C = trv * rdir, D = tru * rdir;
  return area(A, B, C) + area(A, C, D);
}
int npol;
vector<P> pol[MAXPOL];
P orig;
vector<Seg> segs;
vector<E> e;
vector<int> initsegs;
set<Seg> active;
double solve() {
  orig = P(0, 0);
  segs.clear();
  for (int i = (0); i < (npol); ++i)
    for (int j = (0); j < (((int)(pol[i]).size())); ++j) {
      P a = pol[i][j], b = pol[i][(j + 1) % ((int)(pol[i]).size())];
      int s = side(orig, a, b);
      if (s == 0) continue;
      if (s < 0) swap(a, b);
      segs.push_back(Seg(a, b, i, j));
    }
  e.clear(), initsegs.clear();
  P zero(1, 0);
  for (int i = (0); i < (((int)(segs).size())); ++i) {
    P a = segs[i].a, b = segs[i].b;
    if (a < b) {
      e.push_back(E(a, i, +1)), e.push_back(E(b, i, -1));
    } else if (zero < b) {
      e.push_back(E(zero, i, +1)), e.push_back(E(b, i, -1)),
          e.push_back(E(a, i, +1));
    } else {
      e.push_back(E(a, i, +1));
    }
  }
  sort(e.begin(), e.end());
  double ret = 0;
  active.clear();
  for (int i = (0); i < (((int)(e).size())); ++i) {
    curdir = e[i].dir;
    if (e[i].by == +1) {
      active.insert(segs[e[i].seg]);
    } else {
      assert(active.erase(segs[e[i].seg]) == 1);
    }
    if (i + 1 >= ((int)(e).size()) || e[i].dir < e[i + 1].dir) {
      if (((int)(active).size()) != 0) {
        assert(((int)(active).size()) >= 2);
        Seg u = *active.begin(), v = *next(active.begin());
        assert(u.pol == v.pol);
        P nxtdir = i + 1 >= ((int)(e).size()) ? zero : e[i + 1].dir;
        double cur = calcarea(u, v, curdir, nxtdir);
        ret += cur;
      }
    }
  }
  return ret;
}
void run() {
  scanf("%d", &npol);
  for (int i = (0); i < (npol); ++i) {
    int cnt;
    scanf("%d", &cnt);
    pol[i] = vector<P>(cnt);
    for (int j = (0); j < (cnt); ++j) scanf("%d%d", &pol[i][j].x, &pol[i][j].y);
  }
  printf("%.15lf\n", solve());
}
int main() {
  run();
  return 0;
}
